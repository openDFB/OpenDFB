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

#ifndef ___CoreScreen__H___
#define ___CoreScreen__H___

#include <core/CoreScreen_includes.h>

/**********************************************************************************************************************
 * CoreScreen
 */

DFBResult CoreScreen_SetPowerMode(
                    CoreScreen                                *obj,
                    DFBScreenPowerMode                         mode);

DFBResult CoreScreen_WaitVSync(
                    CoreScreen                                *obj
);

DFBResult CoreScreen_GetVSyncCount(
                    CoreScreen                                *obj,
                    u64                                       *ret_count);

DFBResult CoreScreen_TestMixerConfig(
                    CoreScreen                                *obj,
                    u32                                        mixer,
                    const DFBScreenMixerConfig                *config,
                    DFBScreenMixerConfigFlags                 *ret_failed);

DFBResult CoreScreen_SetMixerConfig(
                    CoreScreen                                *obj,
                    u32                                        mixer,
                    const DFBScreenMixerConfig                *config);

DFBResult CoreScreen_TestEncoderConfig(
                    CoreScreen                                *obj,
                    u32                                        encoder,
                    const DFBScreenEncoderConfig              *config,
                    DFBScreenEncoderConfigFlags               *ret_failed);

DFBResult CoreScreen_SetEncoderConfig(
                    CoreScreen                                *obj,
                    u32                                        encoder,
                    const DFBScreenEncoderConfig              *config);

DFBResult CoreScreen_TestOutputConfig(
                    CoreScreen                                *obj,
                    u32                                        output,
                    const DFBScreenOutputConfig               *config,
                    DFBScreenOutputConfigFlags                *ret_failed);

DFBResult CoreScreen_SetOutputConfig(
                    CoreScreen                                *obj,
                    u32                                        output,
                    const DFBScreenOutputConfig               *config);

DFBResult CoreScreen_GetScreenSize(
                    CoreScreen                                *obj,
                    DFBDimension                              *ret_size);

DFBResult CoreScreen_GetLayerDimension(
                    CoreScreen                                *obj,
                    CoreLayer                                 *layer,
                    DFBDimension                              *ret_size);


void CoreScreen_Init_Dispatch(
                    CoreDFB              *core,
                    CoreScreen           *obj,
                    FusionCall           *call
);

void  CoreScreen_Deinit_Dispatch(
                    FusionCall           *call
);


/*
 * CoreScreen Calls
 */
typedef enum {
    CoreScreenCall_SetPowerMode = 1,
    CoreScreenCall_WaitVSync = 2,
    CoreScreenCall_GetVSyncCount = 3,
    CoreScreenCall_TestMixerConfig = 4,
    CoreScreenCall_SetMixerConfig = 5,
    CoreScreenCall_TestEncoderConfig = 6,
    CoreScreenCall_SetEncoderConfig = 7,
    CoreScreenCall_TestOutputConfig = 8,
    CoreScreenCall_SetOutputConfig = 9,
    CoreScreenCall_GetScreenSize = 10,
    CoreScreenCall_GetLayerDimension = 11,
} CoreScreenCall;

/*
 * CoreScreen_SetPowerMode
 */
typedef struct {
    DFBScreenPowerMode                         mode;
} CoreScreenSetPowerMode;

typedef struct {
    DFBResult                                  result;
} CoreScreenSetPowerModeReturn;


/*
 * CoreScreen_WaitVSync
 */
typedef struct {
} CoreScreenWaitVSync;

typedef struct {
    DFBResult                                  result;
} CoreScreenWaitVSyncReturn;


/*
 * CoreScreen_GetVSyncCount
 */
typedef struct {
} CoreScreenGetVSyncCount;

typedef struct {
    DFBResult                                  result;
    u64                                        count;
} CoreScreenGetVSyncCountReturn;


/*
 * CoreScreen_TestMixerConfig
 */
typedef struct {
    u32                                        mixer;
    DFBScreenMixerConfig                       config;
} CoreScreenTestMixerConfig;

typedef struct {
    DFBResult                                  result;
    DFBScreenMixerConfigFlags                  failed;
} CoreScreenTestMixerConfigReturn;


/*
 * CoreScreen_SetMixerConfig
 */
typedef struct {
    u32                                        mixer;
    DFBScreenMixerConfig                       config;
} CoreScreenSetMixerConfig;

typedef struct {
    DFBResult                                  result;
} CoreScreenSetMixerConfigReturn;


/*
 * CoreScreen_TestEncoderConfig
 */
typedef struct {
    u32                                        encoder;
    DFBScreenEncoderConfig                     config;
} CoreScreenTestEncoderConfig;

typedef struct {
    DFBResult                                  result;
    DFBScreenEncoderConfigFlags                failed;
} CoreScreenTestEncoderConfigReturn;


/*
 * CoreScreen_SetEncoderConfig
 */
typedef struct {
    u32                                        encoder;
    DFBScreenEncoderConfig                     config;
} CoreScreenSetEncoderConfig;

typedef struct {
    DFBResult                                  result;
} CoreScreenSetEncoderConfigReturn;


/*
 * CoreScreen_TestOutputConfig
 */
typedef struct {
    u32                                        output;
    DFBScreenOutputConfig                      config;
} CoreScreenTestOutputConfig;

typedef struct {
    DFBResult                                  result;
    DFBScreenOutputConfigFlags                 failed;
} CoreScreenTestOutputConfigReturn;


/*
 * CoreScreen_SetOutputConfig
 */
typedef struct {
    u32                                        output;
    DFBScreenOutputConfig                      config;
} CoreScreenSetOutputConfig;

typedef struct {
    DFBResult                                  result;
} CoreScreenSetOutputConfigReturn;


/*
 * CoreScreen_GetScreenSize
 */
typedef struct {
} CoreScreenGetScreenSize;

typedef struct {
    DFBResult                                  result;
    DFBDimension                               size;
} CoreScreenGetScreenSizeReturn;


/*
 * CoreScreen_GetLayerDimension
 */
typedef struct {
    u32                                        layer_id;
} CoreScreenGetLayerDimension;

typedef struct {
    DFBResult                                  result;
    DFBDimension                               size;
} CoreScreenGetLayerDimensionReturn;


typedef struct _IScreen IScreen;
typedef struct _IScreenReal IScreenReal;
typedef struct _IScreenRequestor IScreenRequestor;


struct _IScreen
{
    CoreScreen *obj;
	CoreDFB *core;

    DFBResult (*SetPowerMode)(IScreen *thiz,
                    DFBScreenPowerMode                         mode
    );

    DFBResult (*WaitVSync)(IScreen *thiz

    );

    DFBResult (*GetVSyncCount)(IScreen *thiz,
                    u64                                       *ret_count
    );

    DFBResult (*TestMixerConfig)(IScreen *thiz,
                    u32                                        mixer,
                    const DFBScreenMixerConfig                *config,
                    DFBScreenMixerConfigFlags                 *ret_failed
    );

    DFBResult (*SetMixerConfig)(IScreen *thiz,
                    u32                                        mixer,
                    const DFBScreenMixerConfig                *config
    );

    DFBResult (*TestEncoderConfig)(IScreen *thiz,
                    u32                                        encoder,
                    const DFBScreenEncoderConfig              *config,
                    DFBScreenEncoderConfigFlags               *ret_failed
    );

    DFBResult (*SetEncoderConfig)(IScreen *thiz,
                    u32                                        encoder,
                    const DFBScreenEncoderConfig              *config
    );

    DFBResult (*TestOutputConfig)(IScreen *thiz,
                    u32                                        output,
                    const DFBScreenOutputConfig               *config,
                    DFBScreenOutputConfigFlags                *ret_failed
    );

    DFBResult (*SetOutputConfig)(IScreen *thiz,
                    u32                                        output,
                    const DFBScreenOutputConfig               *config
    );

    DFBResult (*GetScreenSize)(IScreen *thiz,
                    DFBDimension                              *ret_size
    );

    DFBResult (*GetLayerDimension)(IScreen *thiz,
                    CoreLayer                                 *layer,
                    DFBDimension                              *ret_size
    );

};


struct _IScreenReal
{
	IScreen base;
};

void IScreenRealInit(IScreenReal *thiz, CoreDFB *core, CoreScreen *obj);


struct _IScreenRequestor
{
	IScreen base;
};

void IScreenRequestorInit(IScreenRequestor *thiz, CoreDFB *core, CoreScreen *obj);

DFBResult CoreScreenDispatch__Dispatch( CoreScreen *obj,
                    FusionID      caller,
                    int           method,
                    void         *ptr,
                    unsigned int  length,
                    void         *ret_ptr,
                    unsigned int  ret_size,
                    unsigned int *ret_length );

#endif
