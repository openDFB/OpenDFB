/*
   (c) Copyright 2001-2009  The world wide DirectFB Open Source Community (directfb.org)
   (c) Copyright 2000-2004  Convergence (integrated media) GmbH

   All rights reserved.

   Written by Denis Oliver Kropp <dok@directfb.org>,
              Andreas Hundt <andi@fischlustig.de>,
              Sven Neumann <neo@directfb.org>,
              Ville Syrjälä <syrjala@sci.fi> and
              Claudio Ciccani <klan@users.sf.net>.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the
   Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <direct/conf.h>
#include <direct/direct.h>
#include <direct/interface.h>
#include <direct/log.h>
#include <direct/mem.h>
#include <direct/messages.h>
#include <direct/util.h>

#include <directfb.h>
#include <directfb_version.h>

#include <misc/conf.h>

#include <unistd.h>
#include <direct/thread.h>

#include <core/core.h>
#include <core/coredefs.h>
#include <core/coretypes.h>

#include <core/input.h>
#include <core/layer_context.h>
#include <core/layer_control.h>
#include <core/layers.h>
#include <core/state.h>
#include <core/gfxcard.h>
#include <core/surface.h>
#include <core/windows.h>
#include <core/windowstack.h>

#include <gfx/convert.h>
#include <display/idirectfbsurface.h>
#include <idirectfb.h>


#ifndef DIRECTFB_VERSION_VENDOR
#define DIRECTFB_VERSION_VENDOR
#endif


static DFBResult CreateRemote( const char *host, int session, IDirectFB **ret_interface );


IDirectFB *idirectfb_singleton = NULL;


/*
 * Version checking
 */
const unsigned int directfb_major_version = DIRECTFB_MAJOR_VERSION;
const unsigned int directfb_minor_version = DIRECTFB_MINOR_VERSION;
const unsigned int directfb_micro_version = DIRECTFB_MICRO_VERSION;
const unsigned int directfb_binary_age    = DIRECTFB_BINARY_AGE;
const unsigned int directfb_interface_age = DIRECTFB_INTERFACE_AGE;

const char *
DirectFBCheckVersion( unsigned int required_major,
                      unsigned int required_minor,
                      unsigned int required_micro )
{
     if (required_major > DIRECTFB_MAJOR_VERSION)
          return "DirectFB version too old (major mismatch)";
     if (required_major < DIRECTFB_MAJOR_VERSION)
          return "DirectFB version too new (major mismatch)";
     if (required_minor > DIRECTFB_MINOR_VERSION)
          return "DirectFB version too old (minor mismatch)";
     if (required_minor < DIRECTFB_MINOR_VERSION)
          return "DirectFB version too new (minor mismatch)";
     if (required_micro < DIRECTFB_MICRO_VERSION - DIRECTFB_BINARY_AGE)
          return "DirectFB version too new (micro mismatch)";
     if (required_micro > DIRECTFB_MICRO_VERSION)
          return "DirectFB version too old (micro mismatch)";

     return NULL;
}

const char *
DirectFBUsageString( void )
{
     return dfb_config_usage();
}

DFBResult
DirectFBInit( int *argc, char *(*argv[]) )
{
     DFBResult ret;

     ret = dfb_config_init( argc, argv );
     if (ret)
          return ret;

     return DFB_OK;
}

DFBResult
DirectFBSetOption( const char *name, const char *value )
{
     DFBResult ret;

     if (dfb_config == NULL) {
          D_ERROR( "DirectFBSetOption: DirectFBInit has to be "
                   "called before DirectFBSetOption!\n" );
          return DFB_INIT;
     }

     if (!name)
          return DFB_INVARG;

     ret = dfb_config_set( name, value );
     if (ret)
          return ret;

     return DFB_OK;
}

/*
 * Programs have to call this to get the super interface
 * which is needed to access other functions
 */
DFBResult
DirectFBCreate( IDirectFB **interface_ptr )
{
     DFBResult  ret;
     IDirectFB *dfb;
     CoreDFB   *core_dfb;

     if (!dfb_config) {
          /*  don't use D_ERROR() here, it uses dfb_config  */
          direct_log_printf( NULL, "(!) DirectFBCreate: DirectFBInit "
                             "has to be called before DirectFBCreate!\n" );
          return DFB_INIT;
     }

     if (!interface_ptr)
          return DFB_INVARG;


     if (!dfb_config->no_singleton && idirectfb_singleton) {
          idirectfb_singleton->AddRef( idirectfb_singleton );

          *interface_ptr = idirectfb_singleton;

          return DFB_OK;
     }

     direct_initialize();

     if ( !(direct_config->quiet & DMT_BANNER) && dfb_config->banner) {
          direct_log_printf( NULL,
                             "\n"
                             "   ~~~~~~~~~~~~~~~~~~~~~~~~~~| OpenDFB " DIRECTFB_VERSION DIRECTFB_VERSION_VENDOR " |~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                             "        Powered by OpenDFB!!!\n"
                             "      ----------------------------------------------------------------\n"
                             "\n" );
     }

     if (dfb_config->remote.host)
          return CreateRemote( dfb_config->remote.host, dfb_config->remote.port, interface_ptr );

     static DirectMutex lock = DIRECT_MUTEX_INITIALIZER(lock);

     direct_mutex_lock( &lock );

     if (!dfb_config->no_singleton && idirectfb_singleton) {
          idirectfb_singleton->AddRef( idirectfb_singleton );

          *interface_ptr = idirectfb_singleton;

          direct_mutex_unlock( &lock );
          return DFB_OK;
     }

     ret = dfb_core_create( &core_dfb );
     if (ret) {
          direct_mutex_unlock( &lock );
          return ret;
     }

     DIRECT_ALLOCATE_INTERFACE( dfb, IDirectFB );

     ret = IDirectFB_Construct( dfb, core_dfb );
     if (ret) {
          dfb_core_destroy( core_dfb, false );
          direct_mutex_unlock( &lock );
          return ret;
     }

     if (!dfb_config->no_singleton)
          idirectfb_singleton = dfb;

     direct_mutex_unlock( &lock );

     ret = IDirectFB_WaitInitialised( dfb );
     if (ret) {
          if (!dfb_config->no_singleton)
               idirectfb_singleton = NULL;
          dfb->Release( dfb );
          return ret;
     }

     *interface_ptr = dfb;

     return DFB_OK;
}

DFBResult
DirectFBError( const char *msg, DFBResult error )
{
     if (msg)
          direct_log_printf( NULL, "(#) DirectFBError [%s]: %s\n", msg,
                             DirectFBErrorString( error ) );
     else
          direct_log_printf( NULL, "(#) DirectFBError: %s\n",
                             DirectFBErrorString( error ) );

     return error;
}

const char *
DirectFBErrorString( DFBResult error )
{
     return DirectResultString( error );
}

DFBResult
DirectFBErrorFatal( const char *msg, DFBResult error )
{
     DirectFBError( msg, error );

     //if (idirectfb_singleton)
          //IDirectFB_Destruct( idirectfb_singleton );

     exit( error );
}

/**************************************************************************************************/

static DFBResult
CreateRemote( const char *host, int port, IDirectFB **ret_interface )
{
     DFBResult             ret;
     DirectInterfaceFuncs *funcs;
     void                 *interface_ptr;

     D_ASSERT( host != NULL );
     D_ASSERT( ret_interface != NULL );

     ret = DirectGetInterface( &funcs, "IDirectFB", "Requestor", NULL, NULL );
     if (ret)
          return ret;

     ret = funcs->Allocate( &interface_ptr );
     if (ret)
          return ret;

     ret = funcs->Construct( interface_ptr, host, port );
     if (ret)
          return ret;

     *ret_interface = interface_ptr;

     return DFB_OK;
}

