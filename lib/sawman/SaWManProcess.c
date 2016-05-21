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

#include "SaWManProcess.h"

#include <directfb_util.h>

#include <direct/debug.h>
#include <direct/mem.h>
#include <direct/memcpy.h>
#include <direct/messages.h>

#include <fusion/conf.h>

#include <core/core.h>

D_DEBUG_DOMAIN( DirectFB_SaWManProcess, "DirectFB/SaWManProcess", "DirectFB SaWManProcess" );

/*********************************************************************************************************************/

DFBResult
SaWManProcess_SetExiting(
                    SaWManProcess                             *obj

)
{
    if (!fusion_config->secure_fusion || dfb_core_is_master( core_dfb )) {
		ISaWManProcessReal real;
		ISaWManProcess *super = (ISaWManProcess *)&real;
		ISaWManProcessRealInit( &real, core_dfb, obj );

        return super->SetExiting( super );
    }

	ISaWManProcessRequestor requestor;
	ISaWManProcess *super = (ISaWManProcess *)&requestor;
	ISaWManProcessRequestorInit( &requestor, core_dfb, obj );

    return super->SetExiting( super );
}

DFBResult
SaWManProcess_RegisterManager(
                    SaWManProcess                             *obj,
                    const SaWManRegisterManagerData           *data,
                    SaWManManager                            **ret_manager
)
{
    if (!fusion_config->secure_fusion || dfb_core_is_master( core_dfb )) {
		ISaWManProcessReal real;
		ISaWManProcess *super = (ISaWManProcess *)&real;
		ISaWManProcessRealInit( &real, core_dfb, obj );

        return super->RegisterManager( super, data, ret_manager );
    }

	ISaWManProcessRequestor requestor;
	ISaWManProcess *super = (ISaWManProcess *)&requestor;
	ISaWManProcessRequestorInit( &requestor, core_dfb, obj );

    return super->RegisterManager( super, data, ret_manager );
}

/*********************************************************************************************************************/

static FusionCallHandlerResult
SaWManProcess_Dispatch( int           caller,   /* fusion id of the caller */
                     int           call_arg, /* optional call parameter */
                     void         *ptr, /* optional call parameter */
                     unsigned int  length,
                     void         *ctx,      /* optional handler context */
                     unsigned int  serial,
                     void         *ret_ptr,
                     unsigned int  ret_size,
                     unsigned int *ret_length )
{
    SaWManProcess *obj = (SaWManProcess*) ctx;
    SaWManProcessDispatch__Dispatch( obj, caller, call_arg, ptr, length, ret_ptr, ret_size, ret_length );

    return FCHR_RETURN;
}

void SaWManProcess_Init_Dispatch(
                    CoreDFB              *core,
                    SaWManProcess        *obj,
                    FusionCall           *call
)
{
    fusion_call_init3( call, SaWManProcess_Dispatch, obj, core->world );
}

void  SaWManProcess_Deinit_Dispatch(
                    FusionCall           *call
)
{
     fusion_call_destroy( call );
}

/*********************************************************************************************************************/

static __inline__ void *args_alloc( void *static_buffer, size_t size )
{
    void *buffer = static_buffer;

    if (size > 1000) {
        buffer = D_MALLOC( size );
        if (!buffer)
            return NULL;
    }

    return buffer;
}

static __inline__ void args_free( void *static_buffer, void *buffer )
{
    if (buffer != static_buffer)
        D_FREE( buffer );
}


DFBResult
ISaWManProcessRequestor_SetExiting(ISaWManProcess *thiz

)
{
    DFBResult           ret = DFB_OK;
    char        args_static[1000];
    char        return_args_static[1000];
    SaWManProcessSetExiting       *args = (SaWManProcessSetExiting*) args_alloc( args_static, sizeof(SaWManProcessSetExiting) );
    SaWManProcessSetExitingReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (SaWManProcessSetExitingReturn*) args_alloc( return_args_static, sizeof(SaWManProcessSetExitingReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_SaWManProcess, "ISaWManProcessRequestor_%s()\n", __FUNCTION__ );



    ret = (DFBResult) SaWManProcess_Call( thiz->obj, FCEF_NONE, SaWManProcessCall_SetExiting, args, sizeof(SaWManProcessSetExiting), return_args, sizeof(SaWManProcessSetExitingReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: SaWManProcess_Call( SaWManProcess_SetExiting ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: SaWManProcess_SetExiting failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ISaWManProcessRequestor_RegisterManager(ISaWManProcess *thiz,
                    const SaWManRegisterManagerData           *data,
                    SaWManManager                            **ret_manager
)
{
    DFBResult           ret = DFB_OK;
    SaWManManager *manager = NULL;
    char        args_static[1000];
    char        return_args_static[1000];
    SaWManProcessRegisterManager       *args = (SaWManProcessRegisterManager*) args_alloc( args_static, sizeof(SaWManProcessRegisterManager) );
    SaWManProcessRegisterManagerReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (SaWManProcessRegisterManagerReturn*) args_alloc( return_args_static, sizeof(SaWManProcessRegisterManagerReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_SaWManProcess, "ISaWManProcessRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( data != NULL );
    D_ASSERT( ret_manager != NULL );

    args->data = *data;

    ret = (DFBResult) SaWManProcess_Call( thiz->obj, FCEF_NONE, SaWManProcessCall_RegisterManager, args, sizeof(SaWManProcessRegisterManager), return_args, sizeof(SaWManProcessRegisterManagerReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: SaWManProcess_Call( SaWManProcess_RegisterManager ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: SaWManProcess_RegisterManager failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }


    ret = (DFBResult) SaWManManager_Catch( thiz->core, return_args->manager_id, &manager );
    if (ret) {
         D_DERROR( ret, "%s: Catching manager by ID %u failed!\n", __FUNCTION__, return_args->manager_id );
         goto out;
    }

    *ret_manager = manager;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


void ISaWManProcessRequestorInit(ISaWManProcessRequestor *thiz, CoreDFB *core, SaWManProcess *obj)
{
	thiz->base.core = core;
	thiz->base.obj = obj;

	thiz->base.SetExiting = ISaWManProcessRequestor_SetExiting;
	thiz->base.RegisterManager = ISaWManProcessRequestor_RegisterManager;
}


/*********************************************************************************************************************/

static DFBResult
__SaWManProcessDispatch__Dispatch( SaWManProcess *obj,
                                FusionID      caller,
                                int           method,
                                void         *ptr,
                                unsigned int  length,
                                void         *ret_ptr,
                                unsigned int  ret_size,
                                unsigned int *ret_length )
{
    D_UNUSED
    DFBResult ret;

	ISaWManProcessReal real;
	ISaWManProcess *super = (ISaWManProcess *)&real;
	ISaWManProcessRealInit( &real, core_dfb, obj );


    switch (method) {
        case SaWManProcessCall_SetExiting: {
            D_UNUSED
            SaWManProcessSetExiting       *args        = (SaWManProcessSetExiting *) ptr;
            SaWManProcessSetExitingReturn *return_args = (SaWManProcessSetExitingReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_SaWManProcess, "=-> SaWManProcess_SetExiting\n" );

            return_args->result = super->SetExiting( super );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(SaWManProcessSetExitingReturn);

            return DFB_OK;
        }

        case SaWManProcessCall_RegisterManager: {
    SaWManManager *manager = NULL;
            D_UNUSED
            SaWManProcessRegisterManager       *args        = (SaWManProcessRegisterManager *) ptr;
            SaWManProcessRegisterManagerReturn *return_args = (SaWManProcessRegisterManagerReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_SaWManProcess, "=-> SaWManProcess_RegisterManager\n" );

            return_args->result = super->RegisterManager( super, &args->data, &manager );
            if (return_args->result == DFB_OK) {
                SaWManManager_Throw( manager, caller, &return_args->manager_id );
            }

            *ret_length = sizeof(SaWManProcessRegisterManagerReturn);

            return DFB_OK;
        }

    }

    return DFB_NOSUCHMETHOD;
}
/*********************************************************************************************************************/

DFBResult
SaWManProcessDispatch__Dispatch( SaWManProcess *obj,
                                FusionID      caller,
                                int           method,
                                void         *ptr,
                                unsigned int  length,
                                void         *ret_ptr,
                                unsigned int  ret_size,
                                unsigned int *ret_length )
{
    DFBResult ret = DFB_OK;

    D_DEBUG_AT( DirectFB_SaWManProcess, "SaWManProcessDispatch::%s( %p )\n", __FUNCTION__, obj );

    ret = __SaWManProcessDispatch__Dispatch( obj, caller, method, ptr, length, ret_ptr, ret_size, ret_length );

    return ret;
}

