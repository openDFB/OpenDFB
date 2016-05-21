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

#include "CoreSurface.h"

#include <directfb_util.h>
#include <direct/debug.h>
#include <direct/mem.h>
#include <direct/memcpy.h>
#include <direct/messages.h>
#include <fusion/conf.h>
#include <core/core.h>
#include <core/CoreDFB_CallMode.h>


D_DEBUG_DOMAIN( DirectFB_CoreSurface, "DirectFB/CoreSurface", "DirectFB CoreSurface" );

/*********************************************************************************************************************/

DFBResult
CoreSurface_SetConfig(
                    CoreSurface                               *obj,
                    const CoreSurfaceConfig                   *config
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            ISurfaceReal real;
			ISurface *super = (ISurface *)&real;
			ISurfaceRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetConfig( super, config );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            ISurfaceRequestor requestor;
			ISurface *super = (ISurface *)&requestor;
			ISurfaceRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetConfig( super, config );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreSurface_Flip(
                    CoreSurface                               *obj,
                    bool                                       swap
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            ISurfaceReal real;
			ISurface *super = (ISurface *)&real;
			ISurfaceRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->Flip( super, swap );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            ISurfaceRequestor requestor;
			ISurface *super = (ISurface *)&requestor;
			ISurfaceRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->Flip( super, swap );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreSurface_GetPalette(
                    CoreSurface                               *obj,
                    CorePalette                              **ret_palette
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            ISurfaceReal real;
			ISurface *super = (ISurface *)&real;
			ISurfaceRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->GetPalette( super, ret_palette );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            ISurfaceRequestor requestor;
			ISurface *super = (ISurface *)&requestor;
			ISurfaceRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->GetPalette( super, ret_palette );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreSurface_SetPalette(
                    CoreSurface                               *obj,
                    CorePalette                               *palette
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            ISurfaceReal real;
			ISurface *super = (ISurface *)&real;
			ISurfaceRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetPalette( super, palette );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            ISurfaceRequestor requestor;
			ISurface *super = (ISurface *)&requestor;
			ISurfaceRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetPalette( super, palette );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreSurface_SetAlphaRamp(
                    CoreSurface                               *obj,
                    u8                                         a0,
                    u8                                         a1,
                    u8                                         a2,
                    u8                                         a3
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            ISurfaceReal real;
			ISurface *super = (ISurface *)&real;
			ISurfaceRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetAlphaRamp( super, a0, a1, a2, a3 );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            ISurfaceRequestor requestor;
			ISurface *super = (ISurface *)&requestor;
			ISurfaceRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetAlphaRamp( super, a0, a1, a2, a3 );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreSurface_SetField(
                    CoreSurface                               *obj,
                    s32                                        field
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            ISurfaceReal real;
			ISurface *super = (ISurface *)&real;
			ISurfaceRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetField( super, field );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            ISurfaceRequestor requestor;
			ISurface *super = (ISurface *)&requestor;
			ISurfaceRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetField( super, field );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreSurface_PreLockBuffer(
                    CoreSurface                               *obj,
                    CoreSurfaceBuffer                         *buffer,
                    CoreSurfaceAccessorID                      accessor,
                    CoreSurfaceAccessFlags                     access,
                    CoreSurfaceAllocation                    **ret_allocation
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            ISurfaceReal real;
			ISurface *super = (ISurface *)&real;
			ISurfaceRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->PreLockBuffer( super, buffer, accessor, access, ret_allocation );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            ISurfaceRequestor requestor;
			ISurface *super = (ISurface *)&requestor;
			ISurfaceRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->PreLockBuffer( super, buffer, accessor, access, ret_allocation );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreSurface_PreLockBuffer2(
                    CoreSurface                               *obj,
                    CoreSurfaceBufferRole                      role,
                    DFBSurfaceStereoEye                        eye,
                    CoreSurfaceAccessorID                      accessor,
                    CoreSurfaceAccessFlags                     access,
                    bool                                       lock,
                    CoreSurfaceAllocation                    **ret_allocation
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            ISurfaceReal real;
			ISurface *super = (ISurface *)&real;
			ISurfaceRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->PreLockBuffer2( super, role, eye, accessor, access, lock, ret_allocation );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            ISurfaceRequestor requestor;
			ISurface *super = (ISurface *)&requestor;
			ISurfaceRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->PreLockBuffer2( super, role, eye, accessor, access, lock, ret_allocation );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreSurface_PreReadBuffer(
                    CoreSurface                               *obj,
                    CoreSurfaceBuffer                         *buffer,
                    const DFBRectangle                        *rect,
                    CoreSurfaceAllocation                    **ret_allocation
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            ISurfaceReal real;
			ISurface *super = (ISurface *)&real;
			ISurfaceRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->PreReadBuffer( super, buffer, rect, ret_allocation );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            ISurfaceRequestor requestor;
			ISurface *super = (ISurface *)&requestor;
			ISurfaceRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->PreReadBuffer( super, buffer, rect, ret_allocation );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreSurface_PreWriteBuffer(
                    CoreSurface                               *obj,
                    CoreSurfaceBuffer                         *buffer,
                    const DFBRectangle                        *rect,
                    CoreSurfaceAllocation                    **ret_allocation
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            ISurfaceReal real;
			ISurface *super = (ISurface *)&real;
			ISurfaceRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->PreWriteBuffer( super, buffer, rect, ret_allocation );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            ISurfaceRequestor requestor;
			ISurface *super = (ISurface *)&requestor;
			ISurfaceRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->PreWriteBuffer( super, buffer, rect, ret_allocation );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreSurface_PreLockBuffer3(
                    CoreSurface                               *obj,
                    CoreSurfaceBufferRole                      role,
                    u32                                        flip_count,
                    DFBSurfaceStereoEye                        eye,
                    CoreSurfaceAccessorID                      accessor,
                    CoreSurfaceAccessFlags                     access,
                    bool                                       lock,
                    CoreSurfaceAllocation                    **ret_allocation
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            ISurfaceReal real;
			ISurface *super = (ISurface *)&real;
			ISurfaceRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->PreLockBuffer3( super, role, flip_count, eye, accessor, access, lock, ret_allocation );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            ISurfaceRequestor requestor;
			ISurface *super = (ISurface *)&requestor;
			ISurfaceRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->PreLockBuffer3( super, role, flip_count, eye, accessor, access, lock, ret_allocation );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreSurface_CreateClient(
                    CoreSurface                               *obj,
                    CoreSurfaceClient                        **ret_client
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            ISurfaceReal real;
			ISurface *super = (ISurface *)&real;
			ISurfaceRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->CreateClient( super, ret_client );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            ISurfaceRequestor requestor;
			ISurface *super = (ISurface *)&requestor;
			ISurfaceRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->CreateClient( super, ret_client );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreSurface_BackToFrontCopy(
                    CoreSurface                               *obj,
                    DFBSurfaceStereoEye                        eye,
                    const DFBRegion                           *left_region,
                    const DFBRegion                           *right_region
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            ISurfaceReal real;
			ISurface *super = (ISurface *)&real;
			ISurfaceRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->BackToFrontCopy( super, eye, left_region, right_region );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            ISurfaceRequestor requestor;
			ISurface *super = (ISurface *)&requestor;
			ISurfaceRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->BackToFrontCopy( super, eye, left_region, right_region );
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
CoreSurface_Dispatch( int           caller,   /* fusion id of the caller */
                     int           call_arg, /* optional call parameter */
                     void         *ptr, /* optional call parameter */
                     unsigned int  length,
                     void         *ctx,      /* optional handler context */
                     unsigned int  serial,
                     void         *ret_ptr,
                     unsigned int  ret_size,
                     unsigned int *ret_length )
{
    CoreSurface *obj = (CoreSurface*) ctx;
    CoreSurfaceDispatch__Dispatch( obj, caller, call_arg, ptr, length, ret_ptr, ret_size, ret_length );

    return FCHR_RETURN;
}

void CoreSurface_Init_Dispatch(
                    CoreDFB              *core,
                    CoreSurface          *obj,
                    FusionCall           *call
)
{
    fusion_call_init3( call, CoreSurface_Dispatch, obj, core->world );
}

void  CoreSurface_Deinit_Dispatch(
                    FusionCall           *call
)
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
ISurfaceRequestor_SetConfig(ISurface *thiz,
                    const CoreSurfaceConfig                   *config)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreSurfaceSetConfig       *args = (CoreSurfaceSetConfig*) args_alloc( args_static, sizeof(CoreSurfaceSetConfig) );
    CoreSurfaceSetConfigReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreSurfaceSetConfigReturn*) args_alloc( return_args_static, sizeof(CoreSurfaceSetConfigReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreSurface, "ISurfaceRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( config != NULL );

    args->config = *config;

    ret = (DFBResult) CoreSurface_Call( thiz->obj, FCEF_NONE, CoreSurfaceCall_SetConfig, args, sizeof(CoreSurfaceSetConfig), return_args, sizeof(CoreSurfaceSetConfigReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreSurface_Call( CoreSurface_SetConfig ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreSurface_SetConfig failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ISurfaceRequestor_Flip(ISurface *thiz,
                    bool                                       swap
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreSurfaceFlip       *args = (CoreSurfaceFlip*) args_alloc( args_static, sizeof(CoreSurfaceFlip) );
    CoreSurfaceFlipReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreSurfaceFlipReturn*) args_alloc( return_args_static, sizeof(CoreSurfaceFlipReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreSurface, "ISurfaceRequestor_%s()\n", __FUNCTION__ );


    args->swap = swap;

    ret = (DFBResult) CoreSurface_Call( thiz->obj, FCEF_NONE, CoreSurfaceCall_Flip, args, sizeof(CoreSurfaceFlip), return_args, sizeof(CoreSurfaceFlipReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreSurface_Call( CoreSurface_Flip ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreSurface_Flip failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ISurfaceRequestor_GetPalette(ISurface *thiz,
                    CorePalette                              **ret_palette
)
{
    DFBResult           ret = DFB_OK;
    CorePalette *palette = NULL;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreSurfaceGetPalette       *args = (CoreSurfaceGetPalette*) args_alloc( args_static, sizeof(CoreSurfaceGetPalette) );
    CoreSurfaceGetPaletteReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreSurfaceGetPaletteReturn*) args_alloc( return_args_static, sizeof(CoreSurfaceGetPaletteReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreSurface, "ISurfaceRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( ret_palette != NULL );


    ret = (DFBResult) CoreSurface_Call( thiz->obj, FCEF_NONE, CoreSurfaceCall_GetPalette, args, sizeof(CoreSurfaceGetPalette), return_args, sizeof(CoreSurfaceGetPaletteReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreSurface_Call( CoreSurface_GetPalette ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreSurface_GetPalette failed!\n", __FUNCTION__ );*/
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
ISurfaceRequestor_SetPalette(ISurface *thiz,
                    CorePalette                               *palette
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreSurfaceSetPalette       *args = (CoreSurfaceSetPalette*) args_alloc( args_static, sizeof(CoreSurfaceSetPalette) );
    CoreSurfaceSetPaletteReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreSurfaceSetPaletteReturn*) args_alloc( return_args_static, sizeof(CoreSurfaceSetPaletteReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreSurface, "ISurfaceRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( palette != NULL );

    args->palette_id = CorePalette_GetID( palette );

    ret = (DFBResult) CoreSurface_Call( thiz->obj, FCEF_NONE, CoreSurfaceCall_SetPalette, args, sizeof(CoreSurfaceSetPalette), return_args, sizeof(CoreSurfaceSetPaletteReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreSurface_Call( CoreSurface_SetPalette ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreSurface_SetPalette failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ISurfaceRequestor_SetAlphaRamp(ISurface *thiz,
                    u8                                         a0,
                    u8                                         a1,
                    u8                                         a2,
                    u8                                         a3
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreSurfaceSetAlphaRamp       *args = (CoreSurfaceSetAlphaRamp*) args_alloc( args_static, sizeof(CoreSurfaceSetAlphaRamp) );
    CoreSurfaceSetAlphaRampReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreSurfaceSetAlphaRampReturn*) args_alloc( return_args_static, sizeof(CoreSurfaceSetAlphaRampReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreSurface, "ISurfaceRequestor_%s()\n", __FUNCTION__ );


    args->a0 = a0;
    args->a1 = a1;
    args->a2 = a2;
    args->a3 = a3;

    ret = (DFBResult) CoreSurface_Call( thiz->obj, FCEF_NONE, CoreSurfaceCall_SetAlphaRamp, args, sizeof(CoreSurfaceSetAlphaRamp), return_args, sizeof(CoreSurfaceSetAlphaRampReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreSurface_Call( CoreSurface_SetAlphaRamp ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreSurface_SetAlphaRamp failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ISurfaceRequestor_SetField(ISurface *thiz,
                    s32                                        field
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreSurfaceSetField       *args = (CoreSurfaceSetField*) args_alloc( args_static, sizeof(CoreSurfaceSetField) );
    CoreSurfaceSetFieldReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreSurfaceSetFieldReturn*) args_alloc( return_args_static, sizeof(CoreSurfaceSetFieldReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreSurface, "ISurface_Requestor::%s()\n", __FUNCTION__ );


    args->field = field;

    ret = (DFBResult) CoreSurface_Call( thiz->obj, FCEF_NONE, CoreSurfaceCall_SetField, args, sizeof(CoreSurfaceSetField), return_args, sizeof(CoreSurfaceSetFieldReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreSurface_Call( CoreSurface_SetField ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreSurface_SetField failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ISurfaceRequestor_PreLockBuffer(ISurface *thiz,
                    CoreSurfaceBuffer                         *buffer,
                    CoreSurfaceAccessorID                      accessor,
                    CoreSurfaceAccessFlags                     access,
                    CoreSurfaceAllocation                    **ret_allocation
)
{
    DFBResult           ret = DFB_OK;
    CoreSurfaceAllocation *allocation = NULL;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreSurfacePreLockBuffer       *args = (CoreSurfacePreLockBuffer*) args_alloc( args_static, sizeof(CoreSurfacePreLockBuffer) );
    CoreSurfacePreLockBufferReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreSurfacePreLockBufferReturn*) args_alloc( return_args_static, sizeof(CoreSurfacePreLockBufferReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreSurface, "ISurface_Requestor::%s()\n", __FUNCTION__ );

    D_ASSERT( buffer != NULL );
    D_ASSERT( ret_allocation != NULL );

    args->buffer_id = CoreSurfaceBuffer_GetID( buffer );
    args->accessor = accessor;
    args->access = access;

    ret = (DFBResult) CoreSurface_Call( thiz->obj, FCEF_NONE, CoreSurfaceCall_PreLockBuffer, args, sizeof(CoreSurfacePreLockBuffer), return_args, sizeof(CoreSurfacePreLockBufferReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreSurface_Call( CoreSurface_PreLockBuffer ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreSurface_PreLockBuffer failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }


    ret = (DFBResult) CoreSurfaceAllocation_Catch( thiz->core, return_args->allocation_ptr, &allocation );
    if (ret) {
         D_DERROR( ret, "%s: Catching allocation by ID %u failed!\n", __FUNCTION__, return_args->allocation_id );
         goto out;
    }

    *ret_allocation = allocation;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ISurfaceRequestor_PreLockBuffer2(ISurface *thiz,
                    CoreSurfaceBufferRole                      role,
                    DFBSurfaceStereoEye                        eye,
                    CoreSurfaceAccessorID                      accessor,
                    CoreSurfaceAccessFlags                     access,
                    bool                                       lock,
                    CoreSurfaceAllocation                    **ret_allocation
)
{
    DFBResult           ret = DFB_OK;
    CoreSurfaceAllocation *allocation = NULL;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreSurfacePreLockBuffer2       *args = (CoreSurfacePreLockBuffer2*) args_alloc( args_static, sizeof(CoreSurfacePreLockBuffer2) );
    CoreSurfacePreLockBuffer2Return *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreSurfacePreLockBuffer2Return*) args_alloc( return_args_static, sizeof(CoreSurfacePreLockBuffer2Return) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreSurface, "ISurface_Requestor::%s()\n", __FUNCTION__ );

    D_ASSERT( ret_allocation != NULL );

    args->role = role;
    args->eye = eye;
    args->accessor = accessor;
    args->access = access;
    args->lock = lock;

    ret = (DFBResult) CoreSurface_Call( thiz->obj, FCEF_NONE, CoreSurfaceCall_PreLockBuffer2, args, sizeof(CoreSurfacePreLockBuffer2), return_args, sizeof(CoreSurfacePreLockBuffer2Return), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreSurface_Call( CoreSurface_PreLockBuffer2 ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreSurface_PreLockBuffer2 failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }


    ret = (DFBResult) CoreSurfaceAllocation_Catch( thiz->core, return_args->allocation_ptr, &allocation );
    if (ret) {
         D_DERROR( ret, "%s: Catching allocation by ID %u failed!\n", __FUNCTION__, return_args->allocation_id );
         goto out;
    }

    *ret_allocation = allocation;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ISurfaceRequestor_PreReadBuffer(ISurface *thiz,
                    CoreSurfaceBuffer                         *buffer,
                    const DFBRectangle                        *rect,
                    CoreSurfaceAllocation                    **ret_allocation
)
{
    DFBResult           ret = DFB_OK;
    CoreSurfaceAllocation *allocation = NULL;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreSurfacePreReadBuffer       *args = (CoreSurfacePreReadBuffer*) args_alloc( args_static, sizeof(CoreSurfacePreReadBuffer) );
    CoreSurfacePreReadBufferReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreSurfacePreReadBufferReturn*) args_alloc( return_args_static, sizeof(CoreSurfacePreReadBufferReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreSurface, "ISurface_Requestor::%s()\n", __FUNCTION__ );

    D_ASSERT( buffer != NULL );
    D_ASSERT( rect != NULL );
    D_ASSERT( ret_allocation != NULL );

    args->buffer_id = CoreSurfaceBuffer_GetID( buffer );
    args->rect = *rect;

    ret = (DFBResult) CoreSurface_Call( thiz->obj, FCEF_NONE, CoreSurfaceCall_PreReadBuffer, args, sizeof(CoreSurfacePreReadBuffer), return_args, sizeof(CoreSurfacePreReadBufferReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreSurface_Call( CoreSurface_PreReadBuffer ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreSurface_PreReadBuffer failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }


    ret = (DFBResult) CoreSurfaceAllocation_Catch( thiz->core, return_args->allocation_ptr, &allocation );
    if (ret) {
         D_DERROR( ret, "%s: Catching allocation by ID %u failed!\n", __FUNCTION__, return_args->allocation_id );
         goto out;
    }

    *ret_allocation = allocation;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ISurfaceRequestor_PreWriteBuffer(ISurface *thiz,
                    CoreSurfaceBuffer                         *buffer,
                    const DFBRectangle                        *rect,
                    CoreSurfaceAllocation                    **ret_allocation
)
{
    DFBResult           ret = DFB_OK;
    CoreSurfaceAllocation *allocation = NULL;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreSurfacePreWriteBuffer       *args = (CoreSurfacePreWriteBuffer*) args_alloc( args_static, sizeof(CoreSurfacePreWriteBuffer) );
    CoreSurfacePreWriteBufferReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreSurfacePreWriteBufferReturn*) args_alloc( return_args_static, sizeof(CoreSurfacePreWriteBufferReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreSurface, "ISurface_Requestor::%s()\n", __FUNCTION__ );

    D_ASSERT( buffer != NULL );
    D_ASSERT( rect != NULL );
    D_ASSERT( ret_allocation != NULL );

    args->buffer_id = CoreSurfaceBuffer_GetID( buffer );
    args->rect = *rect;

    ret = (DFBResult) CoreSurface_Call( thiz->obj, FCEF_NONE, CoreSurfaceCall_PreWriteBuffer, args, sizeof(CoreSurfacePreWriteBuffer), return_args, sizeof(CoreSurfacePreWriteBufferReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreSurface_Call( CoreSurface_PreWriteBuffer ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreSurface_PreWriteBuffer failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }


    ret = (DFBResult) CoreSurfaceAllocation_Catch( thiz->core, return_args->allocation_ptr, &allocation );
    if (ret) {
         D_DERROR( ret, "%s: Catching allocation by ID %u failed!\n", __FUNCTION__, return_args->allocation_id );
         goto out;
    }

    *ret_allocation = allocation;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ISurfaceRequestor_PreLockBuffer3(ISurface *thiz,
                    CoreSurfaceBufferRole                      role,
                    u32                                        flip_count,
                    DFBSurfaceStereoEye                        eye,
                    CoreSurfaceAccessorID                      accessor,
                    CoreSurfaceAccessFlags                     access,
                    bool                                       lock,
                    CoreSurfaceAllocation                    **ret_allocation
)
{
    DFBResult           ret = DFB_OK;
    CoreSurfaceAllocation *allocation = NULL;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreSurfacePreLockBuffer3       *args = (CoreSurfacePreLockBuffer3*) args_alloc( args_static, sizeof(CoreSurfacePreLockBuffer3) );
    CoreSurfacePreLockBuffer3Return *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreSurfacePreLockBuffer3Return*) args_alloc( return_args_static, sizeof(CoreSurfacePreLockBuffer3Return) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreSurface, "ISurface_Requestor::%s()\n", __FUNCTION__ );

    D_ASSERT( ret_allocation != NULL );

    args->role = role;
    args->flip_count = flip_count;
    args->eye = eye;
    args->accessor = accessor;
    args->access = access;
    args->lock = lock;

    ret = (DFBResult) CoreSurface_Call( thiz->obj, FCEF_NONE, CoreSurfaceCall_PreLockBuffer3, args, sizeof(CoreSurfacePreLockBuffer3), return_args, sizeof(CoreSurfacePreLockBuffer3Return), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreSurface_Call( CoreSurface_PreLockBuffer3 ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreSurface_PreLockBuffer3 failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }


    ret = (DFBResult) CoreSurfaceAllocation_Catch( thiz->core, return_args->allocation_ptr, &allocation );
    if (ret) {
         D_DERROR( ret, "%s: Catching allocation by ID %u failed!\n", __FUNCTION__, return_args->allocation_id );
         goto out;
    }

    *ret_allocation = allocation;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ISurfaceRequestor_CreateClient(ISurface *thiz,
                    CoreSurfaceClient                        **ret_client
)
{
    DFBResult           ret = DFB_OK;
    CoreSurfaceClient *client = NULL;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreSurfaceCreateClient       *args = (CoreSurfaceCreateClient*) args_alloc( args_static, sizeof(CoreSurfaceCreateClient) );
    CoreSurfaceCreateClientReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreSurfaceCreateClientReturn*) args_alloc( return_args_static, sizeof(CoreSurfaceCreateClientReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreSurface, "ISurface_Requestor::%s()\n", __FUNCTION__ );

    D_ASSERT( ret_client != NULL );


    ret = (DFBResult) CoreSurface_Call( thiz->obj, FCEF_NONE, CoreSurfaceCall_CreateClient, args, sizeof(CoreSurfaceCreateClient), return_args, sizeof(CoreSurfaceCreateClientReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreSurface_Call( CoreSurface_CreateClient ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreSurface_CreateClient failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }


    ret = (DFBResult) CoreSurfaceClient_Catch( thiz->core, return_args->client_ptr, &client );
    if (ret) {
         D_DERROR( ret, "%s: Catching client by ID %u failed!\n", __FUNCTION__, return_args->client_id );
         goto out;
    }

    *ret_client = client;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ISurfaceRequestor_BackToFrontCopy(ISurface *thiz,
                    DFBSurfaceStereoEye                        eye,
                    const DFBRegion                           *left_region,
                    const DFBRegion                           *right_region
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreSurfaceBackToFrontCopy       *args = (CoreSurfaceBackToFrontCopy*) args_alloc( args_static, sizeof(CoreSurfaceBackToFrontCopy) );
    CoreSurfaceBackToFrontCopyReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreSurfaceBackToFrontCopyReturn*) args_alloc( return_args_static, sizeof(CoreSurfaceBackToFrontCopyReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreSurface, "ISurface_Requestor::%s()\n", __FUNCTION__ );


    args->eye = eye;
  if (left_region) {
    args->left_region = *left_region;
    args->left_region_set = true;
  }
  else
    args->left_region_set = false;
  if (right_region) {
    args->right_region = *right_region;
    args->right_region_set = true;
  }
  else
    args->right_region_set = false;

    ret = (DFBResult) CoreSurface_Call( thiz->obj, FCEF_NONE, CoreSurfaceCall_BackToFrontCopy, args, sizeof(CoreSurfaceBackToFrontCopy), return_args, sizeof(CoreSurfaceBackToFrontCopyReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreSurface_Call( CoreSurface_BackToFrontCopy ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreSurface_BackToFrontCopy failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}

void ISurfaceRequestorInit(ISurfaceRequestor *thiz, CoreDFB *core, CoreSurface *obj)
{
	thiz->base.core = core;
	thiz->base.obj = obj;

	thiz->base.SetConfig = ISurfaceRequestor_SetConfig;
	thiz->base.Flip = ISurfaceRequestor_Flip;
	thiz->base.GetPalette = ISurfaceRequestor_GetPalette;
	thiz->base.SetPalette = ISurfaceRequestor_SetPalette;
	thiz->base.SetAlphaRamp = ISurfaceRequestor_SetAlphaRamp;
	thiz->base.SetField = ISurfaceRequestor_SetField;
	thiz->base.PreLockBuffer = ISurfaceRequestor_PreLockBuffer;
	thiz->base.PreLockBuffer2 = ISurfaceRequestor_PreLockBuffer2;
	thiz->base.PreReadBuffer = ISurfaceRequestor_PreReadBuffer;
	thiz->base.PreWriteBuffer = ISurfaceRequestor_PreWriteBuffer;
	thiz->base.PreLockBuffer3 = ISurfaceRequestor_PreLockBuffer3;
	thiz->base.CreateClient = ISurfaceRequestor_CreateClient;
	thiz->base.BackToFrontCopy = ISurfaceRequestor_BackToFrontCopy;
}

/*********************************************************************************************************************/

static DFBResult
__CoreSurfaceDispatch__Dispatch( CoreSurface *obj,
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

	ISurfaceReal real;
	ISurface *super = (ISurface *)&real;
	ISurfaceRealInit( &real, core_dfb, obj );

    switch (method) {
        case CoreSurfaceCall_SetConfig: {
            D_UNUSED
            CoreSurfaceSetConfig       *args        = (CoreSurfaceSetConfig *) ptr;
            CoreSurfaceSetConfigReturn *return_args = (CoreSurfaceSetConfigReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreSurface, "=-> CoreSurface_SetConfig\n" );

            return_args->result = super->SetConfig( super, &args->config );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreSurfaceSetConfigReturn);

            return DFB_OK;
        }

        case CoreSurfaceCall_Flip: {
            D_UNUSED
            CoreSurfaceFlip       *args        = (CoreSurfaceFlip *) ptr;
            CoreSurfaceFlipReturn *return_args = (CoreSurfaceFlipReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreSurface, "=-> CoreSurface_Flip\n" );

            return_args->result = super->Flip( super, args->swap );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreSurfaceFlipReturn);

            return DFB_OK;
        }

        case CoreSurfaceCall_GetPalette: {
    CorePalette *palette = NULL;
            D_UNUSED
            CoreSurfaceGetPalette       *args        = (CoreSurfaceGetPalette *) ptr;
            CoreSurfaceGetPaletteReturn *return_args = (CoreSurfaceGetPaletteReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreSurface, "=-> CoreSurface_GetPalette\n" );

            return_args->result = super->GetPalette( super, &palette );
            if (return_args->result == DFB_OK) {
                CorePalette_Throw( palette, caller, &return_args->palette_id );
                return_args->palette_ptr = (void*) palette;
            }

            *ret_length = sizeof(CoreSurfaceGetPaletteReturn);

            return DFB_OK;
        }

        case CoreSurfaceCall_SetPalette: {
    CorePalette *palette = NULL;
            D_UNUSED
            CoreSurfaceSetPalette       *args        = (CoreSurfaceSetPalette *) ptr;
            CoreSurfaceSetPaletteReturn *return_args = (CoreSurfaceSetPaletteReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreSurface, "=-> CoreSurface_SetPalette\n" );

            ret = (DFBResult) CorePalette_Lookup( core_dfb, args->palette_id, caller, &palette );
            if (ret) {
                 D_DERROR( ret, "%s: Looking up palette by ID %u failed!\n", __FUNCTION__, args->palette_id );
                 return_args->result = ret;
                 return ret;
            }

            return_args->result = super->SetPalette( super, palette );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreSurfaceSetPaletteReturn);

            if (palette)
                CorePalette_Unref( palette );

            return DFB_OK;
        }

        case CoreSurfaceCall_SetAlphaRamp: {
            D_UNUSED
            CoreSurfaceSetAlphaRamp       *args        = (CoreSurfaceSetAlphaRamp *) ptr;
            CoreSurfaceSetAlphaRampReturn *return_args = (CoreSurfaceSetAlphaRampReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreSurface, "=-> CoreSurface_SetAlphaRamp\n" );

            return_args->result = super->SetAlphaRamp( super, args->a0, args->a1, args->a2, args->a3 );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreSurfaceSetAlphaRampReturn);

            return DFB_OK;
        }

        case CoreSurfaceCall_SetField: {
            D_UNUSED
            CoreSurfaceSetField       *args        = (CoreSurfaceSetField *) ptr;
            CoreSurfaceSetFieldReturn *return_args = (CoreSurfaceSetFieldReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreSurface, "=-> CoreSurface_SetField\n" );

            return_args->result = super->SetField( super, args->field );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreSurfaceSetFieldReturn);

            return DFB_OK;
        }

        case CoreSurfaceCall_PreLockBuffer: {
    CoreSurfaceBuffer *buffer = NULL;
    CoreSurfaceAllocation *allocation = NULL;
            D_UNUSED
            CoreSurfacePreLockBuffer       *args        = (CoreSurfacePreLockBuffer *) ptr;
            CoreSurfacePreLockBufferReturn *return_args = (CoreSurfacePreLockBufferReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreSurface, "=-> CoreSurface_PreLockBuffer\n" );

            ret = (DFBResult) CoreSurfaceBuffer_Lookup( core_dfb, args->buffer_id, caller, &buffer );
            if (ret) {
                 D_DERROR( ret, "%s: Looking up buffer by ID %u failed!\n", __FUNCTION__, args->buffer_id );
                 return_args->result = ret;
                 return ret;
            }

            return_args->result = super->PreLockBuffer( super, buffer, args->accessor, args->access, &allocation );
            if (return_args->result == DFB_OK) {
                CoreSurfaceAllocation_Throw( allocation, caller, &return_args->allocation_id );
                return_args->allocation_ptr = (void*) allocation;
            }

            *ret_length = sizeof(CoreSurfacePreLockBufferReturn);

            if (buffer)
                CoreSurfaceBuffer_Unref( buffer );

            return DFB_OK;
        }

        case CoreSurfaceCall_PreLockBuffer2: {
    CoreSurfaceAllocation *allocation = NULL;
            D_UNUSED
            CoreSurfacePreLockBuffer2       *args        = (CoreSurfacePreLockBuffer2 *) ptr;
            CoreSurfacePreLockBuffer2Return *return_args = (CoreSurfacePreLockBuffer2Return *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreSurface, "=-> CoreSurface_PreLockBuffer2\n" );

            return_args->result = super->PreLockBuffer2( super, args->role, args->eye, args->accessor, args->access, args->lock, &allocation );
            if (return_args->result == DFB_OK) {
                CoreSurfaceAllocation_Throw( allocation, caller, &return_args->allocation_id );
                return_args->allocation_ptr = (void*) allocation;
            }

            *ret_length = sizeof(CoreSurfacePreLockBuffer2Return);

            return DFB_OK;
        }

        case CoreSurfaceCall_PreReadBuffer: {
    CoreSurfaceBuffer *buffer = NULL;
    CoreSurfaceAllocation *allocation = NULL;
            D_UNUSED
            CoreSurfacePreReadBuffer       *args        = (CoreSurfacePreReadBuffer *) ptr;
            CoreSurfacePreReadBufferReturn *return_args = (CoreSurfacePreReadBufferReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreSurface, "=-> CoreSurface_PreReadBuffer\n" );

            ret = (DFBResult) CoreSurfaceBuffer_Lookup( core_dfb, args->buffer_id, caller, &buffer );
            if (ret) {
                 D_DERROR( ret, "%s: Looking up buffer by ID %u failed!\n", __FUNCTION__, args->buffer_id );
                 return_args->result = ret;
                 return ret;
            }

            return_args->result = super->PreReadBuffer( super, buffer, &args->rect, &allocation );
            if (return_args->result == DFB_OK) {
                CoreSurfaceAllocation_Throw( allocation, caller, &return_args->allocation_id );
                return_args->allocation_ptr = (void*) allocation;
            }

            *ret_length = sizeof(CoreSurfacePreReadBufferReturn);

            if (buffer)
                CoreSurfaceBuffer_Unref( buffer );

            return DFB_OK;
        }

        case CoreSurfaceCall_PreWriteBuffer: {
    CoreSurfaceBuffer *buffer = NULL;
    CoreSurfaceAllocation *allocation = NULL;
            D_UNUSED
            CoreSurfacePreWriteBuffer       *args        = (CoreSurfacePreWriteBuffer *) ptr;
            CoreSurfacePreWriteBufferReturn *return_args = (CoreSurfacePreWriteBufferReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreSurface, "=-> CoreSurface_PreWriteBuffer\n" );

            ret = (DFBResult) CoreSurfaceBuffer_Lookup( core_dfb, args->buffer_id, caller, &buffer );
            if (ret) {
                 D_DERROR( ret, "%s: Looking up buffer by ID %u failed!\n", __FUNCTION__, args->buffer_id );
                 return_args->result = ret;
                 return ret;
            }

            return_args->result = super->PreWriteBuffer( super, buffer, &args->rect, &allocation );
            if (return_args->result == DFB_OK) {
                CoreSurfaceAllocation_Throw( allocation, caller, &return_args->allocation_id );
                return_args->allocation_ptr = (void*) allocation;
            }

            *ret_length = sizeof(CoreSurfacePreWriteBufferReturn);

            if (buffer)
                CoreSurfaceBuffer_Unref( buffer );

            return DFB_OK;
        }

        case CoreSurfaceCall_PreLockBuffer3: {
    CoreSurfaceAllocation *allocation = NULL;
            D_UNUSED
            CoreSurfacePreLockBuffer3       *args        = (CoreSurfacePreLockBuffer3 *) ptr;
            CoreSurfacePreLockBuffer3Return *return_args = (CoreSurfacePreLockBuffer3Return *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreSurface, "=-> CoreSurface_PreLockBuffer3\n" );

            return_args->result = super->PreLockBuffer3( super, args->role, args->flip_count, args->eye, args->accessor, args->access, args->lock, &allocation );
            if (return_args->result == DFB_OK) {
                CoreSurfaceAllocation_Throw( allocation, caller, &return_args->allocation_id );
                return_args->allocation_ptr = (void*) allocation;
            }

            *ret_length = sizeof(CoreSurfacePreLockBuffer3Return);

            return DFB_OK;
        }

        case CoreSurfaceCall_CreateClient: {
    CoreSurfaceClient *client = NULL;
            D_UNUSED
            CoreSurfaceCreateClient       *args        = (CoreSurfaceCreateClient *) ptr;
            CoreSurfaceCreateClientReturn *return_args = (CoreSurfaceCreateClientReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreSurface, "=-> CoreSurface_CreateClient\n" );

            return_args->result = super->CreateClient( super, &client );
            if (return_args->result == DFB_OK) {
                CoreSurfaceClient_Throw( client, caller, &return_args->client_id );
                return_args->client_ptr = (void*) client;
            }

            *ret_length = sizeof(CoreSurfaceCreateClientReturn);

            return DFB_OK;
        }

        case CoreSurfaceCall_BackToFrontCopy: {
            D_UNUSED
            CoreSurfaceBackToFrontCopy       *args        = (CoreSurfaceBackToFrontCopy *) ptr;
            CoreSurfaceBackToFrontCopyReturn *return_args = (CoreSurfaceBackToFrontCopyReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreSurface, "=-> CoreSurface_BackToFrontCopy\n" );

            return_args->result = super->BackToFrontCopy( super, args->eye, args->left_region_set ? &args->left_region : NULL, args->right_region_set ? &args->right_region : NULL );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreSurfaceBackToFrontCopyReturn);

            return DFB_OK;
        }

    }

    return DFB_NOSUCHMETHOD;
}
/*********************************************************************************************************************/

DFBResult
CoreSurfaceDispatch__Dispatch( CoreSurface *obj,
                                FusionID      caller,
                                int           method,
                                void         *ptr,
                                unsigned int  length,
                                void         *ret_ptr,
                                unsigned int  ret_size,
                                unsigned int *ret_length )
{
    DFBResult ret = DFB_OK;

    D_DEBUG_AT( DirectFB_CoreSurface, "CoreSurfaceDispatch::%s( %p )\n", __FUNCTION__, obj );

    Core_PushIdentity( caller );

    ret = __CoreSurfaceDispatch__Dispatch( obj, caller, method, ptr, length, ret_ptr, ret_size, ret_length );

    Core_PopIdentity();

    return ret;
}

