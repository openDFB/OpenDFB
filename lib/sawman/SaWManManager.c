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

#include "SaWManManager.h"

#include <directfb_util.h>

#include <direct/debug.h>
#include <direct/mem.h>
#include <direct/memcpy.h>
#include <direct/messages.h>

#include <fusion/conf.h>

#include <core/core.h>

D_DEBUG_DOMAIN( DirectFB_SaWManManager, "DirectFB/SaWManManager", "DirectFB SaWManManager" );

/*********************************************************************************************************************/

DFBResult
SaWManManager_Activate(
                    SaWManManager                             *obj

)
{
    if (!fusion_config->secure_fusion || dfb_core_is_master( core_dfb )) {
		ISaWManManagerXReal real;
		ISaWManManagerX *super = (ISaWManManagerX *)&real;
		ISaWManManagerRealInit( &real, core_dfb, obj );

        return super->Activate( super );
    }

	ISaWManManagerXRequestor requestor;
	ISaWManManagerX *super = (ISaWManManagerX *)&requestor;
	ISaWManManagerRequestorInit( &requestor, core_dfb, obj );

    return super->Activate( super );
}

DFBResult
SaWManManager_QueueUpdate(
                    SaWManManager                             *obj,
                    DFBWindowStackingClass                     stacking,
                    const DFBRegion                           *update
)
{
    if (!fusion_config->secure_fusion || dfb_core_is_master( core_dfb )) {
		ISaWManManagerXReal real;
		ISaWManManagerX *super = (ISaWManManagerX *)&real;
		ISaWManManagerRealInit( &real, core_dfb, obj );

        return super->QueueUpdate( super, stacking, update );
    }

	ISaWManManagerXRequestor requestor;
	ISaWManManagerX *super = (ISaWManManagerX *)&requestor;
	ISaWManManagerRequestorInit( &requestor, core_dfb, obj );

    return super->QueueUpdate( super, stacking, update );
}

DFBResult
SaWManManager_ProcessUpdates(
                    SaWManManager                             *obj,
                    DFBSurfaceFlipFlags                        flags
)
{
    if (!fusion_config->secure_fusion || dfb_core_is_master( core_dfb )) {
		ISaWManManagerXReal real;
		ISaWManManagerX *super = (ISaWManManagerX *)&real;
		ISaWManManagerRealInit( &real, core_dfb, obj );

        return super->ProcessUpdates( super, flags );
    }

	ISaWManManagerXRequestor requestor;
	ISaWManManagerX *super = (ISaWManManagerX *)&requestor;
	ISaWManManagerRequestorInit( &requestor, core_dfb, obj );

    return super->ProcessUpdates( super, flags );
}

DFBResult
SaWManManager_CloseWindow(
                    SaWManManager                             *obj,
                    SaWManWindow                              *window
)
{
    if (!fusion_config->secure_fusion || dfb_core_is_master( core_dfb )) {
		ISaWManManagerXReal real;
		ISaWManManagerX *super = (ISaWManManagerX *)&real;
		ISaWManManagerRealInit( &real, core_dfb, obj );

        return super->CloseWindow( super, window );
    }

	ISaWManManagerXRequestor requestor;
	ISaWManManagerX *super = (ISaWManManagerX *)&requestor;
	ISaWManManagerRequestorInit( &requestor, core_dfb, obj );


    return super->CloseWindow( super, window );
}

DFBResult
SaWManManager_InsertWindow(
                    SaWManManager                             *obj,
                    SaWManWindow                              *window,
                    SaWManWindow                              *relative,
                    SaWManWindowRelation                       relation
)
{
    if (!fusion_config->secure_fusion || dfb_core_is_master( core_dfb )) {
		ISaWManManagerXReal real;
		ISaWManManagerX *super = (ISaWManManagerX *)&real;
		ISaWManManagerRealInit( &real, core_dfb, obj );

        return super->InsertWindow( super, window, relative, relation );
    }

	ISaWManManagerXRequestor requestor;
	ISaWManManagerX *super = (ISaWManManagerX *)&requestor;
	ISaWManManagerRequestorInit( &requestor, core_dfb, obj );


    return super->InsertWindow( super, window, relative, relation );
}

DFBResult
SaWManManager_RemoveWindow(
                    SaWManManager                             *obj,
                    SaWManWindow                              *window
)
{
    if (!fusion_config->secure_fusion || dfb_core_is_master( core_dfb )) {
		ISaWManManagerXReal real;
		ISaWManManagerX *super = (ISaWManManagerX *)&real;
		ISaWManManagerRealInit( &real, core_dfb, obj );

        return super->RemoveWindow( super, window );
    }

	ISaWManManagerXRequestor requestor;
	ISaWManManagerX *super = (ISaWManManagerX *)&requestor;
	ISaWManManagerRequestorInit( &requestor, core_dfb, obj );


    return super->RemoveWindow( super, window );
}

DFBResult
SaWManManager_SwitchFocus(
                    SaWManManager                             *obj,
                    SaWManWindow                              *window
)
{
    if (!fusion_config->secure_fusion || dfb_core_is_master( core_dfb )) {
		ISaWManManagerXReal real;
		ISaWManManagerX *super = (ISaWManManagerX *)&real;
		ISaWManManagerRealInit( &real, core_dfb, obj );

        return super->SwitchFocus( super, window );
    }

	ISaWManManagerXRequestor requestor;
	ISaWManManagerX *super = (ISaWManManagerX *)&requestor;
	ISaWManManagerRequestorInit( &requestor, core_dfb, obj );


    return super->SwitchFocus( super, window );
}

DFBResult
SaWManManager_SetScalingMode(
                    SaWManManager                             *obj,
                    SaWManScalingMode                          mode
)
{
    if (!fusion_config->secure_fusion || dfb_core_is_master( core_dfb )) {
		ISaWManManagerXReal real;
		ISaWManManagerX *super = (ISaWManManagerX *)&real;
		ISaWManManagerRealInit( &real, core_dfb, obj );

        return super->SetScalingMode( super, mode );
    }

	ISaWManManagerXRequestor requestor;
	ISaWManManagerX *super = (ISaWManManagerX *)&requestor;
	ISaWManManagerRequestorInit( &requestor, core_dfb, obj );


    return super->SetScalingMode( super, mode );
}

DFBResult
SaWManManager_SetWindowConfig(
                    SaWManManager                             *obj,
                    SaWManWindow                              *window,
                    const SaWManWindowConfig                  *config,
                    SaWManWindowConfigFlags                    flags
)
{
    if (!fusion_config->secure_fusion || dfb_core_is_master( core_dfb )) {
		ISaWManManagerXReal real;
		ISaWManManagerX *super = (ISaWManManagerX *)&real;
		ISaWManManagerRealInit( &real, core_dfb, obj );

        return super->SetWindowConfig( super, window, config, flags );
    }

	ISaWManManagerXRequestor requestor;
	ISaWManManagerX *super = (ISaWManManagerX *)&requestor;
	ISaWManManagerRequestorInit( &requestor, core_dfb, obj );


    return super->SetWindowConfig( super, window, config, flags );
}

DFBResult
SaWManManager_IsShowingWindow(
                    SaWManManager                             *obj,
                    SaWManWindow                              *window,
                    DFBBoolean                                *ret_showing
)
{
    if (!fusion_config->secure_fusion || dfb_core_is_master( core_dfb )) {
		ISaWManManagerXReal real;
		ISaWManManagerX *super = (ISaWManManagerX *)&real;
		ISaWManManagerRealInit( &real, core_dfb, obj );

        return super->IsShowingWindow( super, window, ret_showing );
    }

	ISaWManManagerXRequestor requestor;
	ISaWManManagerX *super = (ISaWManManagerX *)&requestor;
	ISaWManManagerRequestorInit( &requestor, core_dfb, obj );


    return super->IsShowingWindow( super, window, ret_showing );
}

/*********************************************************************************************************************/

static FusionCallHandlerResult
SaWManManager_Dispatch( int           caller,   /* fusion id of the caller */
                     int           call_arg, /* optional call parameter */
                     void         *ptr, /* optional call parameter */
                     unsigned int  length,
                     void         *ctx,      /* optional handler context */
                     unsigned int  serial,
                     void         *ret_ptr,
                     unsigned int  ret_size,
                     unsigned int *ret_length )
{
    SaWManManager *obj = (SaWManManager*) ctx;
    SaWManManagerDispatch__Dispatch( obj, caller, call_arg, ptr, length, ret_ptr, ret_size, ret_length );

    return FCHR_RETURN;
}

void SaWManManager_Init_Dispatch(
                    CoreDFB              *core,
                    SaWManManager        *obj,
                    FusionCall           *call
)
{
    fusion_call_init3( call, SaWManManager_Dispatch, obj, core->world );
}

void  SaWManManager_Deinit_Dispatch(
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
ISaWManManagerRequestor_Activate(ISaWManManagerX* thiz

)
{
    DFBResult           ret = DFB_OK;
    char        args_static[1000];
    char        return_args_static[1000];
    SaWManManagerActivate       *args = (SaWManManagerActivate*) args_alloc( args_static, sizeof(SaWManManagerActivate) );
    SaWManManagerActivateReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (SaWManManagerActivateReturn*) args_alloc( return_args_static, sizeof(SaWManManagerActivateReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_SaWManManager, "ISaWManManagerRequestor_%s()\n", __FUNCTION__ );



    ret = (DFBResult) SaWManManager_Call( thiz->obj, FCEF_NONE, SaWManManagerCall_Activate, args, sizeof(SaWManManagerActivate), return_args, sizeof(SaWManManagerActivateReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: SaWManManager_Call( SaWManManager_Activate ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: SaWManManager_Activate failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ISaWManManagerRequestor_QueueUpdate(ISaWManManagerX* thiz,
                    DFBWindowStackingClass                     stacking,
                    const DFBRegion                           *update
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[1000];
    SaWManManagerQueueUpdate       *args = (SaWManManagerQueueUpdate*) args_alloc( args_static, sizeof(SaWManManagerQueueUpdate) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_SaWManManager, "ISaWManManagerRequestor_%s()\n", __FUNCTION__ );


    args->stacking = stacking;
  if (update) {
    args->update = *update;
    args->update_set = true;
  }
  else
    args->update_set = false;

    ret = (DFBResult) SaWManManager_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY), SaWManManagerCall_QueueUpdate, args, sizeof(SaWManManagerQueueUpdate), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: SaWManManager_Call( SaWManManager_QueueUpdate ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
ISaWManManagerRequestor_ProcessUpdates(ISaWManManagerX* thiz,
                    DFBSurfaceFlipFlags                        flags
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[1000];
    SaWManManagerProcessUpdates       *args = (SaWManManagerProcessUpdates*) args_alloc( args_static, sizeof(SaWManManagerProcessUpdates) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_SaWManManager, "ISaWManManagerRequestor_%s()\n", __FUNCTION__ );


    args->flags = flags;

    ret = (DFBResult) SaWManManager_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY), SaWManManagerCall_ProcessUpdates, args, sizeof(SaWManManagerProcessUpdates), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: SaWManManager_Call( SaWManManager_ProcessUpdates ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
ISaWManManagerRequestor_CloseWindow(ISaWManManagerX* thiz,
                    SaWManWindow                              *window
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[1000];
    SaWManManagerCloseWindow       *args = (SaWManManagerCloseWindow*) args_alloc( args_static, sizeof(SaWManManagerCloseWindow) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_SaWManManager, "ISaWManManagerRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( window != NULL );

    args->window_id = SaWManWindow_GetID( window );

    ret = (DFBResult) SaWManManager_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY), SaWManManagerCall_CloseWindow, args, sizeof(SaWManManagerCloseWindow), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: SaWManManager_Call( SaWManManager_CloseWindow ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
ISaWManManagerRequestor_InsertWindow(ISaWManManagerX* thiz,
                    SaWManWindow                              *window,
                    SaWManWindow                              *relative,
                    SaWManWindowRelation                       relation
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[1000];
    SaWManManagerInsertWindow       *args = (SaWManManagerInsertWindow*) args_alloc( args_static, sizeof(SaWManManagerInsertWindow) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_SaWManManager, "ISaWManManagerRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( window != NULL );

    args->window_id = SaWManWindow_GetID( window );
  if (relative) {
    args->relative_id = SaWManWindow_GetID( relative );
    args->relative_set = true;
  }
  else
    args->relative_set = false;
    args->relation = relation;

    ret = (DFBResult) SaWManManager_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY), SaWManManagerCall_InsertWindow, args, sizeof(SaWManManagerInsertWindow), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: SaWManManager_Call( SaWManManager_InsertWindow ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
ISaWManManagerRequestor_RemoveWindow(ISaWManManagerX* thiz,
                    SaWManWindow                              *window
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[1000];
    SaWManManagerRemoveWindow       *args = (SaWManManagerRemoveWindow*) args_alloc( args_static, sizeof(SaWManManagerRemoveWindow) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_SaWManManager, "ISaWManManagerRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( window != NULL );

    args->window_id = SaWManWindow_GetID( window );

    ret = (DFBResult) SaWManManager_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY), SaWManManagerCall_RemoveWindow, args, sizeof(SaWManManagerRemoveWindow), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: SaWManManager_Call( SaWManManager_RemoveWindow ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
ISaWManManagerRequestor_SwitchFocus(ISaWManManagerX* thiz,
                    SaWManWindow                              *window
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[1000];
    SaWManManagerSwitchFocus       *args = (SaWManManagerSwitchFocus*) args_alloc( args_static, sizeof(SaWManManagerSwitchFocus) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_SaWManManager, "ISaWManManagerRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( window != NULL );

    args->window_id = SaWManWindow_GetID( window );

    ret = (DFBResult) SaWManManager_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY), SaWManManagerCall_SwitchFocus, args, sizeof(SaWManManagerSwitchFocus), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: SaWManManager_Call( SaWManManager_SwitchFocus ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
ISaWManManagerRequestor_SetScalingMode(ISaWManManagerX* thiz,
                    SaWManScalingMode                          mode
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[1000];
    SaWManManagerSetScalingMode       *args = (SaWManManagerSetScalingMode*) args_alloc( args_static, sizeof(SaWManManagerSetScalingMode) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_SaWManManager, "ISaWManManagerRequestor_%s()\n", __FUNCTION__ );


    args->mode = mode;

    ret = (DFBResult) SaWManManager_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY), SaWManManagerCall_SetScalingMode, args, sizeof(SaWManManagerSetScalingMode), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: SaWManManager_Call( SaWManManager_SetScalingMode ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
ISaWManManagerRequestor_SetWindowConfig(ISaWManManagerX* thiz,
                    SaWManWindow                              *window,
                    const SaWManWindowConfig                  *config,
                    SaWManWindowConfigFlags                    flags
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[1000];
    SaWManManagerSetWindowConfig       *args = (SaWManManagerSetWindowConfig*) args_alloc( args_static, sizeof(SaWManManagerSetWindowConfig) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_SaWManManager, "ISaWManManagerRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( window != NULL );
    D_ASSERT( config != NULL );

    args->window_id = SaWManWindow_GetID( window );
    args->config = *config;
    args->flags = flags;

    ret = (DFBResult) SaWManManager_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY), SaWManManagerCall_SetWindowConfig, args, sizeof(SaWManManagerSetWindowConfig), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: SaWManManager_Call( SaWManManager_SetWindowConfig ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
ISaWManManagerRequestor_IsShowingWindow(ISaWManManagerX* thiz,
                    SaWManWindow                              *window,
                    DFBBoolean                                *ret_showing
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[1000];
    char        return_args_static[1000];
    SaWManManagerIsShowingWindow       *args = (SaWManManagerIsShowingWindow*) args_alloc( args_static, sizeof(SaWManManagerIsShowingWindow) );
    SaWManManagerIsShowingWindowReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (SaWManManagerIsShowingWindowReturn*) args_alloc( return_args_static, sizeof(SaWManManagerIsShowingWindowReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_SaWManManager, "ISaWManManagerRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( window != NULL );

    args->window_id = SaWManWindow_GetID( window );

    ret = (DFBResult) SaWManManager_Call( thiz->obj, FCEF_NONE, SaWManManagerCall_IsShowingWindow, args, sizeof(SaWManManagerIsShowingWindow), return_args, sizeof(SaWManManagerIsShowingWindowReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: SaWManManager_Call( SaWManManager_IsShowingWindow ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: SaWManManager_IsShowingWindow failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

    *ret_showing = return_args->showing;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}

void ISaWManManagerRequestorInit(ISaWManManagerXRequestor *thiz, CoreDFB *core, SaWManManager *obj)
{
	thiz->base.core = core;
	thiz->base.obj = obj;

	thiz->base.Activate = ISaWManManagerRequestor_Activate;
	thiz->base.QueueUpdate = ISaWManManagerRequestor_QueueUpdate;
	thiz->base.ProcessUpdates = ISaWManManagerRequestor_ProcessUpdates;
	thiz->base.CloseWindow = ISaWManManagerRequestor_CloseWindow;
	thiz->base.InsertWindow = ISaWManManagerRequestor_InsertWindow;
	thiz->base.RemoveWindow = ISaWManManagerRequestor_RemoveWindow;
	thiz->base.SwitchFocus = ISaWManManagerRequestor_SwitchFocus;
	thiz->base.SetScalingMode = ISaWManManagerRequestor_SetScalingMode;
	thiz->base.SetWindowConfig = ISaWManManagerRequestor_SetWindowConfig;
	thiz->base.IsShowingWindow = ISaWManManagerRequestor_IsShowingWindow;
}


/*********************************************************************************************************************/

static DFBResult
__SaWManManagerDispatch__Dispatch( SaWManManager *obj,
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


	ISaWManManagerXReal real;
	ISaWManManagerX *super = (ISaWManManagerX *)&real;
	ISaWManManagerRealInit( &real, core_dfb, obj );

    switch (method) {
        case SaWManManagerCall_Activate: {
            D_UNUSED
            SaWManManagerActivate       *args        = (SaWManManagerActivate *) ptr;
            SaWManManagerActivateReturn *return_args = (SaWManManagerActivateReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_SaWManManager, "=-> SaWManManager_Activate\n" );

            return_args->result = super->Activate( super );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(SaWManManagerActivateReturn);

            return DFB_OK;
        }

        case SaWManManagerCall_QueueUpdate: {
            D_UNUSED
            SaWManManagerQueueUpdate       *args        = (SaWManManagerQueueUpdate *) ptr;

            D_DEBUG_AT( DirectFB_SaWManManager, "=-> SaWManManager_QueueUpdate\n" );

            D_DEBUG_AT( DirectFB_SaWManManager, "  -> stacking = %x\n", args->stacking );
  			if (args->update_set)
         		;    // TODO: DFBRegion_debug args->update;

            super->QueueUpdate( super, args->stacking, args->update_set ? &args->update : NULL );

            return DFB_OK;
        }

        case SaWManManagerCall_ProcessUpdates: {
            D_UNUSED
            SaWManManagerProcessUpdates       *args        = (SaWManManagerProcessUpdates *) ptr;

            D_DEBUG_AT( DirectFB_SaWManManager, "=-> SaWManManager_ProcessUpdates\n" );

            D_DEBUG_AT( DirectFB_SaWManManager, "  -> flags = %x\n", args->flags );

            super->ProcessUpdates( super, args->flags );

            return DFB_OK;
        }

        case SaWManManagerCall_CloseWindow: {
    		SaWManWindow *window = NULL;
            D_UNUSED
            SaWManManagerCloseWindow       *args        = (SaWManManagerCloseWindow *) ptr;

            D_DEBUG_AT( DirectFB_SaWManManager, "=-> SaWManManager_CloseWindow\n" );

            D_DEBUG_AT( DirectFB_SaWManManager, "  -> window = %d\n", args->window_id );

            ret = (DFBResult) SaWManWindow_Lookup( core_dfb, args->window_id, caller, &window );
            if (ret) {
                 D_DERROR( ret, "%s: Looking up window by ID %u failed!\n", __FUNCTION__, args->window_id );
                 return ret;
            }

            super->CloseWindow( super, window );

            if (window)
                SaWManWindow_Unref( window );

            return DFB_OK;
        }

        case SaWManManagerCall_InsertWindow: {
		    SaWManWindow *window = NULL;
		    SaWManWindow *relative = NULL;
            D_UNUSED
            SaWManManagerInsertWindow       *args        = (SaWManManagerInsertWindow *) ptr;

            D_DEBUG_AT( DirectFB_SaWManManager, "=-> SaWManManager_InsertWindow\n" );

            D_DEBUG_AT( DirectFB_SaWManManager, "  -> window = %d\n", args->window_id );
  			if (args->relative_set)
	            D_DEBUG_AT( DirectFB_SaWManManager, "  -> relative = %d\n", args->relative_id );
            D_DEBUG_AT( DirectFB_SaWManManager, "  -> relation = %x\n", args->relation );

            ret = (DFBResult) SaWManWindow_Lookup( core_dfb, args->window_id, caller, &window );
            if (ret) {
                 D_DERROR( ret, "%s: Looking up window by ID %u failed!\n", __FUNCTION__, args->window_id );
                 return ret;
            }

            if (args->relative_set) {
                ret = (DFBResult) SaWManWindow_Lookup( core_dfb, args->relative_id, caller, &relative );
                if (ret) {
                     D_DERROR( ret, "%s: Looking up relative by ID %u failed!\n", __FUNCTION__, args->relative_id );
                     return ret;
                }
            }

            super->InsertWindow( super, window, args->relative_set ? relative : NULL, args->relation );

            if (window)
                SaWManWindow_Unref( window );

            if (relative)
                SaWManWindow_Unref( relative );

            return DFB_OK;
        }

        case SaWManManagerCall_RemoveWindow: {
    SaWManWindow *window = NULL;
            D_UNUSED
            SaWManManagerRemoveWindow       *args        = (SaWManManagerRemoveWindow *) ptr;

            D_DEBUG_AT( DirectFB_SaWManManager, "=-> SaWManManager_RemoveWindow\n" );

            D_DEBUG_AT( DirectFB_SaWManManager, "  -> window = %d\n", args->window_id );

            ret = (DFBResult) SaWManWindow_Lookup( core_dfb, args->window_id, caller, &window );
            if (ret) {
                 D_DERROR( ret, "%s: Looking up window by ID %u failed!\n", __FUNCTION__, args->window_id );
                 return ret;
            }

            super->RemoveWindow( super, window );

            if (window)
                SaWManWindow_Unref( window );

            return DFB_OK;
        }

        case SaWManManagerCall_SwitchFocus: {
    SaWManWindow *window = NULL;
            D_UNUSED
            SaWManManagerSwitchFocus       *args        = (SaWManManagerSwitchFocus *) ptr;

            D_DEBUG_AT( DirectFB_SaWManManager, "=-> SaWManManager_SwitchFocus\n" );

            D_DEBUG_AT( DirectFB_SaWManManager, "  -> window = %d\n", args->window_id );

            ret = (DFBResult) SaWManWindow_Lookup( core_dfb, args->window_id, caller, &window );
            if (ret) {
                 D_DERROR( ret, "%s: Looking up window by ID %u failed!\n", __FUNCTION__, args->window_id );
                 return ret;
            }

            super->SwitchFocus( super, window );

            if (window)
                SaWManWindow_Unref( window );

            return DFB_OK;
        }

        case SaWManManagerCall_SetScalingMode: {
            D_UNUSED
            SaWManManagerSetScalingMode       *args        = (SaWManManagerSetScalingMode *) ptr;

            D_DEBUG_AT( DirectFB_SaWManManager, "=-> SaWManManager_SetScalingMode\n" );

            D_DEBUG_AT( DirectFB_SaWManManager, "  -> mode = %x\n", args->mode );

            super->SetScalingMode( super, args->mode );

            return DFB_OK;
        }

        case SaWManManagerCall_SetWindowConfig: {
    SaWManWindow *window = NULL;
            D_UNUSED
            SaWManManagerSetWindowConfig       *args        = (SaWManManagerSetWindowConfig *) ptr;

            D_DEBUG_AT( DirectFB_SaWManManager, "=-> SaWManManager_SetWindowConfig\n" );

            D_DEBUG_AT( DirectFB_SaWManManager, "  -> window = %d\n", args->window_id );
         ;    // TODO: SaWManWindowConfig_debug args->config;
            D_DEBUG_AT( DirectFB_SaWManManager, "  -> flags = %x\n", args->flags );

            ret = (DFBResult) SaWManWindow_Lookup( core_dfb, args->window_id, caller, &window );
            if (ret) {
                 D_DERROR( ret, "%s: Looking up window by ID %u failed!\n", __FUNCTION__, args->window_id );
                 return ret;
            }

            super->SetWindowConfig( super, window, &args->config, args->flags );

            if (window)
                SaWManWindow_Unref( window );

            return DFB_OK;
        }

        case SaWManManagerCall_IsShowingWindow: {
    SaWManWindow *window = NULL;
            D_UNUSED
            SaWManManagerIsShowingWindow       *args        = (SaWManManagerIsShowingWindow *) ptr;
            SaWManManagerIsShowingWindowReturn *return_args = (SaWManManagerIsShowingWindowReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_SaWManManager, "=-> SaWManManager_IsShowingWindow\n" );

            ret = (DFBResult) SaWManWindow_Lookup( core_dfb, args->window_id, caller, &window );
            if (ret) {
                 D_DERROR( ret, "%s: Looking up window by ID %u failed!\n", __FUNCTION__, args->window_id );
                 return_args->result = ret;
                 return ret;
            }

            return_args->result = super->IsShowingWindow( super, window, &return_args->showing );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(SaWManManagerIsShowingWindowReturn);

            if (window)
                SaWManWindow_Unref( window );

            return DFB_OK;
        }

    }

    return DFB_NOSUCHMETHOD;
}
/*********************************************************************************************************************/

DFBResult
SaWManManagerDispatch__Dispatch( SaWManManager *obj,
                                FusionID      caller,
                                int           method,
                                void         *ptr,
                                unsigned int  length,
                                void         *ret_ptr,
                                unsigned int  ret_size,
                                unsigned int *ret_length )
{
    DFBResult ret = DFB_OK;

    D_DEBUG_AT( DirectFB_SaWManManager, "SaWManManagerDispatch::%s( %p )\n", __FUNCTION__, obj );

    ret = __SaWManManagerDispatch__Dispatch( obj, caller, method, ptr, length, ret_ptr, ret_size, ret_length );

    return ret;
}

