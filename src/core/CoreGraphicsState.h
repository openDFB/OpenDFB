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

#ifndef ___CoreGraphicsState__H___
#define ___CoreGraphicsState__H___

#include <core/CoreGraphicsState_includes.h>

/**********************************************************************************************************************
 * CoreGraphicsState
 */


DFBResult CoreGraphicsState_SetDrawingFlags(
                    CoreGraphicsState                         *obj,
                    DFBSurfaceDrawingFlags                     flags);

DFBResult CoreGraphicsState_SetBlittingFlags(
                    CoreGraphicsState                         *obj,
                    DFBSurfaceBlittingFlags                    flags);

DFBResult CoreGraphicsState_SetClip(
                    CoreGraphicsState                         *obj,
                    const DFBRegion                           *region);

DFBResult CoreGraphicsState_SetColor(
                    CoreGraphicsState                         *obj,
                    const DFBColor                            *color);

DFBResult CoreGraphicsState_SetColorAndIndex(
                    CoreGraphicsState                         *obj,
                    const DFBColor                            *color,
                    u32                                        index);

DFBResult CoreGraphicsState_SetSrcBlend(
                    CoreGraphicsState                         *obj,
                    DFBSurfaceBlendFunction                    function);

DFBResult CoreGraphicsState_SetDstBlend(
                    CoreGraphicsState                         *obj,
                    DFBSurfaceBlendFunction                    function);

DFBResult CoreGraphicsState_SetSrcColorKey(
                    CoreGraphicsState                         *obj,
                    u32                                        key);

DFBResult CoreGraphicsState_SetDstColorKey(
                    CoreGraphicsState                         *obj,
                    u32                                        key);

DFBResult CoreGraphicsState_SetDestination(
                    CoreGraphicsState                         *obj,
                    CoreSurface                               *surface);

DFBResult CoreGraphicsState_SetSource(
                    CoreGraphicsState                         *obj,
                    CoreSurface                               *surface);

DFBResult CoreGraphicsState_SetSourceMask(
                    CoreGraphicsState                         *obj,
                    CoreSurface                               *surface);

DFBResult CoreGraphicsState_SetSourceMaskVals(
                    CoreGraphicsState                         *obj,
                    const DFBPoint                            *offset,
                    DFBSurfaceMaskFlags                        flags);

DFBResult CoreGraphicsState_SetIndexTranslation(
                    CoreGraphicsState                         *obj,
                    const s32                                 *indices,
                    u32                                        num);

DFBResult CoreGraphicsState_SetColorKey(
                    CoreGraphicsState                         *obj,
                    const DFBColorKey                         *key);

DFBResult CoreGraphicsState_SetRenderOptions(
                    CoreGraphicsState                         *obj,
                    DFBSurfaceRenderOptions                    options);

DFBResult CoreGraphicsState_SetMatrix(
                    CoreGraphicsState                         *obj,
                    const s32                                 *values);

DFBResult CoreGraphicsState_SetSource2(
                    CoreGraphicsState                         *obj,
                    CoreSurface                               *surface);

DFBResult CoreGraphicsState_SetFrom(
                    CoreGraphicsState                         *obj,
                    CoreSurfaceBufferRole                      role,
                    DFBSurfaceStereoEye                        eye);

DFBResult CoreGraphicsState_SetTo(
                    CoreGraphicsState                         *obj,
                    CoreSurfaceBufferRole                      role,
                    DFBSurfaceStereoEye                        eye);

DFBResult CoreGraphicsState_DrawRectangles(
                    CoreGraphicsState                         *obj,
                    const DFBRectangle                        *rects,
                    u32                                        num);

DFBResult CoreGraphicsState_DrawLines(
                    CoreGraphicsState                         *obj,
                    const DFBRegion                           *lines,
                    u32                                        num);

DFBResult CoreGraphicsState_FillRectangles(
                    CoreGraphicsState                         *obj,
                    const DFBRectangle                        *rects,
                    u32                                        num);

DFBResult CoreGraphicsState_FillTriangles(
                    CoreGraphicsState                         *obj,
                    const DFBTriangle                         *triangles,
                    u32                                        num);

DFBResult CoreGraphicsState_FillTrapezoids(
                    CoreGraphicsState                         *obj,
                    const DFBTrapezoid                        *trapezoids,
                    u32                                        num);

DFBResult CoreGraphicsState_FillSpans(
                    CoreGraphicsState                         *obj,
                    s32                                        y,
                    const DFBSpan                             *spans,
                    u32                                        num);

DFBResult CoreGraphicsState_Blit(
                    CoreGraphicsState                         *obj,
                    const DFBRectangle                        *rects,
                    const DFBPoint                            *points,
                    u32                                        num);

DFBResult CoreGraphicsState_Blit2(
                    CoreGraphicsState                         *obj,
                    const DFBRectangle                        *rects,
                    const DFBPoint                            *points1,
                    const DFBPoint                            *points2,
                    u32                                        num);

DFBResult CoreGraphicsState_StretchBlit(
                    CoreGraphicsState                         *obj,
                    const DFBRectangle                        *srects,
                    const DFBRectangle                        *drects,
                    u32                                        num);

DFBResult CoreGraphicsState_TileBlit(
                    CoreGraphicsState                         *obj,
                    const DFBRectangle                        *rects,
                    const DFBPoint                            *points1,
                    const DFBPoint                            *points2,
                    u32                                        num);

DFBResult CoreGraphicsState_TextureTriangles(
                    CoreGraphicsState                         *obj,
                    const DFBVertex                           *vertices,
                    u32                                        num,
                    DFBTriangleFormation                       formation);

DFBResult CoreGraphicsState_Flush(
                    CoreGraphicsState                         *obj
);

DFBResult CoreGraphicsState_ReleaseSource(
                    CoreGraphicsState                         *obj
);

DFBResult CoreGraphicsState_SetSrcConvolution(
                    CoreGraphicsState                         *obj,
                    const DFBConvolutionFilter                *filter);


void CoreGraphicsState_Init_Dispatch(
                    CoreDFB              *core,
                    CoreGraphicsState    *obj,
                    FusionCall           *call
);

void  CoreGraphicsState_Deinit_Dispatch(
                    FusionCall           *call
);

/*
 * CoreGraphicsState Calls
 */
typedef enum {
    CoreGraphicsStateCall_SetDrawingFlags = 1,
    CoreGraphicsStateCall_SetBlittingFlags = 2,
    CoreGraphicsStateCall_SetClip = 3,
    CoreGraphicsStateCall_SetColor = 4,
    CoreGraphicsStateCall_SetColorAndIndex = 5,
    CoreGraphicsStateCall_SetSrcBlend = 6,
    CoreGraphicsStateCall_SetDstBlend = 7,
    CoreGraphicsStateCall_SetSrcColorKey = 8,
    CoreGraphicsStateCall_SetDstColorKey = 9,
    CoreGraphicsStateCall_SetDestination = 10,
    CoreGraphicsStateCall_SetSource = 11,
    CoreGraphicsStateCall_SetSourceMask = 12,
    CoreGraphicsStateCall_SetSourceMaskVals = 13,
    CoreGraphicsStateCall_SetIndexTranslation = 14,
    CoreGraphicsStateCall_SetColorKey = 15,
    CoreGraphicsStateCall_SetRenderOptions = 16,
    CoreGraphicsStateCall_SetMatrix = 17,
    CoreGraphicsStateCall_SetSource2 = 18,
    CoreGraphicsStateCall_SetFrom = 19,
    CoreGraphicsStateCall_SetTo = 20,
    CoreGraphicsStateCall_DrawRectangles = 21,
    CoreGraphicsStateCall_DrawLines = 22,
    CoreGraphicsStateCall_FillRectangles = 23,
    CoreGraphicsStateCall_FillTriangles = 24,
    CoreGraphicsStateCall_FillTrapezoids = 25,
    CoreGraphicsStateCall_FillSpans = 26,
    CoreGraphicsStateCall_Blit = 27,
    CoreGraphicsStateCall_Blit2 = 28,
    CoreGraphicsStateCall_StretchBlit = 29,
    CoreGraphicsStateCall_TileBlit = 30,
    CoreGraphicsStateCall_TextureTriangles = 31,
    CoreGraphicsStateCall_Flush = 32,
    CoreGraphicsStateCall_ReleaseSource = 33,
    CoreGraphicsStateCall_SetSrcConvolution = 34,
} CoreGraphicsStateCall;

/*
 * CoreGraphicsState_SetDrawingFlags
 */
typedef struct {
    DFBSurfaceDrawingFlags                     flags;
} CoreGraphicsStateSetDrawingFlags;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetDrawingFlagsReturn;


/*
 * CoreGraphicsState_SetBlittingFlags
 */
typedef struct {
    DFBSurfaceBlittingFlags                    flags;
} CoreGraphicsStateSetBlittingFlags;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetBlittingFlagsReturn;


/*
 * CoreGraphicsState_SetClip
 */
typedef struct {
    DFBRegion                                  region;
} CoreGraphicsStateSetClip;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetClipReturn;


/*
 * CoreGraphicsState_SetColor
 */
typedef struct {
    DFBColor                                   color;
} CoreGraphicsStateSetColor;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetColorReturn;


/*
 * CoreGraphicsState_SetColorAndIndex
 */
typedef struct {
    DFBColor                                   color;
    u32                                        index;
} CoreGraphicsStateSetColorAndIndex;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetColorAndIndexReturn;


/*
 * CoreGraphicsState_SetSrcBlend
 */
typedef struct {
    DFBSurfaceBlendFunction                    function;
} CoreGraphicsStateSetSrcBlend;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetSrcBlendReturn;


/*
 * CoreGraphicsState_SetDstBlend
 */
typedef struct {
    DFBSurfaceBlendFunction                    function;
} CoreGraphicsStateSetDstBlend;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetDstBlendReturn;


/*
 * CoreGraphicsState_SetSrcColorKey
 */
typedef struct {
    u32                                        key;
} CoreGraphicsStateSetSrcColorKey;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetSrcColorKeyReturn;


/*
 * CoreGraphicsState_SetDstColorKey
 */
typedef struct {
    u32                                        key;
} CoreGraphicsStateSetDstColorKey;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetDstColorKeyReturn;


/*
 * CoreGraphicsState_SetDestination
 */
typedef struct {
    u32                                        surface_id;
} CoreGraphicsStateSetDestination;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetDestinationReturn;


/*
 * CoreGraphicsState_SetSource
 */
typedef struct {
    u32                                        surface_id;
} CoreGraphicsStateSetSource;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetSourceReturn;


/*
 * CoreGraphicsState_SetSourceMask
 */
typedef struct {
    u32                                        surface_id;
} CoreGraphicsStateSetSourceMask;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetSourceMaskReturn;


/*
 * CoreGraphicsState_SetSourceMaskVals
 */
typedef struct {
    DFBPoint                                   offset;
    DFBSurfaceMaskFlags                        flags;
} CoreGraphicsStateSetSourceMaskVals;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetSourceMaskValsReturn;


/*
 * CoreGraphicsState_SetIndexTranslation
 */
typedef struct {
    u32                                        num;
    /* 'num' s32 follow (indices) */
} CoreGraphicsStateSetIndexTranslation;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetIndexTranslationReturn;


/*
 * CoreGraphicsState_SetColorKey
 */
typedef struct {
    DFBColorKey                                key;
} CoreGraphicsStateSetColorKey;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetColorKeyReturn;


/*
 * CoreGraphicsState_SetRenderOptions
 */
typedef struct {
    DFBSurfaceRenderOptions                    options;
} CoreGraphicsStateSetRenderOptions;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetRenderOptionsReturn;


/*
 * CoreGraphicsState_SetMatrix
 */
typedef struct {
    /* '9' s32 follow (values) */
} CoreGraphicsStateSetMatrix;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetMatrixReturn;


/*
 * CoreGraphicsState_SetSource2
 */
typedef struct {
    u32                                        surface_id;
} CoreGraphicsStateSetSource2;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetSource2Return;


/*
 * CoreGraphicsState_SetFrom
 */
typedef struct {
    CoreSurfaceBufferRole                      role;
    DFBSurfaceStereoEye                        eye;
} CoreGraphicsStateSetFrom;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetFromReturn;


/*
 * CoreGraphicsState_SetTo
 */
typedef struct {
    CoreSurfaceBufferRole                      role;
    DFBSurfaceStereoEye                        eye;
} CoreGraphicsStateSetTo;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetToReturn;


/*
 * CoreGraphicsState_DrawRectangles
 */
typedef struct {
    u32                                        num;
    /* 'num' DFBRectangle follow (rects) */
} CoreGraphicsStateDrawRectangles;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateDrawRectanglesReturn;


/*
 * CoreGraphicsState_DrawLines
 */
typedef struct {
    u32                                        num;
    /* 'num' DFBRegion follow (lines) */
} CoreGraphicsStateDrawLines;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateDrawLinesReturn;


/*
 * CoreGraphicsState_FillRectangles
 */
typedef struct {
    u32                                        num;
    /* 'num' DFBRectangle follow (rects) */
} CoreGraphicsStateFillRectangles;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateFillRectanglesReturn;


/*
 * CoreGraphicsState_FillTriangles
 */
typedef struct {
    u32                                        num;
    /* 'num' DFBTriangle follow (triangles) */
} CoreGraphicsStateFillTriangles;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateFillTrianglesReturn;


/*
 * CoreGraphicsState_FillTrapezoids
 */
typedef struct {
    u32                                        num;
    /* 'num' DFBTrapezoid follow (trapezoids) */
} CoreGraphicsStateFillTrapezoids;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateFillTrapezoidsReturn;


/*
 * CoreGraphicsState_FillSpans
 */
typedef struct {
    s32                                        y;
    u32                                        num;
    /* 'num' DFBSpan follow (spans) */
} CoreGraphicsStateFillSpans;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateFillSpansReturn;


/*
 * CoreGraphicsState_Blit
 */
typedef struct {
    u32                                        num;
    /* 'num' DFBRectangle follow (rects) */
    /* 'num' DFBPoint follow (points) */
} CoreGraphicsStateBlit;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateBlitReturn;


/*
 * CoreGraphicsState_Blit2
 */
typedef struct {
    u32                                        num;
    /* 'num' DFBRectangle follow (rects) */
    /* 'num' DFBPoint follow (points1) */
    /* 'num' DFBPoint follow (points2) */
} CoreGraphicsStateBlit2;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateBlit2Return;


/*
 * CoreGraphicsState_StretchBlit
 */
typedef struct {
    u32                                        num;
    /* 'num' DFBRectangle follow (srects) */
    /* 'num' DFBRectangle follow (drects) */
} CoreGraphicsStateStretchBlit;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateStretchBlitReturn;


/*
 * CoreGraphicsState_TileBlit
 */
typedef struct {
    u32                                        num;
    /* 'num' DFBRectangle follow (rects) */
    /* 'num' DFBPoint follow (points1) */
    /* 'num' DFBPoint follow (points2) */
} CoreGraphicsStateTileBlit;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateTileBlitReturn;


/*
 * CoreGraphicsState_TextureTriangles
 */
typedef struct {
    u32                                        num;
    DFBTriangleFormation                       formation;
    /* 'num' DFBVertex follow (vertices) */
} CoreGraphicsStateTextureTriangles;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateTextureTrianglesReturn;


/*
 * CoreGraphicsState_Flush
 */
typedef struct {
} CoreGraphicsStateFlush;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateFlushReturn;


/*
 * CoreGraphicsState_ReleaseSource
 */
typedef struct {
} CoreGraphicsStateReleaseSource;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateReleaseSourceReturn;


/*
 * CoreGraphicsState_SetSrcConvolution
 */
typedef struct {
    DFBConvolutionFilter                       filter;
} CoreGraphicsStateSetSrcConvolution;

typedef struct {
    DFBResult                                  result;
} CoreGraphicsStateSetSrcConvolutionReturn;


typedef struct _IGraphicsState IGraphicsState;
typedef struct _IGraphicsStateReal IGraphicsStateReal;
typedef struct _IGraphicsStateRequestor IGraphicsStateRequestor;


struct _IGraphicsState
{
    CoreGraphicsState *obj;
	CoreDFB *core;

    DFBResult (*SetDrawingFlags)(IGraphicsState *thiz,
                    DFBSurfaceDrawingFlags                     flags
    );

    DFBResult (*SetBlittingFlags)(IGraphicsState *thiz,
                    DFBSurfaceBlittingFlags                    flags
    );

    DFBResult (*SetClip)(IGraphicsState *thiz,
                    const DFBRegion                           *region
    );

    DFBResult (*SetColor)(IGraphicsState *thiz,
                    const DFBColor                            *color
    );

    DFBResult (*SetColorAndIndex)(IGraphicsState *thiz,
                    const DFBColor                            *color,
                    u32                                        index
    );

    DFBResult (*SetSrcBlend)(IGraphicsState *thiz,
                    DFBSurfaceBlendFunction                    function
    );

    DFBResult (*SetDstBlend)(IGraphicsState *thiz,
                    DFBSurfaceBlendFunction                    function
    );

    DFBResult (*SetSrcColorKey)(IGraphicsState *thiz,
                    u32                                        key
    );

    DFBResult (*SetDstColorKey)(IGraphicsState *thiz,
                    u32                                        key
    );

    DFBResult (*SetDestination)(IGraphicsState *thiz,
                    CoreSurface                               *surface
    );

    DFBResult (*SetSource)(IGraphicsState *thiz,
                    CoreSurface                               *surface
    );

    DFBResult (*SetSourceMask)(IGraphicsState *thiz,
                    CoreSurface                               *surface
    );

    DFBResult (*SetSourceMaskVals)(IGraphicsState *thiz,
                    const DFBPoint                            *offset,
                    DFBSurfaceMaskFlags                        flags
    );

    DFBResult (*SetIndexTranslation)(IGraphicsState *thiz,
                    const s32                                 *indices,
                    u32                                        num
    );

    DFBResult (*SetColorKey)(IGraphicsState *thiz,
                    const DFBColorKey                         *key
    );

    DFBResult (*SetRenderOptions)(IGraphicsState *thiz,
                    DFBSurfaceRenderOptions                    options
    );

    DFBResult (*SetMatrix)(IGraphicsState *thiz,
                    const s32                                 *values
    );

    DFBResult (*SetSource2)(IGraphicsState *thiz,
                    CoreSurface                               *surface
    );

    DFBResult (*SetFrom)(IGraphicsState *thiz,
                    CoreSurfaceBufferRole                      role,
                    DFBSurfaceStereoEye                        eye
    );

    DFBResult (*SetTo)(IGraphicsState *thiz,
                    CoreSurfaceBufferRole                      role,
                    DFBSurfaceStereoEye                        eye
    );

    DFBResult (*DrawRectangles)(IGraphicsState *thiz,
                    const DFBRectangle                        *rects,
                    u32                                        num
    );

    DFBResult (*DrawLines)(IGraphicsState *thiz,
                    const DFBRegion                           *lines,
                    u32                                        num
    );

    DFBResult (*FillRectangles)(IGraphicsState *thiz,
                    const DFBRectangle                        *rects,
                    u32                                        num
    );

    DFBResult (*FillTriangles)(IGraphicsState *thiz,
                    const DFBTriangle                         *triangles,
                    u32                                        num
    );

    DFBResult (*FillTrapezoids)(IGraphicsState *thiz,
                    const DFBTrapezoid                        *trapezoids,
                    u32                                        num
    );

    DFBResult (*FillSpans)(IGraphicsState *thiz,
                    s32                                        y,
                    const DFBSpan                             *spans,
                    u32                                        num
    );

    DFBResult (*Blit)(IGraphicsState *thiz,
                    const DFBRectangle                        *rects,
                    const DFBPoint                            *points,
                    u32                                        num
    );

    DFBResult (*Blit2)(IGraphicsState *thiz,
                    const DFBRectangle                        *rects,
                    const DFBPoint                            *points1,
                    const DFBPoint                            *points2,
                    u32                                        num
    );

    DFBResult (*StretchBlit)(IGraphicsState *thiz,
                    const DFBRectangle                        *srects,
                    const DFBRectangle                        *drects,
                    u32                                        num
    );

    DFBResult (*TileBlit)(IGraphicsState *thiz,
                    const DFBRectangle                        *rects,
                    const DFBPoint                            *points1,
                    const DFBPoint                            *points2,
                    u32                                        num
    );

    DFBResult (*TextureTriangles)(IGraphicsState *thiz,
                    const DFBVertex                           *vertices,
                    u32                                        num,
                    DFBTriangleFormation                       formation
    );

    DFBResult (*Flush)(IGraphicsState *thiz

    );

    DFBResult (*ReleaseSource)(IGraphicsState *thiz

    );

    DFBResult (*SetSrcConvolution)(IGraphicsState *thiz,
                    const DFBConvolutionFilter                *filter
    );

};



struct _IGraphicsStateReal
{
	IGraphicsState base;
};

void IGraphicsStateRealInit(IGraphicsStateReal *thiz, CoreDFB *core, CoreGraphicsState *obj);


struct _IGraphicsStateRequestor
{
	IGraphicsState base;
};

void IGraphicsStateRequestorInit(IGraphicsStateRequestor *thiz, CoreDFB *core, CoreGraphicsState *obj);


DFBResult CoreGraphicsStateDispatch__Dispatch( CoreGraphicsState *obj,
                    FusionID      caller,
                    int           method,
                    void         *ptr,
                    unsigned int  length,
                    void         *ret_ptr,
                    unsigned int  ret_size,
                    unsigned int *ret_length );


#endif
