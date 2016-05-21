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
#include <direct/messages.h>

#include <core/core.h>
#include <core/wm.h>

D_DEBUG_DOMAIN( DirectFB_CoreWindowStack, "DirectFB/CoreWindowStack", "DirectFB CoreWindowStack" );

/*********************************************************************************************************************/

DFBResult
IWindowStackReal_RepaintAll(IWindowStack *thiz
)
{
    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackReal_%s()\n", __FUNCTION__ );

    return dfb_windowstack_repaint_all( thiz->obj );
}


DFBResult
IWindowStackReal_CursorEnable(IWindowStack *thiz,
                    bool                                       enable
)
{
    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackReal_%s()\n", __FUNCTION__ );

    return dfb_windowstack_cursor_enable( thiz->core, thiz->obj, enable );
}


DFBResult
IWindowStackReal_CursorSetShape(IWindowStack *thiz,
                    CoreSurface                               *shape,
                    const DFBPoint                            *hotspot
)
{
    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackReal_%s()\n", __FUNCTION__ );

    return dfb_windowstack_cursor_set_shape( thiz->obj, shape, hotspot->x, hotspot->y );
}


DFBResult
IWindowStackReal_CursorSetOpacity(IWindowStack *thiz,
                    u8                                         opacity
)
{
    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackReal_%s()\n", __FUNCTION__ );

    return dfb_windowstack_cursor_set_opacity( thiz->obj, opacity );
}


DFBResult
IWindowStackReal_CursorSetAcceleration(IWindowStack *thiz,
                    u32                                        numerator,
                    u32                                        denominator,
                    u32                                        threshold
)
{
    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackReal_%s()\n", __FUNCTION__ );

    return dfb_windowstack_cursor_set_acceleration( thiz->obj, numerator, denominator, threshold );
}


DFBResult
IWindowStackReal_CursorWarp(IWindowStack *thiz,
                    const DFBPoint                            *position
)
{
    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackReal_%s()\n", __FUNCTION__ );

    return dfb_windowstack_cursor_warp( thiz->obj, position->x, position->y );
}


DFBResult
IWindowStackReal_CursorGetPosition(IWindowStack *thiz,
                    DFBPoint                                  *ret_position
)
{
    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackReal_%s()\n", __FUNCTION__ );

    return dfb_windowstack_get_cursor_position( thiz->obj, &ret_position->x, &ret_position->y );
}


DFBResult
IWindowStackReal_BackgroundSetMode(IWindowStack *thiz,
                    DFBDisplayLayerBackgroundMode              mode
)
{
    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackReal_%s()\n", __FUNCTION__ );

    return dfb_windowstack_set_background_mode( thiz->obj, mode );
}


DFBResult
IWindowStackReal_BackgroundSetImage(IWindowStack *thiz,
                    CoreSurface                               *image
)
{
    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackReal_%s()\n", __FUNCTION__ );

    return dfb_windowstack_set_background_image( thiz->obj, image );
}


DFBResult
IWindowStackReal_BackgroundSetColor(IWindowStack *thiz,
                    const DFBColor                            *color
)
{
    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackReal_%s()\n", __FUNCTION__ );

    return dfb_windowstack_set_background_color( thiz->obj, color );
}


DFBResult
IWindowStackReal_BackgroundSetColorIndex(IWindowStack *thiz,
                    s32                                        index
)
{
    D_DEBUG_AT( DirectFB_CoreWindowStack, "IWindowStackReal_%s()\n", __FUNCTION__ );

    return dfb_windowstack_set_background_color_index( thiz->obj, index );
}

void IWindowStackRealInit(IWindowStackReal *thiz, CoreDFB *core, CoreWindowStack *obj)
{
	thiz->base.core = core;
	thiz->base.obj = obj;

    thiz->base.RepaintAll = IWindowStackReal_RepaintAll;
    thiz->base.CursorEnable = IWindowStackReal_CursorEnable;
    thiz->base.CursorSetShape = IWindowStackReal_CursorSetShape;
    thiz->base.CursorSetOpacity = IWindowStackReal_CursorSetOpacity;
    thiz->base.CursorSetAcceleration = IWindowStackReal_CursorSetAcceleration;
    thiz->base.CursorWarp = IWindowStackReal_CursorWarp;
    thiz->base.CursorGetPosition = IWindowStackReal_CursorGetPosition;
    thiz->base.BackgroundSetMode = IWindowStackReal_BackgroundSetMode;
    thiz->base.BackgroundSetImage = IWindowStackReal_BackgroundSetImage;
    thiz->base.BackgroundSetColor = IWindowStackReal_BackgroundSetColor;
    thiz->base.BackgroundSetColorIndex = IWindowStackReal_BackgroundSetColorIndex;
}


