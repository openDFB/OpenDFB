/*
   (c) Copyright 2001-2009  The world wide DirectFB Open Source Community (directfb.org)
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

#include <core/CoreWindow.h>

#include <directfb_util.h>

#include <direct/debug.h>
#include <direct/mem.h>
#include <direct/messages.h>

#include <core/windows.h>
#include <core/windowstack.h>
#include <core/wm.h>

D_DEBUG_DOMAIN( Core_Window, "Core/Window", "DirectFB Core Window" );

/*********************************************************************************************************************/


DFBResult
IWindowReal_Repaint( IWindow *thiz, const DFBRegion     *left,
                       const DFBRegion     *right,
                       DFBSurfaceFlipFlags  flags )
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );
     D_ASSERT( left != NULL );
     D_ASSERT( right != NULL );

     return dfb_window_repaint( thiz->obj, left, right, flags );
}

DFBResult
IWindowReal_Restack( IWindow *thiz, CoreWindow *relative,
                       int         relation )
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     DFBResult        ret;
     CoreWindowStack *stack;

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );
     D_ASSERT( thiz->obj->stack != NULL );

     stack = thiz->obj->stack;

     /* Lock the window stack. */
     if (dfb_windowstack_lock( stack ))
          return DFB_FUSION;

     /* Never call WM after destroying the window. */
     if (DFB_WINDOW_DESTROYED( thiz->obj )) {
          dfb_windowstack_unlock( stack );
          return DFB_DESTROYED;
     }

     /* Let the window manager do its work. */
     ret = dfb_wm_restack_window( thiz->obj, relative, relation );

     /* Unlock the window stack. */
     dfb_windowstack_unlock( stack );

     return ret;
}

DFBResult
IWindowReal_SetConfig( IWindow *thiz, const CoreWindowConfig        *config,
                         const DFBInputDeviceKeySymbol *keys,
                         u32                            num_keys,
                         CoreWindowConfigFlags          flags )
{
     CoreWindowConfig config_copy;

     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );
     D_ASSERT( config != NULL );

     if ((flags & DWCONF_ASSOCIATION) && config->association) {
          DFBResult ret;
          CoreWindow *parent;

          ret = dfb_core_get_window( thiz->core, config->association, &parent );
          if (ret)
               return ret;

          if (parent->object.owner && parent->object.owner != Core_GetIdentity()) {
               dfb_window_unref( parent );
               return DFB_ACCESSDENIED;
          }

          dfb_window_unref( parent );
     }

     config_copy = *config;

     config_copy.keys     = (DFBInputDeviceKeySymbol*) keys;
     config_copy.num_keys = num_keys;

     return dfb_window_set_config( thiz->obj, &config_copy, flags );
}

DFBResult
IWindowReal_Bind( IWindow *thiz, CoreWindow *source,
                    int         x,
                    int         y )
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );
     D_MAGIC_ASSERT( source, CoreWindow );

     return dfb_window_bind( thiz->obj, source, x, y );
}

DFBResult
IWindowReal_Unbind( IWindow *thiz, CoreWindow *source )
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );
     D_MAGIC_ASSERT( source, CoreWindow );

     return dfb_window_unbind( thiz->obj, source );
}

DFBResult
IWindowReal_RequestFocus(IWindow *thiz)
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     return dfb_window_request_focus( thiz->obj );
}

DFBResult
IWindowReal_ChangeGrab( IWindow *thiz, CoreWMGrabTarget     target,
                          bool                 grab )
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     return dfb_window_change_grab( thiz->obj, target, grab );
}

DFBResult
IWindowReal_GrabKey( IWindow *thiz, DFBInputDeviceKeySymbol     symbol,
                       DFBInputDeviceModifierMask  modifiers )
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     return dfb_window_grab_key( thiz->obj, symbol, modifiers );
}

DFBResult
IWindowReal_UngrabKey( IWindow *thiz, DFBInputDeviceKeySymbol     symbol,
                         DFBInputDeviceModifierMask  modifiers )
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     return dfb_window_ungrab_key( thiz->obj, symbol, modifiers );
}

DFBResult
IWindowReal_Move( IWindow *thiz, int dx,
                    int dy )
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     return dfb_window_move( thiz->obj, dx, dy, true );
}

DFBResult
IWindowReal_MoveTo( IWindow *thiz, int x,
                      int y )
{
     DFBResult ret;
     DFBInsets insets;

     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     dfb_windowstack_lock( thiz->obj->stack );

     dfb_wm_get_insets( thiz->obj->stack, thiz->obj, &insets );

     ret = dfb_window_move( thiz->obj, x + insets.l, y + insets.t, false );

     dfb_windowstack_unlock( thiz->obj->stack );

     return ret;
}

DFBResult
IWindowReal_Resize( IWindow *thiz, int width,
                      int height )
{
     DFBResult ret;
     DFBInsets insets;

     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     dfb_windowstack_lock( thiz->obj->stack );

     dfb_wm_get_insets( thiz->obj->stack, thiz->obj, &insets );

     ret = dfb_window_resize( thiz->obj, width + insets.l+insets.r, height + insets.t+insets.b );

     dfb_windowstack_unlock( thiz->obj->stack );

     return ret;
}

DFBResult
IWindowReal_Destroy(IWindow *thiz)
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     dfb_window_destroy( thiz->obj );

     return DFB_OK;
}

DFBResult
IWindowReal_BeginUpdates( IWindow *thiz, const DFBRegion *update )
{
     DFBResult ret;

     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     dfb_windowstack_lock( thiz->obj->stack );

     ret = dfb_wm_begin_updates( thiz->obj, update );

     dfb_windowstack_unlock( thiz->obj->stack );

     return ret;
}

DFBResult
IWindowReal_SetCursorPosition( IWindow *thiz, int x,
                                 int y )
{
     DFBResult ret;

     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     dfb_windowstack_lock( thiz->obj->stack );

     ret = dfb_wm_set_cursor_position( thiz->obj, x, y );

     dfb_windowstack_unlock( thiz->obj->stack );

     return ret;
}

DFBResult
IWindowReal_ChangeEvents( IWindow *thiz, DFBWindowEventType disable,
                            DFBWindowEventType enable )
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     return dfb_window_change_events( thiz->obj, disable, enable );
}

DFBResult
IWindowReal_ChangeOptions( IWindow *thiz, DFBWindowOptions disable,
                             DFBWindowOptions enable )
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     return dfb_window_change_options( thiz->obj, disable, enable );
}

DFBResult
IWindowReal_SetColor( IWindow *thiz, const DFBColor *color )
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     return dfb_window_set_color( thiz->obj, *color );
}

DFBResult
IWindowReal_SetColorKey( IWindow *thiz, u32 key )
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     return dfb_window_set_colorkey( thiz->obj, key );
}

DFBResult
IWindowReal_SetOpaque( IWindow *thiz, const DFBRegion *opaque )
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     return dfb_window_set_opaque( thiz->obj, opaque );
}

DFBResult
IWindowReal_SetOpacity( IWindow *thiz, u8 opacity )
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     return dfb_window_set_opacity( thiz->obj, opacity );
}

DFBResult
IWindowReal_SetStacking( IWindow *thiz, DFBWindowStackingClass stacking )
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     return dfb_window_change_stacking( thiz->obj, stacking );
}

DFBResult
IWindowReal_SetBounds( IWindow *thiz, const DFBRectangle *bounds )
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     return dfb_window_set_bounds( thiz->obj, DFB_RECTANGLE_VALS( bounds ) );
}

DFBResult
IWindowReal_SetKeySelection( IWindow *thiz, DFBWindowKeySelection          selection,
                               const DFBInputDeviceKeySymbol *keys,
                               u32                            num_keys )
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     return dfb_window_set_key_selection( thiz->obj, selection, keys, num_keys );
}

DFBResult
IWindowReal_SetRotation( IWindow *thiz, int rotation )
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     return dfb_window_set_rotation( thiz->obj, rotation );
}

DFBResult
IWindowReal_GetSurface(IWindow *thiz,
                    CoreSurface                              **ret_surface
)
{
     DFBResult ret;

     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_ASSERT( ret_surface != NULL );

     if (!thiz->obj->surface)
          return DFB_UNSUPPORTED;

     ret = (DFBResult) dfb_surface_ref( thiz->obj->surface );
     if (ret)
          return ret;

     *ret_surface = thiz->obj->surface;

     return DFB_OK;
}

DFBResult
IWindowReal_SetCursorShape(IWindow *thiz,
                    CoreSurface                               *shape,
                    const DFBPoint                            *hotspot )
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     return dfb_window_set_cursor_shape( thiz->obj, shape, hotspot->x, hotspot->y );
}

DFBResult
IWindowReal_AllowFocus(IWindow *thiz)
{
     D_DEBUG_AT( Core_Window, "IWindowReal_%s( %p )\n", __FUNCTION__, thiz->obj );

     D_MAGIC_ASSERT( thiz->obj, CoreWindow );

     /*
      * Remove DWCAPS_NOFOCUS, unless requested by the application itself.
      */
     thiz->obj->caps = (DFBWindowCapabilities)((thiz->obj->caps & ~DWCAPS_NOFOCUS) | (thiz->obj->requested_caps & DWCAPS_NOFOCUS));

     return DFB_OK;
}


DFBResult
IWindowReal_GetInsets(IWindow *thiz,
     DFBInsets                                *ret_insets
)
{
    DFBResult ret;

    D_DEBUG_AT( Core_Window, "IWindowReal_%s()\n", __FUNCTION__ );

    ret = (DFBResult) dfb_layer_context_lock( thiz->obj->stack->context );
    if (ret)
         return ret;

    ret = dfb_wm_get_insets( thiz->obj->stack, thiz->obj, ret_insets );

    dfb_layer_context_unlock( thiz->obj->stack->context );

    return ret;
}

void IWindowRealInit(IWindowReal *thiz, CoreDFB *core, CoreWindow *obj)
{
	thiz->base.core = core;
	thiz->base.obj = obj;

	thiz->base.Repaint = IWindowReal_Repaint;
	thiz->base.BeginUpdates = IWindowReal_BeginUpdates;
	thiz->base.Restack = IWindowReal_Restack;
	thiz->base.SetConfig = IWindowReal_SetConfig;
	thiz->base.Bind = IWindowReal_Bind;
	thiz->base.Unbind = IWindowReal_Unbind;
	thiz->base.RequestFocus = IWindowReal_RequestFocus;
	thiz->base.ChangeGrab = IWindowReal_ChangeGrab;
	thiz->base.GrabKey = IWindowReal_GrabKey;
	thiz->base.UngrabKey = IWindowReal_UngrabKey;
	thiz->base.Move = IWindowReal_Move;
	thiz->base.MoveTo = IWindowReal_MoveTo;
	thiz->base.Resize = IWindowReal_Resize;
	thiz->base.Destroy = IWindowReal_Destroy;
	thiz->base.SetCursorPosition = IWindowReal_SetCursorPosition;
	thiz->base.ChangeEvents = IWindowReal_ChangeEvents;
	thiz->base.ChangeOptions = IWindowReal_ChangeOptions;
	thiz->base.SetColor = IWindowReal_SetColor;
	thiz->base.SetColorKey = IWindowReal_SetColorKey;
	thiz->base.SetOpaque = IWindowReal_SetOpaque;
	thiz->base.SetOpacity = IWindowReal_SetOpacity;
	thiz->base.SetStacking = IWindowReal_SetStacking;
	thiz->base.SetBounds = IWindowReal_SetBounds;
	thiz->base.SetKeySelection = IWindowReal_SetKeySelection;
	thiz->base.SetRotation = IWindowReal_SetRotation;
	thiz->base.GetSurface = IWindowReal_GetSurface;
	thiz->base.SetCursorShape = IWindowReal_SetCursorShape;
	thiz->base.AllowFocus = IWindowReal_AllowFocus;
	thiz->base.GetInsets = IWindowReal_GetInsets;
}

