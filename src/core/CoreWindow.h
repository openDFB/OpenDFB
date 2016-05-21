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

#ifndef ___CoreWindow__H___
#define ___CoreWindow__H___

#include <core/CoreWindow_includes.h>

/**********************************************************************************************************************
 * CoreWindow
 */

DFBResult CoreWindow_Repaint(
                    CoreWindow                                *obj,
                    const DFBRegion                           *left,
                    const DFBRegion                           *right,
                    DFBSurfaceFlipFlags                        flags);

DFBResult CoreWindow_BeginUpdates(
                    CoreWindow                                *obj,
                    const DFBRegion                           *update);

DFBResult CoreWindow_Restack(
                    CoreWindow                                *obj,
                    CoreWindow                                *relative,
                    int                                        relation);

DFBResult CoreWindow_SetConfig(
                    CoreWindow                                *obj,
                    const CoreWindowConfig                    *config,
                    const DFBInputDeviceKeySymbol             *keys,
                    u32                                        num_keys,
                    CoreWindowConfigFlags                      flags);

DFBResult CoreWindow_Bind(
                    CoreWindow                                *obj,
                    CoreWindow                                *source,
                    int                                        x,
                    int                                        y);

DFBResult CoreWindow_Unbind(
                    CoreWindow                                *obj,
                    CoreWindow                                *source);

DFBResult CoreWindow_RequestFocus(
                    CoreWindow                                *obj
);

DFBResult CoreWindow_ChangeGrab(
                    CoreWindow                                *obj,
                    CoreWMGrabTarget                           target,
                    bool                                       grab);

DFBResult CoreWindow_GrabKey(
                    CoreWindow                                *obj,
                    DFBInputDeviceKeySymbol                    symbol,
                    DFBInputDeviceModifierMask                 modifiers);

DFBResult CoreWindow_UngrabKey(
                    CoreWindow                                *obj,
                    DFBInputDeviceKeySymbol                    symbol,
                    DFBInputDeviceModifierMask                 modifiers);

DFBResult CoreWindow_Move(
                    CoreWindow                                *obj,
                    int                                        dx,
                    int                                        dy);

DFBResult CoreWindow_MoveTo(
                    CoreWindow                                *obj,
                    int                                        x,
                    int                                        y);

DFBResult CoreWindow_Resize(
                    CoreWindow                                *obj,
                    int                                        width,
                    int                                        height);

DFBResult CoreWindow_Destroy(
                    CoreWindow                                *obj
);

DFBResult CoreWindow_SetCursorPosition(
                    CoreWindow                                *obj,
                    int                                        x,
                    int                                        y);

DFBResult CoreWindow_ChangeEvents(
                    CoreWindow                                *obj,
                    DFBWindowEventType                         disable,
                    DFBWindowEventType                         enable);

DFBResult CoreWindow_ChangeOptions(
                    CoreWindow                                *obj,
                    DFBWindowOptions                           disable,
                    DFBWindowOptions                           enable);

DFBResult CoreWindow_SetColor(
                    CoreWindow                                *obj,
                    const DFBColor                            *color);

DFBResult CoreWindow_SetColorKey(
                    CoreWindow                                *obj,
                    u32                                        key);

DFBResult CoreWindow_SetOpaque(
                    CoreWindow                                *obj,
                    const DFBRegion                           *opaque);

DFBResult CoreWindow_SetOpacity(
                    CoreWindow                                *obj,
                    u8                                         opacity);

DFBResult CoreWindow_SetStacking(
                    CoreWindow                                *obj,
                    DFBWindowStackingClass                     stacking);

DFBResult CoreWindow_SetBounds(
                    CoreWindow                                *obj,
                    const DFBRectangle                        *bounds);

DFBResult CoreWindow_SetKeySelection(
                    CoreWindow                                *obj,
                    DFBWindowKeySelection                      selection,
                    const DFBInputDeviceKeySymbol             *keys,
                    u32                                        num_keys);

DFBResult CoreWindow_SetRotation(
                    CoreWindow                                *obj,
                    int                                        rotation);

DFBResult CoreWindow_GetSurface(
                    CoreWindow                                *obj,
                    CoreSurface                              **ret_surface);

DFBResult CoreWindow_SetCursorShape(
                    CoreWindow                                *obj,
                    CoreSurface                               *shape,
                    const DFBPoint                            *hotspot);

DFBResult CoreWindow_AllowFocus(
                    CoreWindow                                *obj
);

DFBResult CoreWindow_GetInsets(
                    CoreWindow                                *obj,
                    DFBInsets                                 *ret_insets);


void CoreWindow_Init_Dispatch(
                    CoreDFB              *core,
                    CoreWindow           *obj,
                    FusionCall           *call
);

void  CoreWindow_Deinit_Dispatch(
                    FusionCall           *call
);

/*
 * CoreWindow Calls
 */
typedef enum {
    CoreWindowCall_Repaint = 1,
    CoreWindowCall_BeginUpdates = 2,
    CoreWindowCall_Restack = 3,
    CoreWindowCall_SetConfig = 4,
    CoreWindowCall_Bind = 5,
    CoreWindowCall_Unbind = 6,
    CoreWindowCall_RequestFocus = 7,
    CoreWindowCall_ChangeGrab = 8,
    CoreWindowCall_GrabKey = 9,
    CoreWindowCall_UngrabKey = 10,
    CoreWindowCall_Move = 11,
    CoreWindowCall_MoveTo = 12,
    CoreWindowCall_Resize = 13,
    CoreWindowCall_Destroy = 14,
    CoreWindowCall_SetCursorPosition = 15,
    CoreWindowCall_ChangeEvents = 16,
    CoreWindowCall_ChangeOptions = 17,
    CoreWindowCall_SetColor = 18,
    CoreWindowCall_SetColorKey = 19,
    CoreWindowCall_SetOpaque = 20,
    CoreWindowCall_SetOpacity = 21,
    CoreWindowCall_SetStacking = 22,
    CoreWindowCall_SetBounds = 23,
    CoreWindowCall_SetKeySelection = 24,
    CoreWindowCall_SetRotation = 25,
    CoreWindowCall_GetSurface = 26,
    CoreWindowCall_SetCursorShape = 27,
    CoreWindowCall_AllowFocus = 28,
    CoreWindowCall_GetInsets = 29,
} CoreWindowCall;

/*
 * CoreWindow_Repaint
 */
typedef struct {
    DFBRegion                                  left;
    DFBRegion                                  right;
    DFBSurfaceFlipFlags                        flags;
} CoreWindowRepaint;

typedef struct {
    DFBResult                                  result;
} CoreWindowRepaintReturn;


/*
 * CoreWindow_BeginUpdates
 */
typedef struct {
    bool                                       update_set;
    DFBRegion                                  update;
} CoreWindowBeginUpdates;

typedef struct {
    DFBResult                                  result;
} CoreWindowBeginUpdatesReturn;


/*
 * CoreWindow_Restack
 */
typedef struct {
    bool                                       relative_set;
    u32                                        relative_id;
    int                                        relation;
} CoreWindowRestack;

typedef struct {
    DFBResult                                  result;
} CoreWindowRestackReturn;


/*
 * CoreWindow_SetConfig
 */
typedef struct {
    CoreWindowConfig                           config;
    u32                                        num_keys;
    CoreWindowConfigFlags                      flags;
    bool                                       keys_set;
    /* 'num_keys' DFBInputDeviceKeySymbol follow (keys) */
} CoreWindowSetConfig;

typedef struct {
    DFBResult                                  result;
} CoreWindowSetConfigReturn;


/*
 * CoreWindow_Bind
 */
typedef struct {
    u32                                        source_id;
    int                                        x;
    int                                        y;
} CoreWindowBind;

typedef struct {
    DFBResult                                  result;
} CoreWindowBindReturn;


/*
 * CoreWindow_Unbind
 */
typedef struct {
    u32                                        source_id;
} CoreWindowUnbind;

typedef struct {
    DFBResult                                  result;
} CoreWindowUnbindReturn;


/*
 * CoreWindow_RequestFocus
 */
typedef struct {
} CoreWindowRequestFocus;

typedef struct {
    DFBResult                                  result;
} CoreWindowRequestFocusReturn;


/*
 * CoreWindow_ChangeGrab
 */
typedef struct {
    CoreWMGrabTarget                           target;
    bool                                       grab;
} CoreWindowChangeGrab;

typedef struct {
    DFBResult                                  result;
} CoreWindowChangeGrabReturn;


/*
 * CoreWindow_GrabKey
 */
typedef struct {
    DFBInputDeviceKeySymbol                    symbol;
    DFBInputDeviceModifierMask                 modifiers;
} CoreWindowGrabKey;

typedef struct {
    DFBResult                                  result;
} CoreWindowGrabKeyReturn;


/*
 * CoreWindow_UngrabKey
 */
typedef struct {
    DFBInputDeviceKeySymbol                    symbol;
    DFBInputDeviceModifierMask                 modifiers;
} CoreWindowUngrabKey;

typedef struct {
    DFBResult                                  result;
} CoreWindowUngrabKeyReturn;


/*
 * CoreWindow_Move
 */
typedef struct {
    int                                        dx;
    int                                        dy;
} CoreWindowMove;

typedef struct {
    DFBResult                                  result;
} CoreWindowMoveReturn;


/*
 * CoreWindow_MoveTo
 */
typedef struct {
    int                                        x;
    int                                        y;
} CoreWindowMoveTo;

typedef struct {
    DFBResult                                  result;
} CoreWindowMoveToReturn;


/*
 * CoreWindow_Resize
 */
typedef struct {
    int                                        width;
    int                                        height;
} CoreWindowResize;

typedef struct {
    DFBResult                                  result;
} CoreWindowResizeReturn;


/*
 * CoreWindow_Destroy
 */
typedef struct {
} CoreWindowDestroy;

typedef struct {
    DFBResult                                  result;
} CoreWindowDestroyReturn;


/*
 * CoreWindow_SetCursorPosition
 */
typedef struct {
    int                                        x;
    int                                        y;
} CoreWindowSetCursorPosition;

typedef struct {
    DFBResult                                  result;
} CoreWindowSetCursorPositionReturn;


/*
 * CoreWindow_ChangeEvents
 */
typedef struct {
    DFBWindowEventType                         disable;
    DFBWindowEventType                         enable;
} CoreWindowChangeEvents;

typedef struct {
    DFBResult                                  result;
} CoreWindowChangeEventsReturn;


/*
 * CoreWindow_ChangeOptions
 */
typedef struct {
    DFBWindowOptions                           disable;
    DFBWindowOptions                           enable;
} CoreWindowChangeOptions;

typedef struct {
    DFBResult                                  result;
} CoreWindowChangeOptionsReturn;


/*
 * CoreWindow_SetColor
 */
typedef struct {
    DFBColor                                   color;
} CoreWindowSetColor;

typedef struct {
    DFBResult                                  result;
} CoreWindowSetColorReturn;


/*
 * CoreWindow_SetColorKey
 */
typedef struct {
    u32                                        key;
} CoreWindowSetColorKey;

typedef struct {
    DFBResult                                  result;
} CoreWindowSetColorKeyReturn;


/*
 * CoreWindow_SetOpaque
 */
typedef struct {
    DFBRegion                                  opaque;
} CoreWindowSetOpaque;

typedef struct {
    DFBResult                                  result;
} CoreWindowSetOpaqueReturn;


/*
 * CoreWindow_SetOpacity
 */
typedef struct {
    u8                                         opacity;
} CoreWindowSetOpacity;

typedef struct {
    DFBResult                                  result;
} CoreWindowSetOpacityReturn;


/*
 * CoreWindow_SetStacking
 */
typedef struct {
    DFBWindowStackingClass                     stacking;
} CoreWindowSetStacking;

typedef struct {
    DFBResult                                  result;
} CoreWindowSetStackingReturn;


/*
 * CoreWindow_SetBounds
 */
typedef struct {
    DFBRectangle                               bounds;
} CoreWindowSetBounds;

typedef struct {
    DFBResult                                  result;
} CoreWindowSetBoundsReturn;


/*
 * CoreWindow_SetKeySelection
 */
typedef struct {
    DFBWindowKeySelection                      selection;
    u32                                        num_keys;
    bool                                       keys_set;
    /* 'num_keys' DFBInputDeviceKeySymbol follow (keys) */
} CoreWindowSetKeySelection;

typedef struct {
    DFBResult                                  result;
} CoreWindowSetKeySelectionReturn;


/*
 * CoreWindow_SetRotation
 */
typedef struct {
    int                                        rotation;
} CoreWindowSetRotation;

typedef struct {
    DFBResult                                  result;
} CoreWindowSetRotationReturn;


/*
 * CoreWindow_GetSurface
 */
typedef struct {
} CoreWindowGetSurface;

typedef struct {
    DFBResult                                  result;
    u32                                        surface_id;
    void*                                      surface_ptr;
} CoreWindowGetSurfaceReturn;


/*
 * CoreWindow_SetCursorShape
 */
typedef struct {
    bool                                       shape_set;
    u32                                        shape_id;
    DFBPoint                                   hotspot;
} CoreWindowSetCursorShape;

typedef struct {
    DFBResult                                  result;
} CoreWindowSetCursorShapeReturn;


/*
 * CoreWindow_AllowFocus
 */
typedef struct {
} CoreWindowAllowFocus;

typedef struct {
    DFBResult                                  result;
} CoreWindowAllowFocusReturn;


/*
 * CoreWindow_GetInsets
 */
typedef struct {
} CoreWindowGetInsets;

typedef struct {
    DFBResult                                  result;
    DFBInsets                                  insets;
} CoreWindowGetInsetsReturn;


typedef struct _IWindow IWindow;
typedef struct _IWindowReal IWindowReal;
typedef struct _IWindowRequestor IWindowRequestor;


struct _IWindow{
	CoreDFB *core;
	CoreWindow *obj;

	DFBResult (*Repaint)(IWindow *thiz, const DFBRegion *left, const DFBRegion *right, DFBSurfaceFlipFlags flags);

	DFBResult (*BeginUpdates)(IWindow *thiz, const DFBRegion *update);

	DFBResult (*Restack)(IWindow *thiz, CoreWindow *relative, int relation);

	DFBResult (*SetConfig)(IWindow *thiz, const CoreWindowConfig *config, const DFBInputDeviceKeySymbol *keys, u32 num_keys, CoreWindowConfigFlags flags);

	DFBResult (*Bind)(IWindow *thiz, CoreWindow *source, int x, int y);

	DFBResult (*Unbind)(IWindow *thiz, CoreWindow *source);

	DFBResult (*RequestFocus)(IWindow *thiz);

	DFBResult (*ChangeGrab)(IWindow *thiz, CoreWMGrabTarget target, bool grab);

	DFBResult (*GrabKey)(IWindow *thiz, DFBInputDeviceKeySymbol symbol, DFBInputDeviceModifierMask modifiers);

	DFBResult (*UngrabKey)(IWindow *thiz, DFBInputDeviceKeySymbol symbol, DFBInputDeviceModifierMask modifiers);

	DFBResult (*Move)(IWindow *thiz, int dx, int dy);

	DFBResult (*MoveTo)(IWindow *thiz, int x, int y);

	DFBResult (*Resize)(IWindow *thiz, int width, int height);

	DFBResult (*Destroy)(IWindow *thiz);

	DFBResult (*SetCursorPosition)(IWindow *thiz, int x, int y);

	DFBResult (*ChangeEvents)(IWindow *thiz, DFBWindowEventType disable, DFBWindowEventType enable);

	DFBResult (*ChangeOptions)(IWindow *thiz, DFBWindowOptions disable,DFBWindowOptions enable);

	DFBResult (*SetColor)(IWindow *thiz, const DFBColor *color);

	DFBResult (*SetColorKey)(IWindow *thiz, u32 key);

	DFBResult (*SetOpaque)(IWindow *thiz, const DFBRegion *opaque);

	DFBResult (*SetOpacity)(IWindow *thiz, u8 opacity);

	DFBResult (*SetStacking)(IWindow *thiz, DFBWindowStackingClass stacking);

	DFBResult (*SetBounds)(IWindow *thiz, const DFBRectangle *bounds);

	DFBResult (*SetKeySelection)(IWindow *thiz, DFBWindowKeySelection selection, const DFBInputDeviceKeySymbol *keys, u32 num_keys);

	DFBResult (*SetRotation)(IWindow *thiz, int rotation);

	DFBResult (*GetSurface)(IWindow *thiz, CoreSurface **ret_surface);

	DFBResult (*SetCursorShape)(IWindow *thiz, CoreSurface *shape, const DFBPoint *hotspot);

	DFBResult (*AllowFocus)(IWindow *thiz);

	DFBResult (*GetInsets)(IWindow *thiz, DFBInsets *ret_insets);

};


struct _IWindowReal{
	IWindow base;
};

void IWindowRealInit(IWindowReal *thiz, CoreDFB *core, CoreWindow *obj);

struct _IWindowRequestor{
	IWindow base;
};

void IWindowRequestorInit(IWindowRequestor *thiz, CoreDFB *core, CoreWindow *obj);

DFBResult CoreWindowDispatch__Dispatch( CoreWindow *obj,
                    FusionID      caller,
                    int           method,
                    void         *ptr,
                    unsigned int  length,
                    void         *ret_ptr,
                    unsigned int  ret_size,
                    unsigned int *ret_length );

#endif
