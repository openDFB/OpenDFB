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

#include "SaWMan.h"

#include <directfb_util.h>

#include <direct/debug.h>
#include <direct/mem.h>
#include <direct/memcpy.h>
#include <direct/messages.h>

#include <fusion/conf.h>

#include <core/core.h>

D_DEBUG_DOMAIN( DirectFB_SaWMan, "DirectFB/SaWMan", "DirectFB SaWMan" );

/*********************************************************************************************************************/

DFBResult
SaWMan_RegisterProcess(
                    SaWMan                                    *obj,
                    SaWManProcessFlags                         flags,
                    s32                                        pid,
                    u32                                        fusion_id,
                    SaWManProcess                            **ret_process
)
{
    if (!fusion_config->secure_fusion || dfb_core_is_master( core_dfb )) {
		ISaWManWMReal real;
		ISaWManWM *super = (ISaWManWM *)&real;
		ISaWManWMRealInit( &real, core_dfb, obj );

        return super->RegisterProcess( super, flags, pid, fusion_id, ret_process );
    }

	ISaWManWMRequestor requestor;
	ISaWManWM *super = (ISaWManWM *)&requestor;
	ISaWManWMRequestorInit( &requestor, core_dfb, obj );

    return super->RegisterProcess( super, flags, pid, fusion_id, ret_process );
}

DFBResult
SaWMan_Start(
                    SaWMan                                    *obj,
                    const u8                                  *name,
                    u32                                        name_len,
                    s32                                       *ret_pid
)
{
    if (!fusion_config->secure_fusion || dfb_core_is_master( core_dfb )) {
		ISaWManWMReal real;
		ISaWManWM *super = (ISaWManWM *)&real;
		ISaWManWMRealInit( &real, core_dfb, obj );

        return super->Start( super, name, name_len, ret_pid );
    }

	ISaWManWMRequestor requestor;
	ISaWManWM *super = (ISaWManWM *)&requestor;
	ISaWManWMRequestorInit( &requestor, core_dfb, obj );


    return super->Start( super, name, name_len, ret_pid );
}

DFBResult
SaWMan_Stop(
                    SaWMan                                    *obj,
                    s32                                        pid
)
{
    if (!fusion_config->secure_fusion || dfb_core_is_master( core_dfb )) {
		ISaWManWMReal real;
		ISaWManWM *super = (ISaWManWM *)&real;
		ISaWManWMRealInit( &real, core_dfb, obj );

        return super->Stop( super, pid );
    }

	ISaWManWMRequestor requestor;
	ISaWManWM *super = (ISaWManWM *)&requestor;
	ISaWManWMRequestorInit( &requestor, core_dfb, obj );

    return super->Stop( super, pid );
}

DFBResult
SaWMan_GetPerformance(
                    SaWMan                                    *obj,
                    DFBWindowStackingClass                     stacking,
                    DFBBoolean                                 reset,
                    u32                                       *ret_updates,
                    u64                                       *ret_pixels,
                    s64                                       *ret_duration
)
{
    if (!fusion_config->secure_fusion || dfb_core_is_master( core_dfb )) {
		ISaWManWMReal real;
		ISaWManWM *super = (ISaWManWM *)&real;
		ISaWManWMRealInit( &real, core_dfb, obj );

        return super->GetPerformance( super, stacking, reset, ret_updates, ret_pixels, ret_duration );
    }

	ISaWManWMRequestor requestor;
	ISaWManWM *super = (ISaWManWM *)&requestor;
	ISaWManWMRequestorInit( &requestor, core_dfb, obj );

    return super->GetPerformance( super, stacking, reset, ret_updates, ret_pixels, ret_duration );
}

/*********************************************************************************************************************/

static FusionCallHandlerResult
SaWMan_Dispatch( int           caller,   /* fusion id of the caller */
                     int           call_arg, /* optional call parameter */
                     void         *ptr, /* optional call parameter */
                     unsigned int  length,
                     void         *ctx,      /* optional handler context */
                     unsigned int  serial,
                     void         *ret_ptr,
                     unsigned int  ret_size,
                     unsigned int *ret_length )
{
    SaWMan *obj = (SaWMan*) ctx;
    SaWManDispatch__Dispatch( obj, caller, call_arg, ptr, length, ret_ptr, ret_size, ret_length );

    return FCHR_RETURN;
}

void SaWMan_Init_Dispatch(
                    CoreDFB              *core,
                    SaWMan               *obj,
                    FusionCall           *call
)
{
    fusion_call_init3( call, SaWMan_Dispatch, obj, core->world );
}

void  SaWMan_Deinit_Dispatch(
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
ISaWManWMRequestor_RegisterProcess(ISaWManWM *thiz,
                    SaWManProcessFlags                         flags,
                    s32                                        pid,
                    u32                                        fusion_id,
                    SaWManProcess                            **ret_process
)
{
    DFBResult           ret = DFB_OK;
    SaWManProcess *process = NULL;
    char        args_static[1000];
    char        return_args_static[1000];
    SaWManRegisterProcess       *args = (SaWManRegisterProcess*) args_alloc( args_static, sizeof(SaWManRegisterProcess) );
    SaWManRegisterProcessReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (SaWManRegisterProcessReturn*) args_alloc( return_args_static, sizeof(SaWManRegisterProcessReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_SaWMan, "ISaWManWMRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( ret_process != NULL );

    args->flags = flags;
    args->pid = pid;
    args->fusion_id = fusion_id;

    ret = (DFBResult) SaWMan_Call( thiz->obj, FCEF_NONE, SaWManCall_RegisterProcess, args, sizeof(SaWManRegisterProcess), return_args, sizeof(SaWManRegisterProcessReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: SaWMan_Call( SaWMan_RegisterProcess ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: SaWMan_RegisterProcess failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }


    ret = (DFBResult) SaWManProcess_Catch( thiz->core, return_args->process_id, &process );
    if (ret) {
         D_DERROR( ret, "%s: Catching process by ID %u failed!\n", __FUNCTION__, return_args->process_id );
         goto out;
    }

    *ret_process = process;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ISaWManWMRequestor_Start(ISaWManWM *thiz,
                    const u8                                  *name,
                    u32                                        name_len,
                    s32                                       *ret_pid
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[1000];
    char        return_args_static[1000];
    SaWManStart       *args = (SaWManStart*) args_alloc( args_static, sizeof(SaWManStart) + name_len * sizeof(u8) );
    SaWManStartReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (SaWManStartReturn*) args_alloc( return_args_static, sizeof(SaWManStartReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_SaWMan, "ISaWManWMRequestor_%s()\n", __FUNCTION__ );


    args->name_len = name_len;
    direct_memcpy( (char*) (args + 1), name, name_len * sizeof(u8) );

    ret = (DFBResult) SaWMan_Call( thiz->obj, FCEF_NONE, SaWManCall_Start, args, sizeof(SaWManStart) + name_len * sizeof(u8), return_args, sizeof(SaWManStartReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: SaWMan_Call( SaWMan_Start ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: SaWMan_Start failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

    *ret_pid = return_args->pid;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ISaWManWMRequestor_Stop(ISaWManWM *thiz,
                    s32                                        pid
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[1000];
    char        return_args_static[1000];
    SaWManStop       *args = (SaWManStop*) args_alloc( args_static, sizeof(SaWManStop) );
    SaWManStopReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (SaWManStopReturn*) args_alloc( return_args_static, sizeof(SaWManStopReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_SaWMan, "ISaWManWMRequestor_%s()\n", __FUNCTION__ );


    args->pid = pid;

    ret = (DFBResult) SaWMan_Call( thiz->obj, FCEF_NONE, SaWManCall_Stop, args, sizeof(SaWManStop), return_args, sizeof(SaWManStopReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: SaWMan_Call( SaWMan_Stop ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: SaWMan_Stop failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ISaWManWMRequestor_GetPerformance(ISaWManWM *thiz,
                    DFBWindowStackingClass                     stacking,
                    DFBBoolean                                 reset,
                    u32                                       *ret_updates,
                    u64                                       *ret_pixels,
                    s64                                       *ret_duration
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[1000];
    char        return_args_static[1000];
    SaWManGetPerformance       *args = (SaWManGetPerformance*) args_alloc( args_static, sizeof(SaWManGetPerformance) );
    SaWManGetPerformanceReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (SaWManGetPerformanceReturn*) args_alloc( return_args_static, sizeof(SaWManGetPerformanceReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_SaWMan, "ISaWManWMRequestor_%s()\n", __FUNCTION__ );


    args->stacking = stacking;
    args->reset = reset;

    ret = (DFBResult) SaWMan_Call( thiz->obj, FCEF_NONE, SaWManCall_GetPerformance, args, sizeof(SaWManGetPerformance), return_args, sizeof(SaWManGetPerformanceReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: SaWMan_Call( SaWMan_GetPerformance ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: SaWMan_GetPerformance failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

    *ret_updates = return_args->updates;
    *ret_pixels = return_args->pixels;
    *ret_duration = return_args->duration;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}

void ISaWManWMRealInit(ISaWManWMReal *thiz, CoreDFB *core, SaWMan *obj)
{
	thiz->base.core = core;
	thiz->base.obj = obj;

	thiz->base.RegisterProcess = ISaWManWMRequestor_RegisterProcess;
	thiz->base.Start = ISaWManWMRequestor_Start;
	thiz->base.Stop = ISaWManWMRequestor_Stop;
	thiz->base.GetPerformance = ISaWManWMRequestor_GetPerformance;
}


/*********************************************************************************************************************/

static DFBResult
__SaWManDispatch__Dispatch( SaWMan *obj,
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

	ISaWManWMReal real;
	ISaWManWM *super = (ISaWManWM *)&real;
	ISaWManWMRealInit( &real, core_dfb, obj );

    switch (method) {
        case SaWManCall_RegisterProcess: {
    		SaWManProcess *process = NULL;
            D_UNUSED
            SaWManRegisterProcess       *args        = (SaWManRegisterProcess *) ptr;
            SaWManRegisterProcessReturn *return_args = (SaWManRegisterProcessReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_SaWMan, "=-> SaWMan_RegisterProcess\n" );

            return_args->result = super->RegisterProcess( super, args->flags, args->pid, args->fusion_id, &process );
            if (return_args->result == DFB_OK) {
                SaWManProcess_Throw( process, caller, &return_args->process_id );
            }

            *ret_length = sizeof(SaWManRegisterProcessReturn);

            return DFB_OK;
        }

        case SaWManCall_Start: {
            D_UNUSED
            SaWManStart       *args        = (SaWManStart *) ptr;
            SaWManStartReturn *return_args = (SaWManStartReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_SaWMan, "=-> SaWMan_Start\n" );

            return_args->result = super->Start( super, (u8*) ((char*)(args + 1)), args->name_len, &return_args->pid );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(SaWManStartReturn);

            return DFB_OK;
        }

        case SaWManCall_Stop: {
            D_UNUSED
            SaWManStop       *args        = (SaWManStop *) ptr;
            SaWManStopReturn *return_args = (SaWManStopReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_SaWMan, "=-> SaWMan_Stop\n" );

            return_args->result = super->Stop( super, args->pid );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(SaWManStopReturn);

            return DFB_OK;
        }

        case SaWManCall_GetPerformance: {
            D_UNUSED
            SaWManGetPerformance       *args        = (SaWManGetPerformance *) ptr;
            SaWManGetPerformanceReturn *return_args = (SaWManGetPerformanceReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_SaWMan, "=-> SaWMan_GetPerformance\n" );

            return_args->result = super->GetPerformance( super, args->stacking, args->reset, &return_args->updates, &return_args->pixels, &return_args->duration );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(SaWManGetPerformanceReturn);

            return DFB_OK;
        }

    }

    return DFB_NOSUCHMETHOD;
}
/*********************************************************************************************************************/

DFBResult
SaWManDispatch__Dispatch( SaWMan *obj,
                                FusionID      caller,
                                int           method,
                                void         *ptr,
                                unsigned int  length,
                                void         *ret_ptr,
                                unsigned int  ret_size,
                                unsigned int *ret_length )
{
    DFBResult ret = DFB_OK;

    D_DEBUG_AT( DirectFB_SaWMan, "SaWManDispatch::%s( %p )\n", __FUNCTION__, obj );

    ret = __SaWManDispatch__Dispatch( obj, caller, method, ptr, length, ret_ptr, ret_size, ret_length );

    return ret;
}

