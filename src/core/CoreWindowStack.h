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

#ifndef ___CoreWindowStack__H___
#define ___CoreWindowStack__H___

#include <core/CoreWindowStack_includes.h>

/**********************************************************************************************************************
 * CoreWindowStack
 */

DFBResult CoreWindowStack_RepaintAll(
                    CoreWindowStack                           *obj
);

DFBResult CoreWindowStack_CursorEnable(
                    CoreWindowStack                           *obj,
                    bool                                       enable);

DFBResult CoreWindowStack_CursorSetShape(
                    CoreWindowStack                           *obj,
                    CoreSurface                               *shape,
                    const DFBPoint                            *hotspot);

DFBResult CoreWindowStack_CursorSetOpacity(
                    CoreWindowStack                           *obj,
                    u8                                         opacity);

DFBResult CoreWindowStack_CursorSetAcceleration(
                    CoreWindowStack                           *obj,
                    u32                                        numerator,
                    u32                                        denominator,
                    u32                                        threshold);

DFBResult CoreWindowStack_CursorWarp(
                    CoreWindowStack                           *obj,
                    const DFBPoint                            *position);

DFBResult CoreWindowStack_CursorGetPosition(
                    CoreWindowStack                           *obj,
                    DFBPoint                                  *ret_position);

DFBResult CoreWindowStack_BackgroundSetMode(
                    CoreWindowStack                           *obj,
                    DFBDisplayLayerBackgroundMode              mode);

DFBResult CoreWindowStack_BackgroundSetImage(
                    CoreWindowStack                           *obj,
                    CoreSurface                               *image);

DFBResult CoreWindowStack_BackgroundSetColor(
                    CoreWindowStack                           *obj,
                    const DFBColor                            *color);

DFBResult CoreWindowStack_BackgroundSetColorIndex(
                    CoreWindowStack                           *obj,
                    s32                                        index);


void CoreWindowStack_Init_Dispatch(
                    CoreDFB              *core,
                    CoreWindowStack      *obj,
                    FusionCall           *call
);

void  CoreWindowStack_Deinit_Dispatch(
                    FusionCall           *call
);


/*
 * CoreWindowStack Calls
 */
typedef enum {
    CoreWindowStackCall_RepaintAll = 1,
    CoreWindowStackCall_CursorEnable = 2,
    CoreWindowStackCall_CursorSetShape = 3,
    CoreWindowStackCall_CursorSetOpacity = 4,
    CoreWindowStackCall_CursorSetAcceleration = 5,
    CoreWindowStackCall_CursorWarp = 6,
    CoreWindowStackCall_CursorGetPosition = 7,
    CoreWindowStackCall_BackgroundSetMode = 8,
    CoreWindowStackCall_BackgroundSetImage = 9,
    CoreWindowStackCall_BackgroundSetColor = 10,
    CoreWindowStackCall_BackgroundSetColorIndex = 11,
} CoreWindowStackCall;

/*
 * CoreWindowStack_RepaintAll
 */
typedef struct {
} CoreWindowStackRepaintAll;

typedef struct {
    DFBResult                                  result;
} CoreWindowStackRepaintAllReturn;


/*
 * CoreWindowStack_CursorEnable
 */
typedef struct {
    bool                                       enable;
} CoreWindowStackCursorEnable;

typedef struct {
    DFBResult                                  result;
} CoreWindowStackCursorEnableReturn;


/*
 * CoreWindowStack_CursorSetShape
 */
typedef struct {
    u32                                        shape_id;
    DFBPoint                                   hotspot;
} CoreWindowStackCursorSetShape;

typedef struct {
    DFBResult                                  result;
} CoreWindowStackCursorSetShapeReturn;


/*
 * CoreWindowStack_CursorSetOpacity
 */
typedef struct {
    u8                                         opacity;
} CoreWindowStackCursorSetOpacity;

typedef struct {
    DFBResult                                  result;
} CoreWindowStackCursorSetOpacityReturn;


/*
 * CoreWindowStack_CursorSetAcceleration
 */
typedef struct {
    u32                                        numerator;
    u32                                        denominator;
    u32                                        threshold;
} CoreWindowStackCursorSetAcceleration;

typedef struct {
    DFBResult                                  result;
} CoreWindowStackCursorSetAccelerationReturn;


/*
 * CoreWindowStack_CursorWarp
 */
typedef struct {
    DFBPoint                                   position;
} CoreWindowStackCursorWarp;

typedef struct {
    DFBResult                                  result;
} CoreWindowStackCursorWarpReturn;


/*
 * CoreWindowStack_CursorGetPosition
 */
typedef struct {
} CoreWindowStackCursorGetPosition;

typedef struct {
    DFBResult                                  result;
    DFBPoint                                   position;
} CoreWindowStackCursorGetPositionReturn;


/*
 * CoreWindowStack_BackgroundSetMode
 */
typedef struct {
    DFBDisplayLayerBackgroundMode              mode;
} CoreWindowStackBackgroundSetMode;

typedef struct {
    DFBResult                                  result;
} CoreWindowStackBackgroundSetModeReturn;


/*
 * CoreWindowStack_BackgroundSetImage
 */
typedef struct {
    u32                                        image_id;
} CoreWindowStackBackgroundSetImage;

typedef struct {
    DFBResult                                  result;
} CoreWindowStackBackgroundSetImageReturn;


/*
 * CoreWindowStack_BackgroundSetColor
 */
typedef struct {
    DFBColor                                   color;
} CoreWindowStackBackgroundSetColor;

typedef struct {
    DFBResult                                  result;
} CoreWindowStackBackgroundSetColorReturn;


/*
 * CoreWindowStack_BackgroundSetColorIndex
 */
typedef struct {
    s32                                        index;
} CoreWindowStackBackgroundSetColorIndex;

typedef struct {
    DFBResult                                  result;
} CoreWindowStackBackgroundSetColorIndexReturn;



typedef struct _IWindowStack IWindowStack;
typedef struct _IWindowStackReal IWindowStackReal;
typedef struct _IWindowStackRequestor IWindowStackRequestor;

struct _IWindowStack{
	CoreDFB *core;
    CoreWindowStack *obj;

    DFBResult (*RepaintAll)(IWindowStack *thiz

    );

    DFBResult (*CursorEnable)(IWindowStack *thiz,
                    bool                                       enable
    );

    DFBResult (*CursorSetShape)(IWindowStack *thiz,
                    CoreSurface                               *shape,
                    const DFBPoint                            *hotspot
    );

    DFBResult (*CursorSetOpacity)(IWindowStack *thiz,
                    u8                                         opacity
    );

    DFBResult (*CursorSetAcceleration)(IWindowStack *thiz,
                    u32                                        numerator,
                    u32                                        denominator,
                    u32                                        threshold
    );

    DFBResult (*CursorWarp)(IWindowStack *thiz,
                    const DFBPoint                            *position
    );

    DFBResult (*CursorGetPosition)(IWindowStack *thiz,
                    DFBPoint                                  *ret_position
    );

    DFBResult (*BackgroundSetMode)(IWindowStack *thiz,
                    DFBDisplayLayerBackgroundMode              mode
    );

    DFBResult (*BackgroundSetImage)(IWindowStack *thiz,
                    CoreSurface                               *image
    );

    DFBResult (*BackgroundSetColor)(IWindowStack *thiz,
                    const DFBColor                            *color
    );

    DFBResult (*BackgroundSetColorIndex)(IWindowStack *thiz,
                    s32                                        index
    );
};


struct _IWindowStackReal
{
	IWindowStack base;
};

void IWindowStackRealInit(IWindowStackReal *thiz, CoreDFB *core, CoreWindowStack *obj);


struct _IWindowStackRequestor
{
	IWindowStack base;
};

void IWindowStackRequestorInit(IWindowStackRequestor *thiz, CoreDFB *core, CoreWindowStack *obj);

DFBResult CoreWindowStackDispatch__Dispatch( CoreWindowStack *obj,
                    FusionID      caller,
                    int           method,
                    void         *ptr,
                    unsigned int  length,
                    void         *ret_ptr,
                    unsigned int  ret_size,
                    unsigned int *ret_length );


#endif
