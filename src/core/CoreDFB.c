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
#include "CoreDFB.h"
#include <directfb_util.h>
#include <direct/debug.h>
#include <direct/mem.h>
#include <direct/memcpy.h>
#include <direct/messages.h>

#include <fusion/conf.h>
#include <core/core.h>
#include <core/CoreDFB_CallMode.h>

D_DEBUG_DOMAIN( DirectFB_CoreDFB, "DirectFB/CoreDFB", "DirectFB CoreDFB" );

/*********************************************************************************************************************/

DFBResult
CoreDFB_Initialize(CoreDFB *obj)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ICoreReal real;
			ICore *super = (ICore *)&real;
			ICoreRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->Initialize( super );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ICoreRequestor requestor;
			ICore *super = (ICore *)&requestor;
			ICoreRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->Initialize( super );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreDFB_Register(CoreDFB *obj, u32 slave_call)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ICoreReal real;
			ICore *super = (ICore *)&real;
			ICoreRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->Register( super, slave_call );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ICoreRequestor requestor;
			ICore *super = (ICore *)&requestor;
			ICoreRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->Register( super, slave_call );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreDFB_CreateSurface(CoreDFB *obj,
                    	const CoreSurfaceConfig *config,
                    	CoreSurfaceTypeFlags type,
                    	u64 resource_id,
                    	CorePalette *palette,
                    	CoreSurface **ret_surface)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ICoreReal real;
			ICore *super = (ICore *)&real;
			ICoreRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->CreateSurface( super, config, type, resource_id, palette, ret_surface );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ICoreRequestor requestor;
			ICore *super = (ICore *)&requestor;
			ICoreRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->CreateSurface( super, config, type, resource_id, palette, ret_surface );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreDFB_CreatePalette(CoreDFB                                   *obj,
                    u32                                        size,
                    CorePalette                              **ret_palette)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ICoreReal real;
			ICore *super = (ICore *)&real;
			ICoreRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->CreatePalette( super, size, ret_palette );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ICoreRequestor requestor;
			ICore *super = (ICore *)&requestor;
			ICoreRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->CreatePalette( super, size, ret_palette );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreDFB_CreateState(CoreDFB                                   *obj,
                    CoreGraphicsState                        **ret_state)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ICoreReal real;
			ICore *super = (ICore *)&real;
			ICoreRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->CreateState( super, ret_state );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ICoreRequestor requestor;
			ICore *super = (ICore *)&requestor;
			ICoreRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->CreateState( super, ret_state );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreDFB_WaitIdle(CoreDFB *obj)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ICoreReal real;
			ICore *super = (ICore *)&real;
			ICoreRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->WaitIdle( super );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ICoreRequestor requestor;
			ICore *super = (ICore *)&requestor;
			ICoreRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->WaitIdle( super );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreDFB_CreateImageProvider(
                    CoreDFB                                   *obj,
                    u32                                        buffer_call,
                    u32                                       *ret_call)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ICoreReal real;
			ICore *super = (ICore *)&real;
			ICoreRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->CreateImageProvider( super, buffer_call, ret_call );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ICoreRequestor requestor;
			ICore *super = (ICore *)&requestor;
			ICoreRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->CreateImageProvider( super, buffer_call, ret_call );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreDFB_AllowSurface(
                    CoreDFB                                   *obj,
                    CoreSurface                               *surface,
                    const char                                *executable,
                    u32                                        executable_length)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ICoreReal real;
			ICore *super = (ICore *)&real;
			ICoreRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->AllowSurface( super, surface, executable, executable_length );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ICoreRequestor requestor;
			ICore *super = (ICore *)&requestor;
			ICoreRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->AllowSurface( super, surface, executable, executable_length );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreDFB_GetSurface(
                    CoreDFB                                   *obj,
                    u32                                        surface_id,
                    CoreSurface                              **ret_surface)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ICoreReal real;
			ICore *super = (ICore *)&real;
			ICoreRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->GetSurface( super, surface_id, ret_surface );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ICoreRequestor requestor;
			ICore *super = (ICore *)&requestor;
			ICoreRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->GetSurface( super, surface_id, ret_surface );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreDFB_ClipboardSet(
                    CoreDFB                                   *obj,
                    const char                                *mime_type,
                    u32                                        mime_type_size,
                    const char                                *data,
                    u32                                        data_size,
                    u64                                        timestamp_us)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ICoreReal real;
			ICore *super = (ICore *)&real;
			ICoreRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->ClipboardSet( super, mime_type, mime_type_size, data, data_size, timestamp_us );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ICoreRequestor requestor;
			ICore *super = (ICore *)&requestor;
			ICoreRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->ClipboardSet( super, mime_type, mime_type_size, data, data_size, timestamp_us );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreDFB_ClipboardGet(
                    CoreDFB                                   *obj,
                    char                                      *ret_mime_type,
                    u32                                       *ret_mime_type_size,
                    char                                      *ret_data,
                    u32                                       *ret_data_size)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ICoreReal real;
			ICore *super = (ICore *)&real;
			ICoreRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->ClipboardGet( super, ret_mime_type, ret_mime_type_size, ret_data, ret_data_size );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ICoreRequestor requestor;
			ICore *super = (ICore *)&requestor;
			ICoreRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->ClipboardGet( super, ret_mime_type, ret_mime_type_size, ret_data, ret_data_size );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreDFB_ClipboardGetTimestamp(
                    CoreDFB                                   *obj,
                    u64                                       *ret_timestamp_us)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ICoreReal real;
			ICore *super = (ICore *)&real;
			ICoreRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->ClipboardGetTimestamp( super, ret_timestamp_us );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ICoreRequestor requestor;
			ICore *super = (ICore *)&requestor;
			ICoreRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->ClipboardGetTimestamp( super, ret_timestamp_us );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

/*********************************************************************************************************************/

static FusionCallHandlerResult
CoreDFB_Dispatch( int           caller,   /* fusion id of the caller */
                     int           call_arg, /* optional call parameter */
                     void         *ptr, /* optional call parameter */
                     unsigned int  length,
                     void         *ctx,      /* optional handler context */
                     unsigned int  serial,
                     void         *ret_ptr,
                     unsigned int  ret_size,
                     unsigned int *ret_length )
{
    CoreDFB *obj = (CoreDFB*) ctx;
    CoreDFBDispatch__Dispatch( obj, caller, call_arg, ptr, length, ret_ptr, ret_size, ret_length );

    return FCHR_RETURN;
}

void CoreDFB_Init_Dispatch(
                    CoreDFB              *core,
                    CoreDFB              *obj,
                    FusionCall           *call)
{
    fusion_call_init3( call, CoreDFB_Dispatch, obj, core->world );
}

void  CoreDFB_Deinit_Dispatch(
                    FusionCall           *call)
{
     fusion_call_destroy( call );
}

/*********************************************************************************************************************/

static __inline__ void *args_alloc( void *static_buffer, size_t size )
{
    void *buffer = static_buffer;

    if (size > FLUXED_ARGS_BYTES) {
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
ICoreRequestor_Initialize(ICore *thiz)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreDFBInitialize       *args = (CoreDFBInitialize*) args_alloc( args_static, sizeof(CoreDFBInitialize) );
    CoreDFBInitializeReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreDFBInitializeReturn*) args_alloc( return_args_static, sizeof(CoreDFBInitializeReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreDFB, "ICoreRequesto_%s()\n", __FUNCTION__ );



    ret = (DFBResult) CoreDFB_Call( thiz->obj, FCEF_NONE, CoreDFBCall_Initialize, args, sizeof(CoreDFBInitialize), return_args, sizeof(CoreDFBInitializeReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreDFB_Call( CoreDFB_Initialize ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreDFB_Initialize failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ICoreRequestor_Register(ICore *thiz,
                    u32                                        slave_call)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreDFBRegister       *args = (CoreDFBRegister*) args_alloc( args_static, sizeof(CoreDFBRegister) );
    CoreDFBRegisterReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreDFBRegisterReturn*) args_alloc( return_args_static, sizeof(CoreDFBRegisterReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreDFB, "ICoreRequesto_%s()\n", __FUNCTION__ );


    args->slave_call = slave_call;

    ret = (DFBResult) CoreDFB_Call( thiz->obj, FCEF_NONE, CoreDFBCall_Register, args, sizeof(CoreDFBRegister), return_args, sizeof(CoreDFBRegisterReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreDFB_Call( CoreDFB_Register ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreDFB_Register failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ICoreRequestor_CreateSurface(ICore *thiz,
                    const CoreSurfaceConfig                   *config,
                    CoreSurfaceTypeFlags                       type,
                    u64                                        resource_id,
                    CorePalette                               *palette,
                    CoreSurface                              **ret_surface)
{
    DFBResult           ret = DFB_OK;
    CoreSurface *surface = NULL;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreDFBCreateSurface       *args = (CoreDFBCreateSurface*) args_alloc( args_static, sizeof(CoreDFBCreateSurface) );
    CoreDFBCreateSurfaceReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreDFBCreateSurfaceReturn*) args_alloc( return_args_static, sizeof(CoreDFBCreateSurfaceReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreDFB, "ICoreRequesto_%s()\n", __FUNCTION__ );

    D_ASSERT( config != NULL );
    D_ASSERT( ret_surface != NULL );

    args->config = *config;
    args->type = type;
    args->resource_id = resource_id;
  if (palette) {
    args->palette_id = CorePalette_GetID( palette );
    args->palette_set = true;
  }
  else
    args->palette_set = false;

    ret = (DFBResult) CoreDFB_Call( thiz->obj, FCEF_NONE, CoreDFBCall_CreateSurface, args, sizeof(CoreDFBCreateSurface), return_args, sizeof(CoreDFBCreateSurfaceReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreDFB_Call( CoreDFB_CreateSurface ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreDFB_CreateSurface failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }


    ret = (DFBResult) CoreSurface_Catch( thiz->core, return_args->surface_ptr, &surface );
    if (ret) {
         D_DERROR( ret, "%s: Catching surface by ID %u failed!\n", __FUNCTION__, return_args->surface_id );
         goto out;
    }

    *ret_surface = surface;

out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ICoreRequestor_CreatePalette(ICore *thiz,
                    u32                                        size,
                    CorePalette                              **ret_palette)
{
    DFBResult           ret = DFB_OK;
    CorePalette *palette = NULL;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreDFBCreatePalette       *args = (CoreDFBCreatePalette*) args_alloc( args_static, sizeof(CoreDFBCreatePalette) );
    CoreDFBCreatePaletteReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreDFBCreatePaletteReturn*) args_alloc( return_args_static, sizeof(CoreDFBCreatePaletteReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreDFB, "ICoreRequesto_%s()\n", __FUNCTION__ );

    D_ASSERT( ret_palette != NULL );

    args->size = size;

    ret = (DFBResult) CoreDFB_Call( thiz->obj, FCEF_NONE, CoreDFBCall_CreatePalette, args, sizeof(CoreDFBCreatePalette), return_args, sizeof(CoreDFBCreatePaletteReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreDFB_Call( CoreDFB_CreatePalette ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreDFB_CreatePalette failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }


    ret = (DFBResult) CorePalette_Catch( thiz->core, return_args->palette_ptr, &palette );
    if (ret) {
         D_DERROR( ret, "%s: Catching palette by ID %u failed!\n", __FUNCTION__, return_args->palette_id );
         goto out;
    }

    *ret_palette = palette;

out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ICoreRequestor_CreateState(ICore *thiz,
                    CoreGraphicsState                        **ret_state)
{
    DFBResult           ret = DFB_OK;
    CoreGraphicsState *state = NULL;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreDFBCreateState       *args = (CoreDFBCreateState*) args_alloc( args_static, sizeof(CoreDFBCreateState) );
    CoreDFBCreateStateReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreDFBCreateStateReturn*) args_alloc( return_args_static, sizeof(CoreDFBCreateStateReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreDFB, "ICoreRequesto_%s()\n", __FUNCTION__ );

    D_ASSERT( ret_state != NULL );


    ret = (DFBResult) CoreDFB_Call( thiz->obj, FCEF_NONE, CoreDFBCall_CreateState, args, sizeof(CoreDFBCreateState), return_args, sizeof(CoreDFBCreateStateReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreDFB_Call( CoreDFB_CreateState ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreDFB_CreateState failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }


    ret = (DFBResult) CoreGraphicsState_Catch( thiz->core, return_args->state_ptr, &state );
    if (ret) {
         D_DERROR( ret, "%s: Catching state by ID %u failed!\n", __FUNCTION__, return_args->state_id );
         goto out;
    }

    *ret_state = state;

out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ICoreRequestor_WaitIdle(ICore *thiz)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreDFBWaitIdle       *args = (CoreDFBWaitIdle*) args_alloc( args_static, sizeof(CoreDFBWaitIdle) );
    CoreDFBWaitIdleReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreDFBWaitIdleReturn*) args_alloc( return_args_static, sizeof(CoreDFBWaitIdleReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreDFB, "ICoreRequesto_%s()\n", __FUNCTION__ );



    ret = (DFBResult) CoreDFB_Call( thiz->obj, FCEF_NONE, CoreDFBCall_WaitIdle, args, sizeof(CoreDFBWaitIdle), return_args, sizeof(CoreDFBWaitIdleReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreDFB_Call( CoreDFB_WaitIdle ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreDFB_WaitIdle failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ICoreRequestor_CreateImageProvider(ICore *thiz,
                    u32                                        buffer_call,
                    u32                                       *ret_call)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreDFBCreateImageProvider       *args = (CoreDFBCreateImageProvider*) args_alloc( args_static, sizeof(CoreDFBCreateImageProvider) );
    CoreDFBCreateImageProviderReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreDFBCreateImageProviderReturn*) args_alloc( return_args_static, sizeof(CoreDFBCreateImageProviderReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreDFB, "ICoreRequesto_%s()\n", __FUNCTION__ );


    args->buffer_call = buffer_call;

    ret = (DFBResult) CoreDFB_Call( thiz->obj, FCEF_NONE, CoreDFBCall_CreateImageProvider, args, sizeof(CoreDFBCreateImageProvider), return_args, sizeof(CoreDFBCreateImageProviderReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreDFB_Call( CoreDFB_CreateImageProvider ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreDFB_CreateImageProvider failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

    *ret_call = return_args->call;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ICoreRequestor_AllowSurface(ICore *thiz,
                    CoreSurface                               *surface,
                    const char                                *executable,
                    u32                                        executable_length)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreDFBAllowSurface       *args = (CoreDFBAllowSurface*) args_alloc( args_static, sizeof(CoreDFBAllowSurface) + executable_length * sizeof(char) );
    CoreDFBAllowSurfaceReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreDFBAllowSurfaceReturn*) args_alloc( return_args_static, sizeof(CoreDFBAllowSurfaceReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreDFB, "ICoreRequesto_%s()\n", __FUNCTION__ );

    D_ASSERT( surface != NULL );

    args->surface_id = CoreSurface_GetID( surface );
    args->executable_length = executable_length;
    direct_memcpy( (char*) (args + 1), executable, executable_length * sizeof(char) );

    ret = (DFBResult) CoreDFB_Call( thiz->obj, FCEF_NONE, CoreDFBCall_AllowSurface, args, sizeof(CoreDFBAllowSurface) + executable_length * sizeof(char), return_args, sizeof(CoreDFBAllowSurfaceReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreDFB_Call( CoreDFB_AllowSurface ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreDFB_AllowSurface failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ICoreRequestor_GetSurface(ICore *thiz,
                    u32                                        surface_id,
                    CoreSurface                              **ret_surface)
{
    DFBResult           ret = DFB_OK;
    CoreSurface *surface = NULL;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreDFBGetSurface       *args = (CoreDFBGetSurface*) args_alloc( args_static, sizeof(CoreDFBGetSurface) );
    CoreDFBGetSurfaceReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreDFBGetSurfaceReturn*) args_alloc( return_args_static, sizeof(CoreDFBGetSurfaceReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreDFB, "ICoreRequesto_%s()\n", __FUNCTION__ );

    D_ASSERT( ret_surface != NULL );

    args->surface_id = surface_id;

    ret = (DFBResult) CoreDFB_Call( thiz->obj, FCEF_NONE, CoreDFBCall_GetSurface, args, sizeof(CoreDFBGetSurface), return_args, sizeof(CoreDFBGetSurfaceReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreDFB_Call( CoreDFB_GetSurface ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreDFB_GetSurface failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }


    ret = (DFBResult) CoreSurface_Catch( thiz->core, return_args->surface_ptr, &surface );
    if (ret) {
         D_DERROR( ret, "%s: Catching surface by ID %u failed!\n", __FUNCTION__, return_args->surface_id );
         goto out;
    }

    *ret_surface = surface;

out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ICoreRequestor_ClipboardSet(ICore *thiz,
                    const char                                *mime_type,
                    u32                                        mime_type_size,
                    const char                                *data,
                    u32                                        data_size,
                    u64                                        timestamp_us)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreDFBClipboardSet       *args = (CoreDFBClipboardSet*) args_alloc( args_static, sizeof(CoreDFBClipboardSet) + mime_type_size * sizeof(char) + data_size * sizeof(char) );
    CoreDFBClipboardSetReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreDFBClipboardSetReturn*) args_alloc( return_args_static, sizeof(CoreDFBClipboardSetReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreDFB, "ICoreRequesto_%s()\n", __FUNCTION__ );


    args->mime_type_size = mime_type_size;
    args->data_size = data_size;
    args->timestamp_us = timestamp_us;
    direct_memcpy( (char*) (args + 1), mime_type, mime_type_size * sizeof(char) );
    direct_memcpy( (char*) (args + 1) + mime_type_size * sizeof(char), data, data_size * sizeof(char) );

    ret = (DFBResult) CoreDFB_Call( thiz->obj, FCEF_NONE, CoreDFBCall_ClipboardSet, args, sizeof(CoreDFBClipboardSet) + mime_type_size * sizeof(char) + data_size * sizeof(char), return_args, sizeof(CoreDFBClipboardSetReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreDFB_Call( CoreDFB_ClipboardSet ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreDFB_ClipboardSet failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ICoreRequestor_ClipboardGet(ICore *thiz,
                    char                                      *ret_mime_type,
                    u32                                       *ret_mime_type_size,
                    char                                      *ret_data,
                    u32                                       *ret_data_size)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreDFBClipboardGet       *args = (CoreDFBClipboardGet*) args_alloc( args_static, sizeof(CoreDFBClipboardGet) );
    CoreDFBClipboardGetReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreDFBClipboardGetReturn*) args_alloc( return_args_static, sizeof(CoreDFBClipboardGetReturn) + MAX_CLIPBOARD_MIME_TYPE_SIZE * sizeof(char) + MAX_CLIPBOARD_DATA_SIZE * sizeof(char) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreDFB, "ICoreRequesto_%s()\n", __FUNCTION__ );



    ret = (DFBResult) CoreDFB_Call( thiz->obj, FCEF_NONE, CoreDFBCall_ClipboardGet, args, sizeof(CoreDFBClipboardGet), return_args, sizeof(CoreDFBClipboardGetReturn) + MAX_CLIPBOARD_MIME_TYPE_SIZE * sizeof(char) + MAX_CLIPBOARD_DATA_SIZE * sizeof(char), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreDFB_Call( CoreDFB_ClipboardGet ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreDFB_ClipboardGet failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

    *ret_mime_type_size = return_args->mime_type_size;
    *ret_data_size = return_args->data_size;
    direct_memcpy( ret_mime_type, (char*) (return_args + 1), return_args->mime_type_size * sizeof(char) );
    direct_memcpy( ret_data, (char*) (return_args + 1) + return_args->mime_type_size * sizeof(char), return_args->data_size * sizeof(char) );


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ICoreRequestor_ClipboardGetTimestamp(ICore *thiz, u64 *ret_timestamp_us)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreDFBClipboardGetTimestamp       *args = (CoreDFBClipboardGetTimestamp*) args_alloc( args_static, sizeof(CoreDFBClipboardGetTimestamp) );
    CoreDFBClipboardGetTimestampReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreDFBClipboardGetTimestampReturn*) args_alloc( return_args_static, sizeof(CoreDFBClipboardGetTimestampReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreDFB, "ICoreRequesto_%s()\n", __FUNCTION__ );



    ret = (DFBResult) CoreDFB_Call( thiz->obj, FCEF_NONE, CoreDFBCall_ClipboardGetTimestamp, args, sizeof(CoreDFBClipboardGetTimestamp), return_args, sizeof(CoreDFBClipboardGetTimestampReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreDFB_Call( CoreDFB_ClipboardGetTimestamp ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreDFB_ClipboardGetTimestamp failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

    *ret_timestamp_us = return_args->timestamp_us;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


void ICoreRequestorInit(ICoreRequestor *thiz, CoreDFB *core, CoreDFB *obj)
{
    thiz->base.core = core;
    thiz->base.obj = obj;

    thiz->base.Initialize = ICoreRequestor_Initialize;
    thiz->base.Register = ICoreRequestor_Register;
    thiz->base.CreateSurface = ICoreRequestor_CreateSurface;
    thiz->base.CreatePalette = ICoreRequestor_CreatePalette;
    thiz->base.CreateState = ICoreRequestor_CreateState;
    thiz->base.WaitIdle = ICoreRequestor_WaitIdle;
    thiz->base.CreateImageProvider = ICoreRequestor_CreateImageProvider;
    thiz->base.AllowSurface = ICoreRequestor_AllowSurface;
    thiz->base.GetSurface = ICoreRequestor_GetSurface;
    thiz->base.ClipboardSet = ICoreRequestor_ClipboardSet;
    thiz->base.ClipboardGet = ICoreRequestor_ClipboardGet;
    thiz->base.ClipboardGetTimestamp = ICoreRequestor_ClipboardGetTimestamp;
}

/*********************************************************************************************************************/

static DFBResult
__CoreDFBDispatch__Dispatch( CoreDFB *obj,
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

    ICoreReal real;
    ICore *super = (ICore *)&real;
    ICoreRealInit( &real, core_dfb, obj );


    switch (method) {
        case CoreDFBCall_Initialize: {
            D_UNUSED
            CoreDFBInitialize       *args        = (CoreDFBInitialize *) ptr;
            CoreDFBInitializeReturn *return_args = (CoreDFBInitializeReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreDFB, "=-> CoreDFB_Initialize\n" );

            return_args->result = super->Initialize( super );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreDFBInitializeReturn);

            return DFB_OK;
        }

        case CoreDFBCall_Register: {
            D_UNUSED
            CoreDFBRegister       *args        = (CoreDFBRegister *) ptr;
            CoreDFBRegisterReturn *return_args = (CoreDFBRegisterReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreDFB, "=-> CoreDFB_Register\n" );

            return_args->result = super->Register( super, args->slave_call );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreDFBRegisterReturn);

            return DFB_OK;
        }

        case CoreDFBCall_CreateSurface: {
            CorePalette *palette = NULL;
            CoreSurface *surface = NULL;
            D_UNUSED
            CoreDFBCreateSurface       *args        = (CoreDFBCreateSurface *) ptr;
            CoreDFBCreateSurfaceReturn *return_args = (CoreDFBCreateSurfaceReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreDFB, "=-> CoreDFB_CreateSurface\n" );

            if (args->palette_set) {
                ret = (DFBResult) CorePalette_Lookup( core_dfb, args->palette_id, caller, &palette );
                if (ret) {
                     D_DERROR( ret, "%s: Looking up palette by ID %u failed!\n", __FUNCTION__, args->palette_id );
                     return_args->result = ret;
                     return ret;
                }
            }

            return_args->result = super->CreateSurface( super, &args->config, args->type, args->resource_id, args->palette_set ? palette : NULL, &surface );
            if (return_args->result == DFB_OK) {
                CoreSurface_Throw( surface, caller, &return_args->surface_id );
                return_args->surface_ptr = (void*) surface;
            }

            *ret_length = sizeof(CoreDFBCreateSurfaceReturn);

            if (palette)
                CorePalette_Unref( palette );

            return DFB_OK;
        }

        case CoreDFBCall_CreatePalette: {
            CorePalette *palette = NULL;
            D_UNUSED
            CoreDFBCreatePalette       *args        = (CoreDFBCreatePalette *) ptr;
            CoreDFBCreatePaletteReturn *return_args = (CoreDFBCreatePaletteReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreDFB, "=-> CoreDFB_CreatePalette\n" );

            return_args->result = super->CreatePalette( super, args->size, &palette );
            if (return_args->result == DFB_OK) {
                CorePalette_Throw( palette, caller, &return_args->palette_id );
                return_args->palette_ptr = (void*) palette;
            }

            *ret_length = sizeof(CoreDFBCreatePaletteReturn);

            return DFB_OK;
        }

        case CoreDFBCall_CreateState: {
            CoreGraphicsState *state = NULL;
            D_UNUSED
            CoreDFBCreateState       *args        = (CoreDFBCreateState *) ptr;
            CoreDFBCreateStateReturn *return_args = (CoreDFBCreateStateReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreDFB, "=-> CoreDFB_CreateState\n" );

            return_args->result = super->CreateState( super, &state );
            if (return_args->result == DFB_OK) {
                CoreGraphicsState_Throw( state, caller, &return_args->state_id );
                return_args->state_ptr = (void*) state;
            }

            *ret_length = sizeof(CoreDFBCreateStateReturn);

            return DFB_OK;
        }

        case CoreDFBCall_WaitIdle: {
            D_UNUSED
            CoreDFBWaitIdle       *args        = (CoreDFBWaitIdle *) ptr;
            CoreDFBWaitIdleReturn *return_args = (CoreDFBWaitIdleReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreDFB, "=-> CoreDFB_WaitIdle\n" );

            return_args->result = super->WaitIdle( super );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreDFBWaitIdleReturn);

            return DFB_OK;
        }

        case CoreDFBCall_CreateImageProvider: {
            D_UNUSED
            CoreDFBCreateImageProvider       *args        = (CoreDFBCreateImageProvider *) ptr;
            CoreDFBCreateImageProviderReturn *return_args = (CoreDFBCreateImageProviderReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreDFB, "=-> CoreDFB_CreateImageProvider\n" );

            return_args->result = super->CreateImageProvider( super, args->buffer_call, &return_args->call );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreDFBCreateImageProviderReturn);

            return DFB_OK;
        }

        case CoreDFBCall_AllowSurface: {
            CoreSurface *surface = NULL;
            D_UNUSED
            CoreDFBAllowSurface       *args        = (CoreDFBAllowSurface *) ptr;
            CoreDFBAllowSurfaceReturn *return_args = (CoreDFBAllowSurfaceReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreDFB, "=-> CoreDFB_AllowSurface\n" );

            ret = (DFBResult) CoreSurface_Lookup( core_dfb, args->surface_id, caller, &surface );
            if (ret) {
                 D_DERROR( ret, "%s: Looking up surface by ID %u failed!\n", __FUNCTION__, args->surface_id );
                 return_args->result = ret;
                 return ret;
            }

            return_args->result = super->AllowSurface( super, surface, (char*) ((char*)(args + 1)), args->executable_length );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreDFBAllowSurfaceReturn);

            if (surface)
                CoreSurface_Unref( surface );

            return DFB_OK;
        }

        case CoreDFBCall_GetSurface: {
            CoreSurface *surface = NULL;
            D_UNUSED
            CoreDFBGetSurface       *args        = (CoreDFBGetSurface *) ptr;
            CoreDFBGetSurfaceReturn *return_args = (CoreDFBGetSurfaceReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreDFB, "=-> CoreDFB_GetSurface\n" );

            return_args->result = super->GetSurface( super, args->surface_id, &surface );
            if (return_args->result == DFB_OK) {
                CoreSurface_Throw( surface, caller, &return_args->surface_id );
                return_args->surface_ptr = (void*) surface;
            }

            *ret_length = sizeof(CoreDFBGetSurfaceReturn);

            return DFB_OK;
        }

        case CoreDFBCall_ClipboardSet: {
            D_UNUSED
            CoreDFBClipboardSet       *args        = (CoreDFBClipboardSet *) ptr;
            CoreDFBClipboardSetReturn *return_args = (CoreDFBClipboardSetReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreDFB, "=-> CoreDFB_ClipboardSet\n" );

            return_args->result = super->ClipboardSet( super, (char*) ((char*)(args + 1)), args->mime_type_size, (char*) ((char*)(args + 1) + args->mime_type_size * sizeof(char)), args->data_size, args->timestamp_us );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreDFBClipboardSetReturn);

            return DFB_OK;
        }

        case CoreDFBCall_ClipboardGet: {
            char  tmp_data[MAX_CLIPBOARD_DATA_SIZE];
            D_UNUSED
            CoreDFBClipboardGet       *args        = (CoreDFBClipboardGet *) ptr;
            CoreDFBClipboardGetReturn *return_args = (CoreDFBClipboardGetReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreDFB, "=-> CoreDFB_ClipboardGet\n" );

            return_args->result = super->ClipboardGet( super, (char*) ((char*)(return_args + 1)), &return_args->mime_type_size, tmp_data, &return_args->data_size );
            if (return_args->result == DFB_OK) {
                direct_memcpy( (char*) ((char*)(return_args + 1) + return_args->mime_type_size * sizeof(char)), tmp_data, return_args->data_size );
            }

            *ret_length = sizeof(CoreDFBClipboardGetReturn) + return_args->mime_type_size * sizeof(char) + return_args->data_size * sizeof(char);

            return DFB_OK;
        }

        case CoreDFBCall_ClipboardGetTimestamp: {
            D_UNUSED
            CoreDFBClipboardGetTimestamp       *args        = (CoreDFBClipboardGetTimestamp *) ptr;
            CoreDFBClipboardGetTimestampReturn *return_args = (CoreDFBClipboardGetTimestampReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreDFB, "=-> CoreDFB_ClipboardGetTimestamp\n" );

            return_args->result = super->ClipboardGetTimestamp( super, &return_args->timestamp_us );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreDFBClipboardGetTimestampReturn);

            return DFB_OK;
        }

    }

    return DFB_NOSUCHMETHOD;
}
/*********************************************************************************************************************/

DFBResult
CoreDFBDispatch__Dispatch( CoreDFB *obj,
                                FusionID      caller,
                                int           method,
                                void         *ptr,
                                unsigned int  length,
                                void         *ret_ptr,
                                unsigned int  ret_size,
                                unsigned int *ret_length )
{
    DFBResult ret = DFB_OK;

    D_DEBUG_AT( DirectFB_CoreDFB, "CoreDFBDispatch::%s( %p )\n", __FUNCTION__, obj );

    Core_PushIdentity( caller );

    ret = __CoreDFBDispatch__Dispatch( obj, caller, method, ptr, length, ret_ptr, ret_size, ret_length );

    Core_PopIdentity();

    return ret;
}

