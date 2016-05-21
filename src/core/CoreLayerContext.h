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

#ifndef ___CoreLayerContext__H___
#define ___CoreLayerContext__H___

#include <core/CoreLayerContext_includes.h>

/**********************************************************************************************************************
 * CoreLayerContext
 */

DFBResult CoreLayerContext_GetPrimaryRegion(
                    CoreLayerContext                          *obj,
                    bool                                       create,
                    CoreLayerRegion                          **ret_region);

DFBResult CoreLayerContext_TestConfiguration(
                    CoreLayerContext                          *obj,
                    const DFBDisplayLayerConfig               *config,
                    DFBDisplayLayerConfigFlags                *ret_failed);

DFBResult CoreLayerContext_SetConfiguration(
                    CoreLayerContext                          *obj,
                    const DFBDisplayLayerConfig               *config);

DFBResult CoreLayerContext_SetSrcColorKey(
                    CoreLayerContext                          *obj,
                    const DFBColorKey                         *key);

DFBResult CoreLayerContext_SetDstColorKey(
                    CoreLayerContext                          *obj,
                    const DFBColorKey                         *key);

DFBResult CoreLayerContext_SetSourceRectangle(
                    CoreLayerContext                          *obj,
                    const DFBRectangle                        *rectangle);

DFBResult CoreLayerContext_SetScreenLocation(
                    CoreLayerContext                          *obj,
                    const DFBLocation                         *location);

DFBResult CoreLayerContext_SetScreenRectangle(
                    CoreLayerContext                          *obj,
                    const DFBRectangle                        *rectangle);

DFBResult CoreLayerContext_SetScreenPosition(
                    CoreLayerContext                          *obj,
                    const DFBPoint                            *position);

DFBResult CoreLayerContext_SetOpacity(
                    CoreLayerContext                          *obj,
                    u8                                         opacity);

DFBResult CoreLayerContext_SetRotation(
                    CoreLayerContext                          *obj,
                    s32                                        rotation);

DFBResult CoreLayerContext_SetColorAdjustment(
                    CoreLayerContext                          *obj,
                    const DFBColorAdjustment                  *adjustment);

DFBResult CoreLayerContext_SetStereoDepth(
                    CoreLayerContext                          *obj,
                    bool                                       follow_video,
                    s32                                        z);

DFBResult CoreLayerContext_SetFieldParity(
                    CoreLayerContext                          *obj,
                    u32                                        field);

DFBResult CoreLayerContext_SetClipRegions(
                    CoreLayerContext                          *obj,
                    const DFBRegion                           *regions,
                    u32                                        num,
                    bool                                       positive);

DFBResult CoreLayerContext_CreateWindow(
                    CoreLayerContext                          *obj,
                    const DFBWindowDescription                *description,
                    CoreWindow                               **ret_window);

DFBResult CoreLayerContext_FindWindow(
                    CoreLayerContext                          *obj,
                    DFBWindowID                                window_id,
                    CoreWindow                               **ret_window);

DFBResult CoreLayerContext_FindWindowByResourceID(
                    CoreLayerContext                          *obj,
                    u64                                        resource_id,
                    CoreWindow                               **ret_window);


void CoreLayerContext_Init_Dispatch(
                    CoreDFB              *core,
                    CoreLayerContext     *obj,
                    FusionCall           *call
);

void  CoreLayerContext_Deinit_Dispatch(
                    FusionCall           *call
);

/*
 * CoreLayerContext Calls
 */
typedef enum {
    CoreLayerContextCall_GetPrimaryRegion = 1,
    CoreLayerContextCall_TestConfiguration = 2,
    CoreLayerContextCall_SetConfiguration = 3,
    CoreLayerContextCall_SetSrcColorKey = 4,
    CoreLayerContextCall_SetDstColorKey = 5,
    CoreLayerContextCall_SetSourceRectangle = 6,
    CoreLayerContextCall_SetScreenLocation = 7,
    CoreLayerContextCall_SetScreenRectangle = 8,
    CoreLayerContextCall_SetScreenPosition = 9,
    CoreLayerContextCall_SetOpacity = 10,
    CoreLayerContextCall_SetRotation = 11,
    CoreLayerContextCall_SetColorAdjustment = 12,
    CoreLayerContextCall_SetStereoDepth = 13,
    CoreLayerContextCall_SetFieldParity = 14,
    CoreLayerContextCall_SetClipRegions = 15,
    CoreLayerContextCall_CreateWindow = 16,
    CoreLayerContextCall_FindWindow = 17,
    CoreLayerContextCall_FindWindowByResourceID = 18,
} CoreLayerContextCall;

/*
 * CoreLayerContext_GetPrimaryRegion
 */
typedef struct {
    bool                                       create;
} CoreLayerContextGetPrimaryRegion;

typedef struct {
    DFBResult                                  result;
    u32                                        region_id;
    void*                                      region_ptr;
} CoreLayerContextGetPrimaryRegionReturn;


/*
 * CoreLayerContext_TestConfiguration
 */
typedef struct {
    DFBDisplayLayerConfig                      config;
} CoreLayerContextTestConfiguration;

typedef struct {
    DFBResult                                  result;
    DFBDisplayLayerConfigFlags                 failed;
} CoreLayerContextTestConfigurationReturn;


/*
 * CoreLayerContext_SetConfiguration
 */
typedef struct {
    DFBDisplayLayerConfig                      config;
} CoreLayerContextSetConfiguration;

typedef struct {
    DFBResult                                  result;
} CoreLayerContextSetConfigurationReturn;


/*
 * CoreLayerContext_SetSrcColorKey
 */
typedef struct {
    DFBColorKey                                key;
} CoreLayerContextSetSrcColorKey;

typedef struct {
    DFBResult                                  result;
} CoreLayerContextSetSrcColorKeyReturn;


/*
 * CoreLayerContext_SetDstColorKey
 */
typedef struct {
    DFBColorKey                                key;
} CoreLayerContextSetDstColorKey;

typedef struct {
    DFBResult                                  result;
} CoreLayerContextSetDstColorKeyReturn;


/*
 * CoreLayerContext_SetSourceRectangle
 */
typedef struct {
    DFBRectangle                               rectangle;
} CoreLayerContextSetSourceRectangle;

typedef struct {
    DFBResult                                  result;
} CoreLayerContextSetSourceRectangleReturn;


/*
 * CoreLayerContext_SetScreenLocation
 */
typedef struct {
    DFBLocation                                location;
} CoreLayerContextSetScreenLocation;

typedef struct {
    DFBResult                                  result;
} CoreLayerContextSetScreenLocationReturn;


/*
 * CoreLayerContext_SetScreenRectangle
 */
typedef struct {
    DFBRectangle                               rectangle;
} CoreLayerContextSetScreenRectangle;

typedef struct {
    DFBResult                                  result;
} CoreLayerContextSetScreenRectangleReturn;


/*
 * CoreLayerContext_SetScreenPosition
 */
typedef struct {
    DFBPoint                                   position;
} CoreLayerContextSetScreenPosition;

typedef struct {
    DFBResult                                  result;
} CoreLayerContextSetScreenPositionReturn;


/*
 * CoreLayerContext_SetOpacity
 */
typedef struct {
    u8                                         opacity;
} CoreLayerContextSetOpacity;

typedef struct {
    DFBResult                                  result;
} CoreLayerContextSetOpacityReturn;


/*
 * CoreLayerContext_SetRotation
 */
typedef struct {
    s32                                        rotation;
} CoreLayerContextSetRotation;

typedef struct {
    DFBResult                                  result;
} CoreLayerContextSetRotationReturn;


/*
 * CoreLayerContext_SetColorAdjustment
 */
typedef struct {
    DFBColorAdjustment                         adjustment;
} CoreLayerContextSetColorAdjustment;

typedef struct {
    DFBResult                                  result;
} CoreLayerContextSetColorAdjustmentReturn;


/*
 * CoreLayerContext_SetStereoDepth
 */
typedef struct {
    bool                                       follow_video;
    s32                                        z;
} CoreLayerContextSetStereoDepth;

typedef struct {
    DFBResult                                  result;
} CoreLayerContextSetStereoDepthReturn;


/*
 * CoreLayerContext_SetFieldParity
 */
typedef struct {
    u32                                        field;
} CoreLayerContextSetFieldParity;

typedef struct {
    DFBResult                                  result;
} CoreLayerContextSetFieldParityReturn;


/*
 * CoreLayerContext_SetClipRegions
 */
typedef struct {
    u32                                        num;
    bool                                       positive;
    /* 'num' DFBRegion follow (regions) */
} CoreLayerContextSetClipRegions;

typedef struct {
    DFBResult                                  result;
} CoreLayerContextSetClipRegionsReturn;


/*
 * CoreLayerContext_CreateWindow
 */
typedef struct {
    DFBWindowDescription                       description;
} CoreLayerContextCreateWindow;

typedef struct {
    DFBResult                                  result;
    u32                                        window_id;
    void*                                      window_ptr;
} CoreLayerContextCreateWindowReturn;


/*
 * CoreLayerContext_FindWindow
 */
typedef struct {
    DFBWindowID                                window_id;
} CoreLayerContextFindWindow;

typedef struct {
    DFBResult                                  result;
    u32                                        window_id;
    void*                                      window_ptr;
} CoreLayerContextFindWindowReturn;


/*
 * CoreLayerContext_FindWindowByResourceID
 */
typedef struct {
    u64                                        resource_id;
} CoreLayerContextFindWindowByResourceID;

typedef struct {
    DFBResult                                  result;
    u32                                        window_id;
    void*                                      window_ptr;
} CoreLayerContextFindWindowByResourceIDReturn;


typedef struct _ILayerContext ILayerContext;
typedef struct _ILayerContextReal ILayerContextReal;
typedef struct _ILayerContextRequestor ILayerContextRequestor;


struct _ILayerContext
{
    CoreLayerContext *obj;
	CoreDFB *core;

    DFBResult (*GetPrimaryRegion)(ILayerContext *thiz,
                    bool                                       create,
                    CoreLayerRegion                          **ret_region
    );

    DFBResult (*TestConfiguration)(ILayerContext *thiz,
                    const DFBDisplayLayerConfig               *config,
                    DFBDisplayLayerConfigFlags                *ret_failed
    );

    DFBResult (*SetConfiguration)(ILayerContext *thiz,
                    const DFBDisplayLayerConfig               *config
    );

    DFBResult (*SetSrcColorKey)(ILayerContext *thiz,
                    const DFBColorKey                         *key
    );

    DFBResult (*SetDstColorKey)(ILayerContext *thiz,
                    const DFBColorKey                         *key
    );

    DFBResult (*SetSourceRectangle)(ILayerContext *thiz,
                    const DFBRectangle                        *rectangle
    );

    DFBResult (*SetScreenLocation)(ILayerContext *thiz,
                    const DFBLocation                         *location
    );

    DFBResult (*SetScreenRectangle)(ILayerContext *thiz,
                    const DFBRectangle                        *rectangle
    );

    DFBResult (*SetScreenPosition)(ILayerContext *thiz,
                    const DFBPoint                            *position
    );

    DFBResult (*SetOpacity)(ILayerContext *thiz,
                    u8                                         opacity
    );

    DFBResult (*SetRotation)(ILayerContext *thiz,
                    s32                                        rotation
    );

    DFBResult (*SetColorAdjustment)(ILayerContext *thiz,
                    const DFBColorAdjustment                  *adjustment
    );

    DFBResult (*SetStereoDepth)(ILayerContext *thiz,
                    bool                                       follow_video,
                    s32                                        z
    );

    DFBResult (*SetFieldParity)(ILayerContext *thiz,
                    u32                                        field
    );

    DFBResult (*SetClipRegions)(ILayerContext *thiz,
                    const DFBRegion                           *regions,
                    u32                                        num,
                    bool                                       positive
    );

    DFBResult (*CreateWindow)(ILayerContext *thiz,
                    const DFBWindowDescription                *description,
                    CoreWindow                               **ret_window
    );

    DFBResult (*FindWindow)(ILayerContext *thiz,
                    DFBWindowID                                window_id,
                    CoreWindow                               **ret_window
    );

    DFBResult (*FindWindowByResourceID)(ILayerContext *thiz,
                    u64                                        resource_id,
                    CoreWindow                               **ret_window
    );

};


struct _ILayerContextReal
{
	ILayerContext base;
};

void ILayerContextRealInit(ILayerContextReal *thiz, CoreDFB *core, CoreLayerContext *obj);

struct _ILayerContextRequestor
{
	ILayerContext base;
};

void ILayerContextRequestorInit(ILayerContextRequestor *thiz, CoreDFB *core, CoreLayerContext *obj);

DFBResult CoreLayerContextDispatch__Dispatch( CoreLayerContext *obj,
                    FusionID      caller,
                    int           method,
                    void         *ptr,
                    unsigned int  length,
                    void         *ret_ptr,
                    unsigned int  ret_size,
                    unsigned int *ret_length );

#endif
