/*
   (c) Copyright 2001-2011  The world wide DirectFB Open Source Community (directfb.org)
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

#include "CoreLayer.h"
#include <directfb_util.h>

#include <direct/debug.h>
#include <direct/mem.h>
#include <direct/memcpy.h>
#include <direct/messages.h>
#include <core/core.h>

D_DEBUG_DOMAIN( DirectFB_CoreLayer, "DirectFB/CoreLayer", "DirectFB CoreLayer" );

/*********************************************************************************************************************/
DFBResult
ILayerReal_CreateContext(ILayer *thiz,
                    CoreLayerContext                         **ret_context
)
{
    D_DEBUG_AT( DirectFB_CoreLayer, "ILayerReal_%s()\n", __FUNCTION__ );

    D_ASSERT( ret_context != NULL );

    return dfb_layer_create_context( thiz->obj, false, ret_context );
}

DFBResult
ILayerReal_GetPrimaryContext(ILayer *thiz,
                    bool                                       activate,
                    CoreLayerContext                         **ret_context
)
{
     D_DEBUG_AT( DirectFB_CoreLayer, "ILayerReal_%s()\n", __FUNCTION__ );

     D_ASSERT( ret_context != NULL );

     return dfb_layer_get_primary_context( thiz->obj, activate, ret_context );
}

DFBResult
ILayerReal_ActivateContext(ILayer *thiz,
                    CoreLayerContext                          *context
)
{
    D_DEBUG_AT( DirectFB_CoreLayer, "ILayerReal_%s()\n", __FUNCTION__ );

    D_ASSERT( context != NULL );

    return dfb_layer_activate_context( thiz->obj, context );
}

DFBResult
ILayerReal_GetCurrentOutputField(ILayer *thiz,
                    s32                                       *ret_field
)
{
     D_DEBUG_AT( DirectFB_CoreLayer, "ILayerReal_%s()\n", __FUNCTION__ );

     D_ASSERT( ret_field != NULL );

     return dfb_layer_get_current_output_field( thiz->obj, ret_field );
}

DFBResult
ILayerReal_SetLevel(ILayer *thiz,
                    s32                                        level
)
{
     D_DEBUG_AT( DirectFB_CoreLayer, "ILayerReal_%s()\n", __FUNCTION__ );

     return dfb_layer_set_level( thiz->obj, level );
}

DFBResult
ILayerReal_WaitVSync(ILayer *thiz
)
{
    D_DEBUG_AT( DirectFB_CoreLayer, "ILayerReal_%s()\n", __FUNCTION__ );

    return dfb_layer_wait_vsync( thiz->obj );
}

void ILayerRealInit(ILayerReal *thiz, CoreDFB *core, CoreLayer *obj)
{
	thiz->base.core = core;
	thiz->base.obj = obj;

 	thiz->base.CreateContext = ILayerReal_CreateContext;
	thiz->base.GetPrimaryContext = ILayerReal_GetPrimaryContext;
	thiz->base.ActivateContext = ILayerReal_ActivateContext;
	thiz->base.GetCurrentOutputField = ILayerReal_GetCurrentOutputField;
	thiz->base.SetLevel = ILayerReal_SetLevel;
	thiz->base.WaitVSync = ILayerReal_WaitVSync;
}

