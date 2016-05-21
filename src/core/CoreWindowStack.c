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

#include "CoreWindowStack.h"
#include <directfb_util.h>

#include <direct/debug.h>
#include <direct/mem.h>
#include <direct/memcpy.h>
#include <direct/messages.h>

#include <fusion/conf.h>

#include <core/core.h>

#include <core/CoreDFB_CallMode.h>

D_DEBUG_DOMAIN( DirectFB_CoreWindowStack, "DirectFB/CoreWindowStack", "DirectFB CoreWindowStack" );

/*********************************************************************************************************************/

DFBResult
CoreWindowStack_RepaintAll(
                    CoreWindowStack                           *obj

)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IWindowStackReal real;
			IWindowStack *super = (IWindowStack *)&real;
			IWindowStackRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->RepaintAll( super );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IWindowStackRequestor requestor;
			IWindowStack *super = (IWindowStack *)&requestor;
			IWindowStackRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->RepaintAll( super );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindowStack_CursorEnable(
                    CoreWindowStack                           *obj,
                    bool                                       enable
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IWindowStackReal real;
			IWindowStack *super = (IWindowStack *)&real;
			IWindowStackRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->CursorEnable( super, enable );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IWindowStackRequestor requestor;
			IWindowStack *super = (IWindowStack *)&requestor;
			IWindowStackRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->CursorEnable( super, enable );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindowStack_CursorSetShape(
                    CoreWindowStack                           *obj,
                    CoreSurface                               *shape,
                    const DFBPoint                            *hotspot
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IWindowStackReal real;
			IWindowStack *super = (IWindowStack *)&real;
			IWindowStackRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->CursorSetShape( super, shape, hotspot );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IWindowStackRequestor requestor;
			IWindowStack *super = (IWindowStack *)&requestor;
			IWindowStackRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->CursorSetShape( super, shape, hotspot );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindowStack_CursorSetOpacity(
                    CoreWindowStack                           *obj,
                    u8                                         opacity
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IWindowStackReal real;
			IWindowStack *super = (IWindowStack *)&real;
			IWindowStackRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->CursorSetOpacity( super, opacity );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IWindowStackRequestor requestor;
			IWindowStack *super = (IWindowStack *)&requestor;
			IWindowStackRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->CursorSetOpacity( super, opacity );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindowStack_CursorSetAcceleration(
                    CoreWindowStack                           *obj,
                    u32                                        numerator,
                    u32                                        denominator,
                    u32                                        threshold
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IWindowStackReal real;
			IWindowStack *super = (IWindowStack *)&real;
			IWindowStackRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->CursorSetAcceleration( super, numerator, denominator, threshold );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IWindowStackRequestor requestor;
			IWindowStack *super = (IWindowStack *)&requestor;
			IWindowStackRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->CursorSetAcceleration( super, numerator, denominator, threshold );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindowStack_CursorWarp(
                    CoreWindowStack                           *obj,
                    const DFBPoint                            *position
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IWindowStackReal real;
			IWindowStack *super = (IWindowStack *)&real;
			IWindowStackRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->CursorWarp( super, position );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IWindowStackRequestor requestor;
			IWindowStack *super = (IWindowStack *)&requestor;
			IWindowStackRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->CursorWarp( super, position );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindowStack_CursorGetPosition(
                    CoreWindowStack                           *obj,
                    DFBPoint                                  *ret_position
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IWindowStackReal real;
			IWindowStack *super = (IWindowStack *)&real;
			IWindowStackRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->CursorGetPosition( super, ret_position );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IWindowStackRequestor requestor;
			IWindowStack *super = (IWindowStack *)&requestor;
			IWindowStackRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->CursorGetPosition( super, ret_position );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindowStack_BackgroundSetMode(
                    CoreWindowStack                           *obj,
                    DFBDisplayLayerBackgroundMode              mode
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IWindowStackReal real;
			IWindowStack *super = (IWindowStack *)&real;
			IWindowStackRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->BackgroundSetMode( super, mode );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IWindowStackRequestor requestor;
			IWindowStack *super = (IWindowStack *)&requestor;
			IWindowStackRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->BackgroundSetMode( super, mode );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindowStack_BackgroundSetImage(
                    CoreWindowStack                           *obj,
                    CoreSurface                               *image
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IWindowStackReal real;
			IWindowStack *super = (IWindowStack *)&real;
			IWindowStackRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->BackgroundSetImage( super, image );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IWindowStackRequestor requestor;
			IWindowStack *super = (IWindowStack *)&requestor;
			IWindowStackRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->BackgroundSetImage( super, image );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindowStack_BackgroundSetColor(
                    CoreWindowStack                           *obj,
                    const DFBColor                            *color
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IWindowStackReal real;
			IWindowStack *super = (IWindowStack *)&real;
			IWindowStackRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->BackgroundSetColor( super, color );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IWindowStackRequestor requestor;
			IWindowStack *super = (IWindowStack *)&requestor;
			IWindowStackRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->BackgroundSetColor( super, color );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindowStack_BackgroundSetColorIndex(
                    CoreWindowStack                           *obj,
                    s32                                        index
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IWindowStackReal real;
			IWindowStack *super = (IWindowStack *)&real;
			IWindowStackRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->BackgroundSetColorIndex( super, index );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IWindowStackRequestor requestor;
			IWindowStack *super = (IWindowStack *)&requestor;
			IWindowStackRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->BackgroundSetColorIndex( super, index );
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
CoreWindowStack_Dispatch( int           caller,   /* fusion id of the caller */
                     int           call_arg, /* optional call parameter */
                     void         *ptr, /* optional call parameter */
                     unsigned int  length,
                     void         *ctx,      /* optional handler context */
                     unsigned int  serial,
                     void         *ret_ptr,
                     unsigned int  ret_size,
                     unsigned int *ret_length )
{
    CoreWindowStack *obj = (CoreWindowStack*) ctx;
    CoreWindowStackDispatch__Dispatch( obj, caller, call_arg, ptr, length, ret_ptr, ret_size, ret_length );

    return FCHR_RETURN;
}

void CoreWindowStack_Init_Dispatch(
                    CoreDFB              *core,
                    CoreWindowStack      *obj,
                    FusionCall           *call
)
{
    fusion_call_init3( call, CoreWindowStack_Dispatch, obj, core->world );
}

void  CoreWindowStack_Deinit_Dispatch(
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
IWindowStackRequestor_RepaintAll(IWindowStack *thiz

)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowStackRepaintAll       *args = (CoreWindowStackRepaintAll*) args_alloc( args_static, sizeof(CoreWindowStackRepaintAll) );
    CoreWindowStackRepaintAllReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowStackRepaintAllReturn*) args_alloc( return_args_static, sizeof(CoreWindowStackRepaintAllReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackRequestor_%s()\n", __FUNCTION__ );



    ret = (DFBResult) CoreWindowStack_Call( thiz->obj, FCEF_NONE, CoreWindowStackCall_RepaintAll, args, sizeof(CoreWindowStackRepaintAll), return_args, sizeof(CoreWindowStackRepaintAllReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindowStack_Call( CoreWindowStack_RepaintAll ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindowStack_RepaintAll failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowStackRequestor_CursorEnable(IWindowStack *thiz,
                    bool                                       enable
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowStackCursorEnable       *args = (CoreWindowStackCursorEnable*) args_alloc( args_static, sizeof(CoreWindowStackCursorEnable) );
    CoreWindowStackCursorEnableReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowStackCursorEnableReturn*) args_alloc( return_args_static, sizeof(CoreWindowStackCursorEnableReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackRequestor_%s()\n", __FUNCTION__ );


    args->enable = enable;

    ret = (DFBResult) CoreWindowStack_Call( thiz->obj, FCEF_NONE, CoreWindowStackCall_CursorEnable, args, sizeof(CoreWindowStackCursorEnable), return_args, sizeof(CoreWindowStackCursorEnableReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindowStack_Call( CoreWindowStack_CursorEnable ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindowStack_CursorEnable failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowStackRequestor_CursorSetShape(IWindowStack *thiz,
                    CoreSurface                               *shape,
                    const DFBPoint                            *hotspot
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowStackCursorSetShape       *args = (CoreWindowStackCursorSetShape*) args_alloc( args_static, sizeof(CoreWindowStackCursorSetShape) );
    CoreWindowStackCursorSetShapeReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowStackCursorSetShapeReturn*) args_alloc( return_args_static, sizeof(CoreWindowStackCursorSetShapeReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( shape != NULL );
    D_ASSERT( hotspot != NULL );

    args->shape_id = CoreSurface_GetID( shape );
    args->hotspot = *hotspot;

    ret = (DFBResult) CoreWindowStack_Call( thiz->obj, FCEF_NONE, CoreWindowStackCall_CursorSetShape, args, sizeof(CoreWindowStackCursorSetShape), return_args, sizeof(CoreWindowStackCursorSetShapeReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindowStack_Call( CoreWindowStack_CursorSetShape ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindowStack_CursorSetShape failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowStackRequestor_CursorSetOpacity(IWindowStack *thiz,
                    u8                                         opacity
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowStackCursorSetOpacity       *args = (CoreWindowStackCursorSetOpacity*) args_alloc( args_static, sizeof(CoreWindowStackCursorSetOpacity) );
    CoreWindowStackCursorSetOpacityReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowStackCursorSetOpacityReturn*) args_alloc( return_args_static, sizeof(CoreWindowStackCursorSetOpacityReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackRequestor_%s()\n", __FUNCTION__ );


    args->opacity = opacity;

    ret = (DFBResult) CoreWindowStack_Call( thiz->obj, FCEF_NONE, CoreWindowStackCall_CursorSetOpacity, args, sizeof(CoreWindowStackCursorSetOpacity), return_args, sizeof(CoreWindowStackCursorSetOpacityReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindowStack_Call( CoreWindowStack_CursorSetOpacity ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindowStack_CursorSetOpacity failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowStackRequestor_CursorSetAcceleration(IWindowStack *thiz,
                    u32                                        numerator,
                    u32                                        denominator,
                    u32                                        threshold
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowStackCursorSetAcceleration       *args = (CoreWindowStackCursorSetAcceleration*) args_alloc( args_static, sizeof(CoreWindowStackCursorSetAcceleration) );
    CoreWindowStackCursorSetAccelerationReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowStackCursorSetAccelerationReturn*) args_alloc( return_args_static, sizeof(CoreWindowStackCursorSetAccelerationReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackRequestor_%s()\n", __FUNCTION__ );


    args->numerator = numerator;
    args->denominator = denominator;
    args->threshold = threshold;

    ret = (DFBResult) CoreWindowStack_Call( thiz->obj, FCEF_NONE, CoreWindowStackCall_CursorSetAcceleration, args, sizeof(CoreWindowStackCursorSetAcceleration), return_args, sizeof(CoreWindowStackCursorSetAccelerationReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindowStack_Call( CoreWindowStack_CursorSetAcceleration ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindowStack_CursorSetAcceleration failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowStackRequestor_CursorWarp(IWindowStack *thiz,
                    const DFBPoint                            *position
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowStackCursorWarp       *args = (CoreWindowStackCursorWarp*) args_alloc( args_static, sizeof(CoreWindowStackCursorWarp) );
    CoreWindowStackCursorWarpReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowStackCursorWarpReturn*) args_alloc( return_args_static, sizeof(CoreWindowStackCursorWarpReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( position != NULL );

    args->position = *position;

    ret = (DFBResult) CoreWindowStack_Call( thiz->obj, FCEF_NONE, CoreWindowStackCall_CursorWarp, args, sizeof(CoreWindowStackCursorWarp), return_args, sizeof(CoreWindowStackCursorWarpReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindowStack_Call( CoreWindowStack_CursorWarp ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindowStack_CursorWarp failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowStackRequestor_CursorGetPosition(IWindowStack *thiz,
                    DFBPoint                                  *ret_position
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowStackCursorGetPosition       *args = (CoreWindowStackCursorGetPosition*) args_alloc( args_static, sizeof(CoreWindowStackCursorGetPosition) );
    CoreWindowStackCursorGetPositionReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowStackCursorGetPositionReturn*) args_alloc( return_args_static, sizeof(CoreWindowStackCursorGetPositionReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( ret_position != NULL );


    ret = (DFBResult) CoreWindowStack_Call( thiz->obj, FCEF_NONE, CoreWindowStackCall_CursorGetPosition, args, sizeof(CoreWindowStackCursorGetPosition), return_args, sizeof(CoreWindowStackCursorGetPositionReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindowStack_Call( CoreWindowStack_CursorGetPosition ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindowStack_CursorGetPosition failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

    *ret_position = return_args->position;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowStackRequestor_BackgroundSetMode(IWindowStack *thiz,
                    DFBDisplayLayerBackgroundMode              mode
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowStackBackgroundSetMode       *args = (CoreWindowStackBackgroundSetMode*) args_alloc( args_static, sizeof(CoreWindowStackBackgroundSetMode) );
    CoreWindowStackBackgroundSetModeReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowStackBackgroundSetModeReturn*) args_alloc( return_args_static, sizeof(CoreWindowStackBackgroundSetModeReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackRequestor_%s()\n", __FUNCTION__ );


    args->mode = mode;

    ret = (DFBResult) CoreWindowStack_Call( thiz->obj, FCEF_NONE, CoreWindowStackCall_BackgroundSetMode, args, sizeof(CoreWindowStackBackgroundSetMode), return_args, sizeof(CoreWindowStackBackgroundSetModeReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindowStack_Call( CoreWindowStack_BackgroundSetMode ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindowStack_BackgroundSetMode failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowStackRequestor_BackgroundSetImage(IWindowStack *thiz,
                    CoreSurface                               *image
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowStackBackgroundSetImage       *args = (CoreWindowStackBackgroundSetImage*) args_alloc( args_static, sizeof(CoreWindowStackBackgroundSetImage) );
    CoreWindowStackBackgroundSetImageReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowStackBackgroundSetImageReturn*) args_alloc( return_args_static, sizeof(CoreWindowStackBackgroundSetImageReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( image != NULL );

    args->image_id = CoreSurface_GetID( image );

    ret = (DFBResult) CoreWindowStack_Call( thiz->obj, FCEF_NONE, CoreWindowStackCall_BackgroundSetImage, args, sizeof(CoreWindowStackBackgroundSetImage), return_args, sizeof(CoreWindowStackBackgroundSetImageReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindowStack_Call( CoreWindowStack_BackgroundSetImage ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindowStack_BackgroundSetImage failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowStackRequestor_BackgroundSetColor(IWindowStack *thiz,
                    const DFBColor                            *color
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowStackBackgroundSetColor       *args = (CoreWindowStackBackgroundSetColor*) args_alloc( args_static, sizeof(CoreWindowStackBackgroundSetColor) );
    CoreWindowStackBackgroundSetColorReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowStackBackgroundSetColorReturn*) args_alloc( return_args_static, sizeof(CoreWindowStackBackgroundSetColorReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( color != NULL );

    args->color = *color;

    ret = (DFBResult) CoreWindowStack_Call( thiz->obj, FCEF_NONE, CoreWindowStackCall_BackgroundSetColor, args, sizeof(CoreWindowStackBackgroundSetColor), return_args, sizeof(CoreWindowStackBackgroundSetColorReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindowStack_Call( CoreWindowStack_BackgroundSetColor ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindowStack_BackgroundSetColor failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowStackRequestor_BackgroundSetColorIndex(IWindowStack *thiz,
                    s32                                        index
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowStackBackgroundSetColorIndex       *args = (CoreWindowStackBackgroundSetColorIndex*) args_alloc( args_static, sizeof(CoreWindowStackBackgroundSetColorIndex) );
    CoreWindowStackBackgroundSetColorIndexReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowStackBackgroundSetColorIndexReturn*) args_alloc( return_args_static, sizeof(CoreWindowStackBackgroundSetColorIndexReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackRequestor_%s()\n", __FUNCTION__ );


    args->index = index;

    ret = (DFBResult) CoreWindowStack_Call( thiz->obj, FCEF_NONE, CoreWindowStackCall_BackgroundSetColorIndex, args, sizeof(CoreWindowStackBackgroundSetColorIndex), return_args, sizeof(CoreWindowStackBackgroundSetColorIndexReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindowStack_Call( CoreWindowStack_BackgroundSetColorIndex ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindowStack_BackgroundSetColorIndex failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


void IWindowStackRequestorInit(IWindowStackRequestor *thiz, CoreDFB *core, CoreWindowStack *obj)
{
	thiz->base.core = core;
	thiz->base.obj = obj;

    thiz->base.RepaintAll = IWindowStackRequestor_RepaintAll;
    thiz->base.CursorEnable = IWindowStackRequestor_CursorEnable;
    thiz->base.CursorSetShape = IWindowStackRequestor_CursorSetShape;
    thiz->base.CursorSetOpacity = IWindowStackRequestor_CursorSetOpacity;
    thiz->base.CursorSetAcceleration = IWindowStackRequestor_CursorSetAcceleration;
    thiz->base.CursorWarp = IWindowStackRequestor_CursorWarp;
    thiz->base.CursorGetPosition = IWindowStackRequestor_CursorGetPosition;
    thiz->base.BackgroundSetMode = IWindowStackRequestor_BackgroundSetMode;
    thiz->base.BackgroundSetImage = IWindowStackRequestor_BackgroundSetImage;
    thiz->base.BackgroundSetColor = IWindowStackRequestor_BackgroundSetColor;
    thiz->base.BackgroundSetColorIndex = IWindowStackRequestor_BackgroundSetColorIndex;
}


/*********************************************************************************************************************/

static DFBResult
__CoreWindowStackDispatch__Dispatch( CoreWindowStack *obj,
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

	IWindowStackReal real;
	IWindowStack *super = (IWindowStack *)&real;
	IWindowStackRealInit(&real, core_dfb, obj);

    switch (method) {
        case CoreWindowStackCall_RepaintAll: {
            D_UNUSED
            CoreWindowStackRepaintAll       *args        = (CoreWindowStackRepaintAll *) ptr;
            CoreWindowStackRepaintAllReturn *return_args = (CoreWindowStackRepaintAllReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindowStack, "=-> CoreWindowStack_RepaintAll\n" );

            return_args->result = super->RepaintAll( super );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowStackRepaintAllReturn);

            return DFB_OK;
        }

        case CoreWindowStackCall_CursorEnable: {
            D_UNUSED
            CoreWindowStackCursorEnable       *args        = (CoreWindowStackCursorEnable *) ptr;
            CoreWindowStackCursorEnableReturn *return_args = (CoreWindowStackCursorEnableReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindowStack, "=-> CoreWindowStack_CursorEnable\n" );

            return_args->result = super->CursorEnable( super, args->enable );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowStackCursorEnableReturn);

            return DFB_OK;
        }

        case CoreWindowStackCall_CursorSetShape: {
    CoreSurface *shape = NULL;
            D_UNUSED
            CoreWindowStackCursorSetShape       *args        = (CoreWindowStackCursorSetShape *) ptr;
            CoreWindowStackCursorSetShapeReturn *return_args = (CoreWindowStackCursorSetShapeReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindowStack, "=-> CoreWindowStack_CursorSetShape\n" );

            ret = (DFBResult) CoreSurface_Lookup( core_dfb, args->shape_id, caller, &shape );
            if (ret) {
                 D_DERROR( ret, "%s: Looking up shape by ID %u failed!\n", __FUNCTION__, args->shape_id );
                 return_args->result = ret;
                 return ret;
            }

            return_args->result = super->CursorSetShape( super, shape, &args->hotspot );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowStackCursorSetShapeReturn);

            if (shape)
                CoreSurface_Unref( shape );

            return DFB_OK;
        }

        case CoreWindowStackCall_CursorSetOpacity: {
            D_UNUSED
            CoreWindowStackCursorSetOpacity       *args        = (CoreWindowStackCursorSetOpacity *) ptr;
            CoreWindowStackCursorSetOpacityReturn *return_args = (CoreWindowStackCursorSetOpacityReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindowStack, "=-> CoreWindowStack_CursorSetOpacity\n" );

            return_args->result = super->CursorSetOpacity( super, args->opacity );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowStackCursorSetOpacityReturn);

            return DFB_OK;
        }

        case CoreWindowStackCall_CursorSetAcceleration: {
            D_UNUSED
            CoreWindowStackCursorSetAcceleration       *args        = (CoreWindowStackCursorSetAcceleration *) ptr;
            CoreWindowStackCursorSetAccelerationReturn *return_args = (CoreWindowStackCursorSetAccelerationReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindowStack, "=-> CoreWindowStack_CursorSetAcceleration\n" );

            return_args->result = super->CursorSetAcceleration( super, args->numerator, args->denominator, args->threshold );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowStackCursorSetAccelerationReturn);

            return DFB_OK;
        }

        case CoreWindowStackCall_CursorWarp: {
            D_UNUSED
            CoreWindowStackCursorWarp       *args        = (CoreWindowStackCursorWarp *) ptr;
            CoreWindowStackCursorWarpReturn *return_args = (CoreWindowStackCursorWarpReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindowStack, "=-> CoreWindowStack_CursorWarp\n" );

            return_args->result = super->CursorWarp( super, &args->position );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowStackCursorWarpReturn);

            return DFB_OK;
        }

        case CoreWindowStackCall_CursorGetPosition: {
            D_UNUSED
            CoreWindowStackCursorGetPosition       *args        = (CoreWindowStackCursorGetPosition *) ptr;
            CoreWindowStackCursorGetPositionReturn *return_args = (CoreWindowStackCursorGetPositionReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindowStack, "=-> CoreWindowStack_CursorGetPosition\n" );

            return_args->result = super->CursorGetPosition( super, &return_args->position );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowStackCursorGetPositionReturn);

            return DFB_OK;
        }

        case CoreWindowStackCall_BackgroundSetMode: {
            D_UNUSED
            CoreWindowStackBackgroundSetMode       *args        = (CoreWindowStackBackgroundSetMode *) ptr;
            CoreWindowStackBackgroundSetModeReturn *return_args = (CoreWindowStackBackgroundSetModeReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindowStack, "=-> CoreWindowStack_BackgroundSetMode\n" );

            return_args->result = super->BackgroundSetMode( super, args->mode );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowStackBackgroundSetModeReturn);

            return DFB_OK;
        }

        case CoreWindowStackCall_BackgroundSetImage: {
    CoreSurface *image = NULL;
            D_UNUSED
            CoreWindowStackBackgroundSetImage       *args        = (CoreWindowStackBackgroundSetImage *) ptr;
            CoreWindowStackBackgroundSetImageReturn *return_args = (CoreWindowStackBackgroundSetImageReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindowStack, "=-> CoreWindowStack_BackgroundSetImage\n" );

            ret = (DFBResult) CoreSurface_Lookup( core_dfb, args->image_id, caller, &image );
            if (ret) {
                 D_DERROR( ret, "%s: Looking up image by ID %u failed!\n", __FUNCTION__, args->image_id );
                 return_args->result = ret;
                 return ret;
            }

            return_args->result = super->BackgroundSetImage( super, image );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowStackBackgroundSetImageReturn);

            if (image)
                CoreSurface_Unref( image );

            return DFB_OK;
        }

        case CoreWindowStackCall_BackgroundSetColor: {
            D_UNUSED
            CoreWindowStackBackgroundSetColor       *args        = (CoreWindowStackBackgroundSetColor *) ptr;
            CoreWindowStackBackgroundSetColorReturn *return_args = (CoreWindowStackBackgroundSetColorReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindowStack, "=-> CoreWindowStack_BackgroundSetColor\n" );

            return_args->result = super->BackgroundSetColor( super, &args->color );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowStackBackgroundSetColorReturn);

            return DFB_OK;
        }

        case CoreWindowStackCall_BackgroundSetColorIndex: {
            D_UNUSED
            CoreWindowStackBackgroundSetColorIndex       *args        = (CoreWindowStackBackgroundSetColorIndex *) ptr;
            CoreWindowStackBackgroundSetColorIndexReturn *return_args = (CoreWindowStackBackgroundSetColorIndexReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindowStack, "=-> CoreWindowStack_BackgroundSetColorIndex\n" );

            return_args->result = super->BackgroundSetColorIndex( super, args->index );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowStackBackgroundSetColorIndexReturn);

            return DFB_OK;
        }

    }

    return DFB_NOSUCHMETHOD;
}
/*********************************************************************************************************************/

DFBResult
CoreWindowStackDispatch__Dispatch( CoreWindowStack *obj,
                                FusionID      caller,
                                int           method,
                                void         *ptr,
                                unsigned int  length,
                                void         *ret_ptr,
                                unsigned int  ret_size,
                                unsigned int *ret_length )
{
    DFBResult ret = DFB_OK;

    D_DEBUG_AT( DirectFB_CoreWindowStack, "CoreWindowStackDispatch::%s( %p )\n", __FUNCTION__, obj );

    Core_PushIdentity( caller );

    ret = __CoreWindowStackDispatch__Dispatch( obj, caller, method, ptr, length, ret_ptr, ret_size, ret_length );

    Core_PopIdentity();

    return ret;
}

