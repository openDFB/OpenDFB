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

#ifndef ___CoreDFB__H___
#define ___CoreDFB__H___

#include <core/CoreDFB_includes.h>

/**********************************************************************************************************************
 * CoreDFB
 */

DFBResult CoreDFB_Initialize(
                    CoreDFB                                   *obj
);

DFBResult CoreDFB_Register(
                    CoreDFB                                   *obj,
                    u32                                        slave_call);

DFBResult CoreDFB_CreateSurface(
                    CoreDFB                                   *obj,
                    const CoreSurfaceConfig                   *config,
                    CoreSurfaceTypeFlags                       type,
                    u64                                        resource_id,
                    CorePalette                               *palette,
                    CoreSurface                              **ret_surface);

DFBResult CoreDFB_CreatePalette(
                    CoreDFB                                   *obj,
                    u32                                        size,
                    CorePalette                              **ret_palette);

DFBResult CoreDFB_CreateState(
                    CoreDFB                                   *obj,
                    CoreGraphicsState                        **ret_state);

DFBResult CoreDFB_WaitIdle(
                    CoreDFB                                   *obj
);

DFBResult CoreDFB_CreateImageProvider(
                    CoreDFB                                   *obj,
                    u32                                        buffer_call,
                    u32                                       *ret_call);

DFBResult CoreDFB_AllowSurface(
                    CoreDFB                                   *obj,
                    CoreSurface                               *surface,
                    const char                                *executable,
                    u32                                        executable_length);

DFBResult CoreDFB_GetSurface(
                    CoreDFB                                   *obj,
                    u32                                        surface_id,
                    CoreSurface                              **ret_surface);

DFBResult CoreDFB_ClipboardSet(
                    CoreDFB                                   *obj,
                    const char                                *mime_type,
                    u32                                        mime_type_size,
                    const char                                *data,
                    u32                                        data_size,
                    u64                                        timestamp_us);

DFBResult CoreDFB_ClipboardGet(
                    CoreDFB                                   *obj,
                    char                                      *ret_mime_type,
                    u32                                       *ret_mime_type_size,
                    char                                      *ret_data,
                    u32                                       *ret_data_size);

DFBResult CoreDFB_ClipboardGetTimestamp(
                    CoreDFB                                   *obj,
                    u64                                       *ret_timestamp_us);


void CoreDFB_Init_Dispatch(
                    CoreDFB              *core,
                    CoreDFB              *obj,
                    FusionCall           *call
);

void  CoreDFB_Deinit_Dispatch(
                    FusionCall           *call
);


/*
 * CoreDFB Calls
 */
typedef enum {
    CoreDFBCall_Initialize = 1,
    CoreDFBCall_Register = 2,
    CoreDFBCall_CreateSurface = 3,
    CoreDFBCall_CreatePalette = 4,
    CoreDFBCall_CreateState = 5,
    CoreDFBCall_WaitIdle = 6,
    CoreDFBCall_CreateImageProvider = 7,
    CoreDFBCall_AllowSurface = 8,
    CoreDFBCall_GetSurface = 9,
    CoreDFBCall_ClipboardSet = 10,
    CoreDFBCall_ClipboardGet = 11,
    CoreDFBCall_ClipboardGetTimestamp = 12,
} CoreDFBCall;

/*
 * CoreDFB_Initialize
 */
typedef struct {
} CoreDFBInitialize;

typedef struct {
    DFBResult                                  result;
} CoreDFBInitializeReturn;


/*
 * CoreDFB_Register
 */
typedef struct {
    u32                                        slave_call;
} CoreDFBRegister;

typedef struct {
    DFBResult                                  result;
} CoreDFBRegisterReturn;


/*
 * CoreDFB_CreateSurface
 */
typedef struct {
    CoreSurfaceConfig                          config;
    CoreSurfaceTypeFlags                       type;
    u64                                        resource_id;
    bool                                       palette_set;
    u32                                        palette_id;
} CoreDFBCreateSurface;

typedef struct {
    DFBResult                                  result;
    u32                                        surface_id;
    void*                                      surface_ptr;
} CoreDFBCreateSurfaceReturn;


/*
 * CoreDFB_CreatePalette
 */
typedef struct {
    u32                                        size;
} CoreDFBCreatePalette;

typedef struct {
    DFBResult                                  result;
    u32                                        palette_id;
    void*                                      palette_ptr;
} CoreDFBCreatePaletteReturn;


/*
 * CoreDFB_CreateState
 */
typedef struct {
} CoreDFBCreateState;

typedef struct {
    DFBResult                                  result;
    u32                                        state_id;
    void*                                      state_ptr;
} CoreDFBCreateStateReturn;


/*
 * CoreDFB_WaitIdle
 */
typedef struct {
} CoreDFBWaitIdle;

typedef struct {
    DFBResult                                  result;
} CoreDFBWaitIdleReturn;


/*
 * CoreDFB_CreateImageProvider
 */
typedef struct {
    u32                                        buffer_call;
} CoreDFBCreateImageProvider;

typedef struct {
    DFBResult                                  result;
    u32                                        call;
} CoreDFBCreateImageProviderReturn;


/*
 * CoreDFB_AllowSurface
 */
typedef struct {
    u32                                        surface_id;
    u32                                        executable_length;
    /* 'executable_length' char follow (executable) */
} CoreDFBAllowSurface;

typedef struct {
    DFBResult                                  result;
} CoreDFBAllowSurfaceReturn;


/*
 * CoreDFB_GetSurface
 */
typedef struct {
    u32                                        surface_id;
} CoreDFBGetSurface;

typedef struct {
    DFBResult                                  result;
    u32                                        surface_id;
    void*                                      surface_ptr;
} CoreDFBGetSurfaceReturn;


/*
 * CoreDFB_ClipboardSet
 */
typedef struct {
    u32                                        mime_type_size;
    u32                                        data_size;
    u64                                        timestamp_us;
    /* 'mime_type_size' char follow (mime_type) */
    /* 'data_size' char follow (data) */
} CoreDFBClipboardSet;

typedef struct {
    DFBResult                                  result;
} CoreDFBClipboardSetReturn;


/*
 * CoreDFB_ClipboardGet
 */
typedef struct {
} CoreDFBClipboardGet;

typedef struct {
    DFBResult                                  result;
    u32                                        mime_type_size;
    u32                                        data_size;
    /* 'mime_type_size' char follow (mime_type) */
    /* 'data_size' char follow (data) */
} CoreDFBClipboardGetReturn;


/*
 * CoreDFB_ClipboardGetTimestamp
 */
typedef struct {
} CoreDFBClipboardGetTimestamp;

typedef struct {
    DFBResult                                  result;
    u64                                        timestamp_us;
} CoreDFBClipboardGetTimestampReturn;

typedef struct _ICore ICore;
typedef struct _ICoreReal ICoreReal;
typedef struct _ICoreRequestor ICoreRequestor;

struct _ICore{
	CoreDFB *core;
	CoreDFB *obj;

    DFBResult (*Initialize)(ICore *thiz);

    DFBResult (*Register)(ICore *thiz, u32 slave_call);

    DFBResult (*CreateSurface)(ICore *thiz,
                    const CoreSurfaceConfig                   *config,
                    CoreSurfaceTypeFlags                       type,
                    u64                                        resource_id,
                    CorePalette                               *palette,
                    CoreSurface                              **ret_surface);

    DFBResult (*CreatePalette)(ICore *thiz, u32 size, CorePalette **ret_palette);

    DFBResult (*CreateState)(ICore *thiz, CoreGraphicsState **ret_state);

    DFBResult (*WaitIdle)(ICore *thiz);

    DFBResult (*CreateImageProvider)(ICore *thiz, u32 buffer_call, u32 *ret_call);

    DFBResult (*AllowSurface)(ICore *thiz, CoreSurface *surface, const char *executable, u32 executable_length);

    DFBResult (*GetSurface)(ICore *thiz, u32 surface_id, CoreSurface **ret_surface);

    DFBResult (*ClipboardSet)(ICore *thiz,
                    const char *mime_type,
                    u32 mime_type_size,
                    const char *data,
                    u32 data_size,
                    u64 timestamp_us);

    DFBResult (*ClipboardGet)(ICore *thiz,
                    char *ret_mime_type,
                    u32 *ret_mime_type_size,
                    char *ret_data,
                    u32 *ret_data_size);

    DFBResult (*ClipboardGetTimestamp)(ICore *thiz, u64 *ret_timestamp_us);

};

struct _ICoreReal{
	ICore base;
};

void ICoreRealInit(ICoreReal *thiz, CoreDFB *core, CoreDFB *obj);

struct _ICoreRequestor{
	ICore base;
};

void ICoreRequestorInit(ICoreRequestor *thiz, CoreDFB *core, CoreDFB *obj);


DFBResult CoreDFBDispatch__Dispatch( CoreDFB *obj,
                    FusionID      caller,
                    int           method,
                    void         *ptr,
                    unsigned int  length,
                    void         *ret_ptr,
                    unsigned int  ret_size,
                    unsigned int *ret_length );

#endif
