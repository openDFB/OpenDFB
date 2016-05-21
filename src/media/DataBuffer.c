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

#include "DataBuffer.h"

#include <directfb_util.h>

#include <direct/debug.h>
#include <direct/mem.h>
#include <direct/memcpy.h>
#include <direct/messages.h>

#include <fusion/conf.h>

#include <core/core.h>


D_DEBUG_DOMAIN( DirectFB_DataBuffer, "DirectFB/DataBuffer", "DirectFB DataBuffer" );

/*********************************************************************************************************************/

DFBResult
DataBuffer_Flush(
                    DataBuffer                                *obj

)
{
	IDataBufferRequestor requestor;
	IDataBuffer *super = (IDataBuffer *)&requestor;
	IDataBufferRequestorInit( &requestor, core_dfb, obj );

    return super->Flush( super );
}

DFBResult
DataBuffer_Finish(
                    DataBuffer                                *obj

)
{
	IDataBufferRequestor requestor;
	IDataBuffer *super = (IDataBuffer *)&requestor;
	IDataBufferRequestorInit( &requestor, core_dfb, obj );

    return super->Finish( super );
}

DFBResult
DataBuffer_SeekTo(
                    DataBuffer                                *obj,
                    u64                                        offset
)
{
	IDataBufferRequestor requestor;
	IDataBuffer *super = (IDataBuffer *)&requestor;
	IDataBufferRequestorInit( &requestor, core_dfb, obj );

    return super->SeekTo( super, offset );
}

DFBResult
DataBuffer_GetPosition(
                    DataBuffer                                *obj,
                    u64                                       *ret_offset
)
{
	IDataBufferRequestor requestor;
	IDataBuffer *super = (IDataBuffer *)&requestor;
	IDataBufferRequestorInit( &requestor, core_dfb, obj );

    return super->GetPosition( super, ret_offset );
}

DFBResult
DataBuffer_GetLength(
                    DataBuffer                                *obj,
                    u64                                       *ret_length
)
{
	IDataBufferRequestor requestor;
	IDataBuffer *super = (IDataBuffer *)&requestor;
	IDataBufferRequestorInit( &requestor, core_dfb, obj );

    return super->GetLength( super, ret_length );
}

DFBResult
DataBuffer_WaitForData(
                    DataBuffer                                *obj,
                    u64                                        length
)
{
	IDataBufferRequestor requestor;
	IDataBuffer *super = (IDataBuffer *)&requestor;
	IDataBufferRequestorInit( &requestor, core_dfb, obj );

    return super->WaitForData( super, length );
}

DFBResult
DataBuffer_WaitForDataWithTimeout(
                    DataBuffer                                *obj,
                    u64                                        length,
                    u64                                        timeout_ms
)
{
	IDataBufferRequestor requestor;
	IDataBuffer *super = (IDataBuffer *)&requestor;
	IDataBufferRequestorInit( &requestor, core_dfb, obj );

    return super->WaitForDataWithTimeout( super, length, timeout_ms );
}

DFBResult
DataBuffer_GetData(
                    DataBuffer                                *obj,
                    u32                                        length,
                    u8                                        *ret_data,
                    u32                                       *ret_read
)
{
	IDataBufferRequestor requestor;
	IDataBuffer *super = (IDataBuffer *)&requestor;
	IDataBufferRequestorInit( &requestor, core_dfb, obj );

    return super->GetData( super, length, ret_data, ret_read );
}

DFBResult
DataBuffer_PeekData(
                    DataBuffer                                *obj,
                    u32                                        length,
                    s64                                        offset,
                    u8                                        *ret_data,
                    u32                                       *ret_read
)
{
	IDataBufferRequestor requestor;
	IDataBuffer *super = (IDataBuffer *)&requestor;
	IDataBufferRequestorInit( &requestor, core_dfb, obj );

    return super->PeekData( super, length, offset, ret_data, ret_read );
}

DFBResult
DataBuffer_HasData(
                    DataBuffer                                *obj

)
{
	IDataBufferRequestor requestor;
	IDataBuffer *super = (IDataBuffer *)&requestor;
	IDataBufferRequestorInit( &requestor, core_dfb, obj );

    return super->HasData( super );
}

DFBResult
DataBuffer_PutData(
                    DataBuffer                                *obj,
                    const u8                                  *data,
                    u32                                        length
)
{
	IDataBufferRequestor requestor;
	IDataBuffer *super = (IDataBuffer *)&requestor;
	IDataBufferRequestorInit( &requestor, core_dfb, obj );

    return super->PutData( super, data, length );
}

/*********************************************************************************************************************/

static FusionCallHandlerResult
DataBuffer_Dispatch( int           caller,   /* fusion id of the caller */
                     int           call_arg, /* optional call parameter */
                     void         *ptr, /* optional call parameter */
                     unsigned int  length,
                     void         *ctx,      /* optional handler context */
                     unsigned int  serial,
                     void         *ret_ptr,
                     unsigned int  ret_size,
                     unsigned int *ret_length )
{
    IDirectFBDataBuffer *obj = (IDirectFBDataBuffer*) ctx;
    DataBufferDispatch__Dispatch( obj, caller, call_arg, ptr, length, ret_ptr, ret_size, ret_length );

    return FCHR_RETURN;
}

void DataBuffer_Init_Dispatch(
                    CoreDFB              *core,
                    IDirectFBDataBuffer  *obj,
                    FusionCall           *call
)
{
    fusion_call_init3( call, DataBuffer_Dispatch, obj, core->world );
}

void  DataBuffer_Deinit_Dispatch(
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
IDataBufferRequestor_Flush(IDataBuffer *thiz

)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    DataBufferFlush       *args = (DataBufferFlush*) args_alloc( args_static, sizeof(DataBufferFlush) );
    DataBufferFlushReturn *return_args;

	IDataBufferRequestor *ibr = (IDataBufferRequestor *)thiz;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (DataBufferFlushReturn*) args_alloc( return_args_static, sizeof(DataBufferFlushReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_DataBuffer, "IDataBufferRequestor_%s()\n", __FUNCTION__ );



    ret = (DFBResult) DataBuffer_Call( ibr->obj, FCEF_NONE, DataBufferCall_Flush, args, sizeof(DataBufferFlush), return_args, sizeof(DataBufferFlushReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: DataBuffer_Call( DataBuffer_Flush ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: DataBuffer_Flush failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IDataBufferRequestor_Finish(IDataBuffer *thiz

)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    DataBufferFinish       *args = (DataBufferFinish*) args_alloc( args_static, sizeof(DataBufferFinish) );
    DataBufferFinishReturn *return_args;
	IDataBufferRequestor *ibr = (IDataBufferRequestor *)thiz;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (DataBufferFinishReturn*) args_alloc( return_args_static, sizeof(DataBufferFinishReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_DataBuffer, "IDataBufferRequestor_%s()\n", __FUNCTION__ );



    ret = (DFBResult) DataBuffer_Call( ibr->obj, FCEF_NONE, DataBufferCall_Finish, args, sizeof(DataBufferFinish), return_args, sizeof(DataBufferFinishReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: DataBuffer_Call( DataBuffer_Finish ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: DataBuffer_Finish failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IDataBufferRequestor_SeekTo(IDataBuffer *thiz,
                    u64                                        offset
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    DataBufferSeekTo       *args = (DataBufferSeekTo*) args_alloc( args_static, sizeof(DataBufferSeekTo) );
    DataBufferSeekToReturn *return_args;
	IDataBufferRequestor *ibr = (IDataBufferRequestor *)thiz;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (DataBufferSeekToReturn*) args_alloc( return_args_static, sizeof(DataBufferSeekToReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_DataBuffer, "IDataBufferRequestor_%s()\n", __FUNCTION__ );


    args->offset = offset;

    ret = (DFBResult) DataBuffer_Call( ibr->obj, FCEF_NONE, DataBufferCall_SeekTo, args, sizeof(DataBufferSeekTo), return_args, sizeof(DataBufferSeekToReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: DataBuffer_Call( DataBuffer_SeekTo ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: DataBuffer_SeekTo failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IDataBufferRequestor_GetPosition(IDataBuffer *thiz,
                    u64                                       *ret_offset
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    DataBufferGetPosition       *args = (DataBufferGetPosition*) args_alloc( args_static, sizeof(DataBufferGetPosition) );
    DataBufferGetPositionReturn *return_args;
	IDataBufferRequestor *ibr = (IDataBufferRequestor *)thiz;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (DataBufferGetPositionReturn*) args_alloc( return_args_static, sizeof(DataBufferGetPositionReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_DataBuffer, "IDataBufferRequestor_%s()\n", __FUNCTION__ );



    ret = (DFBResult) DataBuffer_Call( ibr->obj, FCEF_NONE, DataBufferCall_GetPosition, args, sizeof(DataBufferGetPosition), return_args, sizeof(DataBufferGetPositionReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: DataBuffer_Call( DataBuffer_GetPosition ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: DataBuffer_GetPosition failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

    *ret_offset = return_args->offset;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IDataBufferRequestor_GetLength(IDataBuffer *thiz,
                    u64                                       *ret_length
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    DataBufferGetLength       *args = (DataBufferGetLength*) args_alloc( args_static, sizeof(DataBufferGetLength) );
    DataBufferGetLengthReturn *return_args;
	IDataBufferRequestor *ibr = (IDataBufferRequestor *)thiz;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (DataBufferGetLengthReturn*) args_alloc( return_args_static, sizeof(DataBufferGetLengthReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_DataBuffer, "IDataBufferRequestor_%s()\n", __FUNCTION__ );



    ret = (DFBResult) DataBuffer_Call( ibr->obj, FCEF_NONE, DataBufferCall_GetLength, args, sizeof(DataBufferGetLength), return_args, sizeof(DataBufferGetLengthReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: DataBuffer_Call( DataBuffer_GetLength ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: DataBuffer_GetLength failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

    *ret_length = return_args->length;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IDataBufferRequestor_WaitForData(IDataBuffer *thiz,
                    u64                                        length
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    DataBufferWaitForData       *args = (DataBufferWaitForData*) args_alloc( args_static, sizeof(DataBufferWaitForData) );
    DataBufferWaitForDataReturn *return_args;
	IDataBufferRequestor *ibr = (IDataBufferRequestor *)thiz;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (DataBufferWaitForDataReturn*) args_alloc( return_args_static, sizeof(DataBufferWaitForDataReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_DataBuffer, "IDataBufferRequestor_%s()\n", __FUNCTION__ );


    args->length = length;

    ret = (DFBResult) DataBuffer_Call( ibr->obj, FCEF_NONE, DataBufferCall_WaitForData, args, sizeof(DataBufferWaitForData), return_args, sizeof(DataBufferWaitForDataReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: DataBuffer_Call( DataBuffer_WaitForData ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: DataBuffer_WaitForData failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IDataBufferRequestor_WaitForDataWithTimeout(IDataBuffer *thiz,
                    u64                                        length,
                    u64                                        timeout_ms
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    DataBufferWaitForDataWithTimeout       *args = (DataBufferWaitForDataWithTimeout*) args_alloc( args_static, sizeof(DataBufferWaitForDataWithTimeout) );
    DataBufferWaitForDataWithTimeoutReturn *return_args;
	IDataBufferRequestor *ibr = (IDataBufferRequestor *)thiz;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (DataBufferWaitForDataWithTimeoutReturn*) args_alloc( return_args_static, sizeof(DataBufferWaitForDataWithTimeoutReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_DataBuffer, "IDataBufferRequestor_%s()\n", __FUNCTION__ );


    args->length = length;
    args->timeout_ms = timeout_ms;

    ret = (DFBResult) DataBuffer_Call( ibr->obj, FCEF_NONE, DataBufferCall_WaitForDataWithTimeout, args, sizeof(DataBufferWaitForDataWithTimeout), return_args, sizeof(DataBufferWaitForDataWithTimeoutReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: DataBuffer_Call( DataBuffer_WaitForDataWithTimeout ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: DataBuffer_WaitForDataWithTimeout failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IDataBufferRequestor_GetData(IDataBuffer *thiz,
                    u32                                        length,
                    u8                                        *ret_data,
                    u32                                       *ret_read
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    DataBufferGetData       *args = (DataBufferGetData*) args_alloc( args_static, sizeof(DataBufferGetData) );
    DataBufferGetDataReturn *return_args;
	IDataBufferRequestor *ibr = (IDataBufferRequestor *)thiz;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (DataBufferGetDataReturn*) args_alloc( return_args_static, sizeof(DataBufferGetDataReturn) + length * sizeof(u8) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_DataBuffer, "IDataBufferRequestor_%s()\n", __FUNCTION__ );


    args->length = length;

    ret = (DFBResult) DataBuffer_Call( ibr->obj, FCEF_NONE, DataBufferCall_GetData, args, sizeof(DataBufferGetData), return_args, sizeof(DataBufferGetDataReturn) + length * sizeof(u8), NULL );
    if (ret) {
        D_DERROR( ret, "%s: DataBuffer_Call( DataBuffer_GetData ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: DataBuffer_GetData failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

    *ret_read = return_args->read;
    direct_memcpy( ret_data, (char*) (return_args + 1), return_args->read * sizeof(u8) );


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IDataBufferRequestor_PeekData(IDataBuffer *thiz,
                    u32                                        length,
                    s64                                        offset,
                    u8                                        *ret_data,
                    u32                                       *ret_read
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    DataBufferPeekData       *args = (DataBufferPeekData*) args_alloc( args_static, sizeof(DataBufferPeekData) );
    DataBufferPeekDataReturn *return_args;
	IDataBufferRequestor *ibr = (IDataBufferRequestor *)thiz;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (DataBufferPeekDataReturn*) args_alloc( return_args_static, sizeof(DataBufferPeekDataReturn) + length * sizeof(u8) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_DataBuffer, "IDataBufferRequestor_%s()\n", __FUNCTION__ );


    args->length = length;
    args->offset = offset;

    ret = (DFBResult) DataBuffer_Call( ibr->obj, FCEF_NONE, DataBufferCall_PeekData, args, sizeof(DataBufferPeekData), return_args, sizeof(DataBufferPeekDataReturn) + length * sizeof(u8), NULL );
    if (ret) {
        D_DERROR( ret, "%s: DataBuffer_Call( DataBuffer_PeekData ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: DataBuffer_PeekData failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

    *ret_read = return_args->read;
    direct_memcpy( ret_data, (char*) (return_args + 1), return_args->read * sizeof(u8) );


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IDataBufferRequestor_HasData(IDataBuffer *thiz

)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    DataBufferHasData       *args = (DataBufferHasData*) args_alloc( args_static, sizeof(DataBufferHasData) );
    DataBufferHasDataReturn *return_args;
	IDataBufferRequestor *ibr = (IDataBufferRequestor *)thiz;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (DataBufferHasDataReturn*) args_alloc( return_args_static, sizeof(DataBufferHasDataReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_DataBuffer, "IDataBufferRequestor_%s()\n", __FUNCTION__ );



    ret = (DFBResult) DataBuffer_Call( ibr->obj, FCEF_NONE, DataBufferCall_HasData, args, sizeof(DataBufferHasData), return_args, sizeof(DataBufferHasDataReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: DataBuffer_Call( DataBuffer_HasData ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: DataBuffer_HasData failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IDataBufferRequestor_PutData(IDataBuffer *thiz,
                    const u8                                  *data,
                    u32                                        length
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    DataBufferPutData       *args = (DataBufferPutData*) args_alloc( args_static, sizeof(DataBufferPutData) + length * sizeof(u8) );
    DataBufferPutDataReturn *return_args;
	IDataBufferRequestor *ibr = (IDataBufferRequestor *)thiz;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (DataBufferPutDataReturn*) args_alloc( return_args_static, sizeof(DataBufferPutDataReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_DataBuffer, "IDataBufferRequestor_%s()\n", __FUNCTION__ );


    args->length = length;
    direct_memcpy( (char*) (args + 1), data, length * sizeof(u8) );

    ret = (DFBResult) DataBuffer_Call( ibr->obj, FCEF_NONE, DataBufferCall_PutData, args, sizeof(DataBufferPutData) + length * sizeof(u8), return_args, sizeof(DataBufferPutDataReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: DataBuffer_Call( DataBuffer_PutData ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: DataBuffer_PutData failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}



void IDataBufferRequestorInit(IDataBufferRequestor *thiz, CoreDFB *core, DataBuffer *obj)
{
	thiz->base.core = core;
	thiz->obj = obj;

	thiz->base.Flush = IDataBufferRequestor_Flush;
	thiz->base.SeekTo = IDataBufferRequestor_SeekTo;
	thiz->base.GetPosition = IDataBufferRequestor_GetPosition;
	thiz->base.GetLength = IDataBufferRequestor_GetLength;
	thiz->base.WaitForData = IDataBufferRequestor_WaitForData;
	thiz->base.WaitForDataWithTimeout = IDataBufferRequestor_WaitForDataWithTimeout;
	thiz->base.GetData = IDataBufferRequestor_GetData;
	thiz->base.PeekData = IDataBufferRequestor_PeekData;
	thiz->base.HasData = IDataBufferRequestor_HasData;
	thiz->base.PutData = IDataBufferRequestor_PutData;
}

/*********************************************************************************************************************/

static DFBResult
__DataBufferDispatch__Dispatch( IDirectFBDataBuffer *obj,
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

	IDataBufferReal real;
	IDataBuffer *super = (IDataBuffer *)&real;
	IDataBufferRealInit( &real, core_dfb, obj );

    switch (method) {
        case DataBufferCall_Flush: {
            D_UNUSED
            DataBufferFlush       *args        = (DataBufferFlush *) ptr;
            DataBufferFlushReturn *return_args = (DataBufferFlushReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_DataBuffer, "=-> DataBuffer_Flush\n" );

            return_args->result = super->Flush( super );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(DataBufferFlushReturn);

            return DFB_OK;
        }

        case DataBufferCall_Finish: {
            D_UNUSED
            DataBufferFinish       *args        = (DataBufferFinish *) ptr;
            DataBufferFinishReturn *return_args = (DataBufferFinishReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_DataBuffer, "=-> DataBuffer_Finish\n" );

            return_args->result = super->Finish( super );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(DataBufferFinishReturn);

            return DFB_OK;
        }

        case DataBufferCall_SeekTo: {
            D_UNUSED
            DataBufferSeekTo       *args        = (DataBufferSeekTo *) ptr;
            DataBufferSeekToReturn *return_args = (DataBufferSeekToReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_DataBuffer, "=-> DataBuffer_SeekTo\n" );

            return_args->result = super->SeekTo( super, args->offset );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(DataBufferSeekToReturn);

            return DFB_OK;
        }

        case DataBufferCall_GetPosition: {
            D_UNUSED
            DataBufferGetPosition       *args        = (DataBufferGetPosition *) ptr;
            DataBufferGetPositionReturn *return_args = (DataBufferGetPositionReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_DataBuffer, "=-> DataBuffer_GetPosition\n" );

            return_args->result = super->GetPosition( super, &return_args->offset );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(DataBufferGetPositionReturn);

            return DFB_OK;
        }

        case DataBufferCall_GetLength: {
            D_UNUSED
            DataBufferGetLength       *args        = (DataBufferGetLength *) ptr;
            DataBufferGetLengthReturn *return_args = (DataBufferGetLengthReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_DataBuffer, "=-> DataBuffer_GetLength\n" );

            return_args->result = super->GetLength( super, &return_args->length );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(DataBufferGetLengthReturn);

            return DFB_OK;
        }

        case DataBufferCall_WaitForData: {
            D_UNUSED
            DataBufferWaitForData       *args        = (DataBufferWaitForData *) ptr;
            DataBufferWaitForDataReturn *return_args = (DataBufferWaitForDataReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_DataBuffer, "=-> DataBuffer_WaitForData\n" );

            return_args->result = super->WaitForData( super, args->length );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(DataBufferWaitForDataReturn);

            return DFB_OK;
        }

        case DataBufferCall_WaitForDataWithTimeout: {
            D_UNUSED
            DataBufferWaitForDataWithTimeout       *args        = (DataBufferWaitForDataWithTimeout *) ptr;
            DataBufferWaitForDataWithTimeoutReturn *return_args = (DataBufferWaitForDataWithTimeoutReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_DataBuffer, "=-> DataBuffer_WaitForDataWithTimeout\n" );

            return_args->result = super->WaitForDataWithTimeout( super, args->length, args->timeout_ms );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(DataBufferWaitForDataWithTimeoutReturn);

            return DFB_OK;
        }

        case DataBufferCall_GetData: {
            D_UNUSED
            DataBufferGetData       *args        = (DataBufferGetData *) ptr;
            DataBufferGetDataReturn *return_args = (DataBufferGetDataReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_DataBuffer, "=-> DataBuffer_GetData\n" );

            return_args->result = super->GetData( super, args->length, (u8*) ((char*)(return_args + 1)), &return_args->read );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(DataBufferGetDataReturn) + return_args->read * sizeof(u8);

            return DFB_OK;
        }

        case DataBufferCall_PeekData: {
            D_UNUSED
            DataBufferPeekData       *args        = (DataBufferPeekData *) ptr;
            DataBufferPeekDataReturn *return_args = (DataBufferPeekDataReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_DataBuffer, "=-> DataBuffer_PeekData\n" );

            return_args->result = super->PeekData( super, args->length, args->offset, (u8*) ((char*)(return_args + 1)), &return_args->read );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(DataBufferPeekDataReturn) + return_args->read * sizeof(u8);

            return DFB_OK;
        }

        case DataBufferCall_HasData: {
            D_UNUSED
            DataBufferHasData       *args        = (DataBufferHasData *) ptr;
            DataBufferHasDataReturn *return_args = (DataBufferHasDataReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_DataBuffer, "=-> DataBuffer_HasData\n" );

            return_args->result = super->HasData( super );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(DataBufferHasDataReturn);

            return DFB_OK;
        }

        case DataBufferCall_PutData: {
            D_UNUSED
            DataBufferPutData       *args        = (DataBufferPutData *) ptr;
            DataBufferPutDataReturn *return_args = (DataBufferPutDataReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_DataBuffer, "=-> DataBuffer_PutData\n" );

            return_args->result = super->PutData( super, (u8*) ((char*)(args + 1)), args->length );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(DataBufferPutDataReturn);

            return DFB_OK;
        }

    }

    return DFB_NOSUCHMETHOD;
}
/*********************************************************************************************************************/

DFBResult
DataBufferDispatch__Dispatch( IDirectFBDataBuffer *obj,
                                FusionID      caller,
                                int           method,
                                void         *ptr,
                                unsigned int  length,
                                void         *ret_ptr,
                                unsigned int  ret_size,
                                unsigned int *ret_length )
{
    DFBResult ret = DFB_OK;

    D_DEBUG_AT( DirectFB_DataBuffer, "DataBufferDispatch::%s( %p )\n", __FUNCTION__, obj );

    Core_PushIdentity( caller );

    ret = __DataBufferDispatch__Dispatch( obj, caller, method, ptr, length, ret_ptr, ret_size, ret_length );

    Core_PopIdentity();

    return ret;
}

