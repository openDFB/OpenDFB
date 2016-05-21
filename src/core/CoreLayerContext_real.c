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

#include "CoreLayerContext.h"

#include <directfb_util.h>

#include <direct/debug.h>
#include <direct/mem.h>
#include <direct/messages.h>

#include <core/core.h>
#include <core/wm.h>

D_DEBUG_DOMAIN( DirectFB_CoreLayerContext, "DirectFB/CoreLayerContext", "DirectFB CoreLayerContext" );

/*********************************************************************************************************************/
DFBResult
ILayerContextReal_GetPrimaryRegion(ILayerContext *thiz,
                    bool                                       create,
                    CoreLayerRegion                          **ret_region
)
{
    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContext_Requestor::%s()\n", __FUNCTION__ );

    D_ASSERT( ret_region != NULL );

    return dfb_layer_context_get_primary_region( thiz->obj, create, ret_region );
}

DFBResult
ILayerContextReal_TestConfiguration(ILayerContext *thiz,
                    const DFBDisplayLayerConfig               *config,
                    DFBDisplayLayerConfigFlags                *ret_failed
)
{
    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContext_Requestor::%s()\n", __FUNCTION__ );

    D_ASSERT( config != NULL );

    return dfb_layer_context_test_configuration( thiz->obj, config, ret_failed );
}

DFBResult
ILayerContextReal_SetConfiguration(ILayerContext *thiz,
                    const DFBDisplayLayerConfig               *config
)
{
    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContext_Requestor::%s()\n", __FUNCTION__ );

    D_ASSERT( config != NULL );

    return dfb_layer_context_set_configuration( thiz->obj, config );
}

DFBResult
ILayerContextReal_SetSrcColorKey(ILayerContext *thiz,
                    const DFBColorKey                         *key
)
{
    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextReal_%s()\n", __FUNCTION__ );

    D_ASSERT( key != NULL );

    return dfb_layer_context_set_src_colorkey( thiz->obj, key->r, key->g, key->b, key->index );
}


DFBResult
ILayerContextReal_SetDstColorKey(ILayerContext *thiz,
                    const DFBColorKey                         *key
)
{
    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextReal_%s()\n", __FUNCTION__ );

    D_ASSERT( key != NULL );

    return dfb_layer_context_set_dst_colorkey( thiz->obj, key->r, key->g, key->b, key->index );
}


DFBResult
ILayerContextReal_SetSourceRectangle(ILayerContext *thiz,
                    const DFBRectangle                        *rectangle
)
{
    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextReal_%s()\n", __FUNCTION__ );

    D_ASSERT( rectangle != NULL );

    return dfb_layer_context_set_sourcerectangle( thiz->obj, rectangle );
}


DFBResult
ILayerContextReal_SetScreenLocation(ILayerContext *thiz,
                    const DFBLocation                         *location
)
{
    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextReal_%s()\n", __FUNCTION__ );

    D_ASSERT( location != NULL );

    return dfb_layer_context_set_screenlocation( thiz->obj, location );
}


DFBResult
ILayerContextReal_SetScreenRectangle(ILayerContext *thiz,
                    const DFBRectangle                        *rectangle
)
{
    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextReal_%s()\n", __FUNCTION__ );

    D_ASSERT( rectangle != NULL );

    return dfb_layer_context_set_screenrectangle( thiz->obj, rectangle );
}


DFBResult
ILayerContextReal_SetScreenPosition(ILayerContext *thiz,
                    const DFBPoint                            *position
)
{
    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextReal_%s()\n", __FUNCTION__ );

    D_ASSERT( position != NULL );

    return dfb_layer_context_set_screenposition( thiz->obj, position->x, position->y );
}


DFBResult
ILayerContextReal_SetOpacity(ILayerContext *thiz,
                    u8                                         opacity
)
{
    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextReal_%s()\n", __FUNCTION__ );

    return dfb_layer_context_set_opacity( thiz->obj, opacity );
}


DFBResult
ILayerContextReal_SetRotation(ILayerContext *thiz,
                    s32                                        rotation
)
{
    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextReal_%s()\n", __FUNCTION__ );

    return dfb_layer_context_set_rotation( thiz->obj, rotation );
}


DFBResult
ILayerContextReal_SetColorAdjustment(ILayerContext *thiz,
                    const DFBColorAdjustment                  *adjustment
)
{
    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextReal_%s()\n", __FUNCTION__ );

    D_ASSERT( adjustment != NULL );

    return dfb_layer_context_set_coloradjustment( thiz->obj, adjustment );
}


DFBResult
ILayerContextReal_SetStereoDepth(ILayerContext *thiz,
                    bool                                       follow_video,
                    s32                                        z
)
{
    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextReal_%s()\n", __FUNCTION__ );

    return dfb_layer_context_set_stereo_depth( thiz->obj, follow_video, z );
}


DFBResult
ILayerContextReal_SetFieldParity(ILayerContext *thiz,
                    u32                                        field
)
{
    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextReal_%s()\n", __FUNCTION__ );

    return dfb_layer_context_set_field_parity( thiz->obj, field );
}


DFBResult
ILayerContextReal_SetClipRegions(ILayerContext *thiz,
                    const DFBRegion                           *regions,
                    u32                                        num,
                    bool                                       positive
)
{
    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextReal_%s()\n", __FUNCTION__ );

    D_ASSERT( regions != NULL );

    return dfb_layer_context_set_clip_regions( thiz->obj, regions, num, positive ? DFB_TRUE : DFB_FALSE );
}

DFBResult
ILayerContextReal_CreateWindow(ILayerContext *thiz,
                    const DFBWindowDescription                *description,
                    CoreWindow                               **ret_window
)
{
    DFBResult ret;

    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextReal_%s()\n", __FUNCTION__ );

    D_ASSERT( description != NULL );
    D_ASSERT( ret_window != NULL );

    if (description->flags & DWDESC_PARENT) {
        CoreWindow *parent;

        ret = dfb_core_get_window( thiz->core, description->parent_id, &parent );
        if (ret)
            return ret;

        if (parent->object.owner && parent->object.owner != Core_GetIdentity()) {
             dfb_window_unref( parent );
             return DFB_ACCESSDENIED;
        }

        dfb_window_unref( parent );
    }

    if (description->flags & DWDESC_TOPLEVEL_ID) {
        CoreWindow *toplevel;

        ret = dfb_core_get_window( thiz->core, description->toplevel_id, &toplevel );
        if (ret)
            return ret;

        if (toplevel->object.owner && toplevel->object.owner != Core_GetIdentity()) {
             dfb_window_unref( toplevel );
             return DFB_ACCESSDENIED;
        }

        dfb_window_unref( toplevel );
    }

    return dfb_layer_context_create_window( thiz->core, thiz->obj, description, ret_window );
}

DFBResult
ILayerContextReal_FindWindow(ILayerContext *thiz,
                    DFBWindowID                                window_id,
                    CoreWindow                               **ret_window
)
{
    CoreWindow *window;

    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextReal_%s()\n", __FUNCTION__ );

    D_ASSERT( ret_window != NULL );

    window = dfb_layer_context_find_window( thiz->obj, window_id );
    if (!window)
         return DFB_IDNOTFOUND;

    *ret_window = window;

    return DFB_OK;
}

typedef struct {
     unsigned long    resource_id;
     CoreWindow      *window;
} FindWindowByResourceID_Context;

static DFBEnumerationResult
FindWindowByResourceID_WindowCallback( CoreWindow *window,
                                       void       *_ctx )
{
     FindWindowByResourceID_Context *ctx = (FindWindowByResourceID_Context *) _ctx;

     if (window->surface) {
          if (window->surface->resource_id == ctx->resource_id) {
               ctx->window = window;

               return DFENUM_CANCEL;
          }
     }

     return DFENUM_OK;
}

DFBResult
ILayerContextReal_FindWindowByResourceID(ILayerContext *thiz,
                    u64                                        resource_id,
                    CoreWindow                               **ret_window
)
{
     DFBResult                       ret;
     CoreLayerContext               *context = thiz->obj;
     CoreWindowStack                *stack;
     FindWindowByResourceID_Context  ctx;

     D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextReal_%s()\n", __FUNCTION__ );

     D_ASSERT( ret_window != NULL );

     stack = context->stack;
     D_ASSERT( stack != NULL );

     ctx.resource_id = resource_id;
     ctx.window      = NULL;

     ret = (DFBResult) dfb_layer_context_lock( context );
     if (ret)
         return ret;

     ret = dfb_wm_enum_windows( stack, FindWindowByResourceID_WindowCallback, &ctx );
     if (ret == DFB_OK) {
          if (ctx.window) {
               ret = (DFBResult) dfb_window_ref( ctx.window );
               if (ret == DFB_OK)
                    *ret_window = ctx.window;
          }
          else
               ret = DFB_IDNOTFOUND;
     }

     dfb_layer_context_unlock( context );

     return ret;
}

void ILayerContextRealInit(ILayerContextReal *thiz, CoreDFB *core, CoreLayerContext *obj)
{
	thiz->base.core = core;
	thiz->base.obj = obj;

  	thiz->base.GetPrimaryRegion = ILayerContextReal_GetPrimaryRegion;
  	thiz->base.TestConfiguration = ILayerContextReal_TestConfiguration;
	thiz->base.SetConfiguration = ILayerContextReal_SetConfiguration;
	thiz->base.SetSrcColorKey = ILayerContextReal_SetSrcColorKey;
	thiz->base.SetDstColorKey = ILayerContextReal_SetDstColorKey;
	thiz->base.SetSourceRectangle = ILayerContextReal_SetSourceRectangle;
	thiz->base.SetScreenLocation = ILayerContextReal_SetScreenLocation;
	thiz->base.SetScreenRectangle = ILayerContextReal_SetScreenRectangle;
	thiz->base.SetScreenPosition = ILayerContextReal_SetScreenPosition;
	thiz->base.SetOpacity = ILayerContextReal_SetOpacity;
	thiz->base.SetRotation = ILayerContextReal_SetRotation;
	thiz->base.SetColorAdjustment = ILayerContextReal_SetColorAdjustment;
	thiz->base.SetStereoDepth = ILayerContextReal_SetStereoDepth;
	thiz->base.SetFieldParity = ILayerContextReal_SetFieldParity;
	thiz->base.SetClipRegions = ILayerContextReal_SetClipRegions;
	thiz->base.CreateWindow = ILayerContextReal_CreateWindow;
	thiz->base.FindWindow = ILayerContextReal_FindWindow;
	thiz->base.FindWindowByResourceID = ILayerContextReal_FindWindowByResourceID;
}

