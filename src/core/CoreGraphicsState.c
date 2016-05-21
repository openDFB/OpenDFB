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

#include "CoreGraphicsState.h"

#include <directfb_util.h>

#include <direct/debug.h>
#include <direct/mem.h>
#include <direct/memcpy.h>
#include <direct/messages.h>

#include <fusion/conf.h>

#include <core/core.h>

#include <core/CoreDFB_CallMode.h>

D_DEBUG_DOMAIN( DirectFB_CoreGraphicsState, "DirectFB/CoreGraphicsState", "DirectFB CoreGraphicsState" );

/*********************************************************************************************************************/

DFBResult
CoreGraphicsState_SetDrawingFlags(
                    CoreGraphicsState                         *obj,
                    DFBSurfaceDrawingFlags                     flags
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetDrawingFlags( super, flags );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetDrawingFlags( super, flags );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_SetBlittingFlags(
                    CoreGraphicsState                         *obj,
                    DFBSurfaceBlittingFlags                    flags
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetBlittingFlags( super, flags );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetBlittingFlags( super, flags );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_SetClip(
                    CoreGraphicsState                         *obj,
                    const DFBRegion                           *region
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetClip( super, region );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetClip( super, region );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_SetColor(
                    CoreGraphicsState                         *obj,
                    const DFBColor                            *color
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetColor( super, color );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetColor( super, color );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_SetColorAndIndex(
                    CoreGraphicsState                         *obj,
                    const DFBColor                            *color,
                    u32                                        index
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetColorAndIndex( super, color, index );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetColorAndIndex( super, color, index );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_SetSrcBlend(
                    CoreGraphicsState                         *obj,
                    DFBSurfaceBlendFunction                    function
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetSrcBlend( super, function );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetSrcBlend( super, function );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_SetDstBlend(
                    CoreGraphicsState                         *obj,
                    DFBSurfaceBlendFunction                    function
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetDstBlend( super, function );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetDstBlend( super, function );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_SetSrcColorKey(
                    CoreGraphicsState                         *obj,
                    u32                                        key
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetSrcColorKey( super, key );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetSrcColorKey( super, key );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_SetDstColorKey(
                    CoreGraphicsState                         *obj,
                    u32                                        key
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetDstColorKey( super, key );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetDstColorKey( super, key );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_SetDestination(
                    CoreGraphicsState                         *obj,
                    CoreSurface                               *surface
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetDestination( super, surface );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetDestination( super, surface );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_SetSource(
                    CoreGraphicsState                         *obj,
                    CoreSurface                               *surface
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetSource( super, surface );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetSource( super, surface );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_SetSourceMask(
                    CoreGraphicsState                         *obj,
                    CoreSurface                               *surface
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetSourceMask( super, surface );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetSourceMask( super, surface );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_SetSourceMaskVals(
                    CoreGraphicsState                         *obj,
                    const DFBPoint                            *offset,
                    DFBSurfaceMaskFlags                        flags
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetSourceMaskVals( super, offset, flags );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetSourceMaskVals( super, offset, flags );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_SetIndexTranslation(
                    CoreGraphicsState                         *obj,
                    const s32                                 *indices,
                    u32                                        num
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetIndexTranslation( super, indices, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetIndexTranslation( super, indices, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_SetColorKey(
                    CoreGraphicsState                         *obj,
                    const DFBColorKey                         *key
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetColorKey( super, key );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetColorKey( super, key );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_SetRenderOptions(
                    CoreGraphicsState                         *obj,
                    DFBSurfaceRenderOptions                    options
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetRenderOptions( super, options );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetRenderOptions( super, options );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_SetMatrix(
                    CoreGraphicsState                         *obj,
                    const s32                                 *values
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetMatrix( super, values );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetMatrix( super, values );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_SetSource2(
                    CoreGraphicsState                         *obj,
                    CoreSurface                               *surface
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetSource2( super, surface );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetSource2( super, surface );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_SetFrom(
                    CoreGraphicsState                         *obj,
                    CoreSurfaceBufferRole                      role,
                    DFBSurfaceStereoEye                        eye
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetFrom( super, role, eye );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetFrom( super, role, eye );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_SetTo(
                    CoreGraphicsState                         *obj,
                    CoreSurfaceBufferRole                      role,
                    DFBSurfaceStereoEye                        eye
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetTo( super, role, eye );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetTo( super, role, eye );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_DrawRectangles(
                    CoreGraphicsState                         *obj,
                    const DFBRectangle                        *rects,
                    u32                                        num
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->DrawRectangles( super, rects, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->DrawRectangles( super, rects, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_DrawLines(
                    CoreGraphicsState                         *obj,
                    const DFBRegion                           *lines,
                    u32                                        num
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->DrawLines( super, lines, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->DrawLines( super, lines, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_FillRectangles(
                    CoreGraphicsState                         *obj,
                    const DFBRectangle                        *rects,
                    u32                                        num
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->FillRectangles( super, rects, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->FillRectangles( super, rects, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_FillTriangles(
                    CoreGraphicsState                         *obj,
                    const DFBTriangle                         *triangles,
                    u32                                        num
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->FillTriangles( super, triangles, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->FillTriangles( super, triangles, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_FillTrapezoids(
                    CoreGraphicsState                         *obj,
                    const DFBTrapezoid                        *trapezoids,
                    u32                                        num
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->FillTrapezoids( super, trapezoids, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->FillTrapezoids( super, trapezoids, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_FillSpans(
                    CoreGraphicsState                         *obj,
                    s32                                        y,
                    const DFBSpan                             *spans,
                    u32                                        num
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->FillSpans( super, y, spans, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->FillSpans( super, y, spans, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_Blit(
                    CoreGraphicsState                         *obj,
                    const DFBRectangle                        *rects,
                    const DFBPoint                            *points,
                    u32                                        num
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->Blit( super, rects, points, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->Blit( super, rects, points, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_Blit2(
                    CoreGraphicsState                         *obj,
                    const DFBRectangle                        *rects,
                    const DFBPoint                            *points1,
                    const DFBPoint                            *points2,
                    u32                                        num
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->Blit2( super, rects, points1, points2, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->Blit2( super, rects, points1, points2, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_StretchBlit(
                    CoreGraphicsState                         *obj,
                    const DFBRectangle                        *srects,
                    const DFBRectangle                        *drects,
                    u32                                        num
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->StretchBlit( super, srects, drects, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->StretchBlit( super, srects, drects, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_TileBlit(
                    CoreGraphicsState                         *obj,
                    const DFBRectangle                        *rects,
                    const DFBPoint                            *points1,
                    const DFBPoint                            *points2,
                    u32                                        num
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->TileBlit( super, rects, points1, points2, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->TileBlit( super, rects, points1, points2, num );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_TextureTriangles(
                    CoreGraphicsState                         *obj,
                    const DFBVertex                           *vertices,
                    u32                                        num,
                    DFBTriangleFormation                       formation
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->TextureTriangles( super, vertices, num, formation );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->TextureTriangles( super, vertices, num, formation );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_Flush(
                    CoreGraphicsState                         *obj

)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->Flush( super );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->Flush( super );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_ReleaseSource(
                    CoreGraphicsState                         *obj

)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->ReleaseSource( super );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->ReleaseSource( super );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreGraphicsState_SetSrcConvolution(
                    CoreGraphicsState                         *obj,
                    const DFBConvolutionFilter                *filter
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IGraphicsStateReal real;
			IGraphicsState *super = (IGraphicsState *)&real;
			IGraphicsStateRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetSrcConvolution( super, filter );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IGraphicsStateRequestor requestor;
			IGraphicsState *super = (IGraphicsState *)&requestor;
			IGraphicsStateRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetSrcConvolution( super, filter );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

/*********************************************************************************************************************/

static FusionCallHandlerResult
CoreGraphicsState_Dispatch( int           caller,   /* fusion id of the caller */
                     int           call_arg, /* optional call parameter */
                     void         *ptr, /* optional call parameter */
                     unsigned int  length,
                     void         *ctx,      /* optional handler context */
                     unsigned int  serial,
                     void         *ret_ptr,
                     unsigned int  ret_size,
                     unsigned int *ret_length )
{
    CoreGraphicsState *obj = (CoreGraphicsState*) ctx;
    CoreGraphicsStateDispatch__Dispatch( obj, caller, call_arg, ptr, length, ret_ptr, ret_size, ret_length );

    return FCHR_RETURN;
}

void CoreGraphicsState_Init_Dispatch(
                    CoreDFB              *core,
                    CoreGraphicsState    *obj,
                    FusionCall           *call
)
{
    fusion_call_init3( call, CoreGraphicsState_Dispatch, obj, core->world );
}

void  CoreGraphicsState_Deinit_Dispatch(
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
IGraphicsStateRequestor_SetDrawingFlags(IGraphicsState *thiz,
                    DFBSurfaceDrawingFlags                     flags
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetDrawingFlags       *args = (CoreGraphicsStateSetDrawingFlags*) args_alloc( args_static, sizeof(CoreGraphicsStateSetDrawingFlags) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );


    args->flags = flags;

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetDrawingFlags, args, sizeof(CoreGraphicsStateSetDrawingFlags), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetDrawingFlags ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_SetBlittingFlags(IGraphicsState *thiz,
                    DFBSurfaceBlittingFlags                    flags
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetBlittingFlags       *args = (CoreGraphicsStateSetBlittingFlags*) args_alloc( args_static, sizeof(CoreGraphicsStateSetBlittingFlags) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );


    args->flags = flags;

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetBlittingFlags, args, sizeof(CoreGraphicsStateSetBlittingFlags), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetBlittingFlags ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_SetClip(IGraphicsState *thiz,
                    const DFBRegion                           *region
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetClip       *args = (CoreGraphicsStateSetClip*) args_alloc( args_static, sizeof(CoreGraphicsStateSetClip) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( region != NULL );

    args->region = *region;

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetClip, args, sizeof(CoreGraphicsStateSetClip), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetClip ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_SetColor(IGraphicsState *thiz,
                    const DFBColor                            *color
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetColor       *args = (CoreGraphicsStateSetColor*) args_alloc( args_static, sizeof(CoreGraphicsStateSetColor) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( color != NULL );

    args->color = *color;

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetColor, args, sizeof(CoreGraphicsStateSetColor), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetColor ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_SetColorAndIndex(IGraphicsState *thiz,
                    const DFBColor                            *color,
                    u32                                        index
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetColorAndIndex       *args = (CoreGraphicsStateSetColorAndIndex*) args_alloc( args_static, sizeof(CoreGraphicsStateSetColorAndIndex) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( color != NULL );

    args->color = *color;
    args->index = index;

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetColorAndIndex, args, sizeof(CoreGraphicsStateSetColorAndIndex), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetColorAndIndex ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_SetSrcBlend(IGraphicsState *thiz,
                    DFBSurfaceBlendFunction                    function
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetSrcBlend       *args = (CoreGraphicsStateSetSrcBlend*) args_alloc( args_static, sizeof(CoreGraphicsStateSetSrcBlend) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );


    args->function = function;

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetSrcBlend, args, sizeof(CoreGraphicsStateSetSrcBlend), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetSrcBlend ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_SetDstBlend(IGraphicsState *thiz,
                    DFBSurfaceBlendFunction                    function
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetDstBlend       *args = (CoreGraphicsStateSetDstBlend*) args_alloc( args_static, sizeof(CoreGraphicsStateSetDstBlend) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );


    args->function = function;

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetDstBlend, args, sizeof(CoreGraphicsStateSetDstBlend), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetDstBlend ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_SetSrcColorKey(IGraphicsState *thiz,
                    u32                                        key
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetSrcColorKey       *args = (CoreGraphicsStateSetSrcColorKey*) args_alloc( args_static, sizeof(CoreGraphicsStateSetSrcColorKey) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );


    args->key = key;

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetSrcColorKey, args, sizeof(CoreGraphicsStateSetSrcColorKey), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetSrcColorKey ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_SetDstColorKey(IGraphicsState *thiz,
                    u32                                        key
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetDstColorKey       *args = (CoreGraphicsStateSetDstColorKey*) args_alloc( args_static, sizeof(CoreGraphicsStateSetDstColorKey) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );


    args->key = key;

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetDstColorKey, args, sizeof(CoreGraphicsStateSetDstColorKey), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetDstColorKey ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_SetDestination(IGraphicsState *thiz,
                    CoreSurface                               *surface
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetDestination       *args = (CoreGraphicsStateSetDestination*) args_alloc( args_static, sizeof(CoreGraphicsStateSetDestination) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( surface != NULL );

    args->surface_id = CoreSurface_GetID( surface );

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetDestination, args, sizeof(CoreGraphicsStateSetDestination), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetDestination ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_SetSource(IGraphicsState *thiz,
                    CoreSurface                               *surface
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetSource       *args = (CoreGraphicsStateSetSource*) args_alloc( args_static, sizeof(CoreGraphicsStateSetSource) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( surface != NULL );

    args->surface_id = CoreSurface_GetID( surface );

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetSource, args, sizeof(CoreGraphicsStateSetSource), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetSource ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_SetSourceMask(IGraphicsState *thiz,
                    CoreSurface                               *surface
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetSourceMask       *args = (CoreGraphicsStateSetSourceMask*) args_alloc( args_static, sizeof(CoreGraphicsStateSetSourceMask) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( surface != NULL );

    args->surface_id = CoreSurface_GetID( surface );

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetSourceMask, args, sizeof(CoreGraphicsStateSetSourceMask), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetSourceMask ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_SetSourceMaskVals(IGraphicsState *thiz,
                    const DFBPoint                            *offset,
                    DFBSurfaceMaskFlags                        flags
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetSourceMaskVals       *args = (CoreGraphicsStateSetSourceMaskVals*) args_alloc( args_static, sizeof(CoreGraphicsStateSetSourceMaskVals) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( offset != NULL );

    args->offset = *offset;
    args->flags = flags;

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetSourceMaskVals, args, sizeof(CoreGraphicsStateSetSourceMaskVals), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetSourceMaskVals ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_SetIndexTranslation(IGraphicsState *thiz,
                    const s32                                 *indices,
                    u32                                        num
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetIndexTranslation       *args = (CoreGraphicsStateSetIndexTranslation*) args_alloc( args_static, sizeof(CoreGraphicsStateSetIndexTranslation) + num * sizeof(s32) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( indices != NULL );

    args->num = num;
    direct_memcpy( (char*) (args + 1), indices, num * sizeof(s32) );

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetIndexTranslation, args, sizeof(CoreGraphicsStateSetIndexTranslation) + num * sizeof(s32), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetIndexTranslation ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_SetColorKey(IGraphicsState *thiz,
                    const DFBColorKey                         *key
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetColorKey       *args = (CoreGraphicsStateSetColorKey*) args_alloc( args_static, sizeof(CoreGraphicsStateSetColorKey) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( key != NULL );

    args->key = *key;

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetColorKey, args, sizeof(CoreGraphicsStateSetColorKey), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetColorKey ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_SetRenderOptions(IGraphicsState *thiz,
                    DFBSurfaceRenderOptions                    options
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetRenderOptions       *args = (CoreGraphicsStateSetRenderOptions*) args_alloc( args_static, sizeof(CoreGraphicsStateSetRenderOptions) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );


    args->options = options;

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetRenderOptions, args, sizeof(CoreGraphicsStateSetRenderOptions), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetRenderOptions ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_SetMatrix(IGraphicsState *thiz,
                    const s32                                 *values
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetMatrix       *args = (CoreGraphicsStateSetMatrix*) args_alloc( args_static, sizeof(CoreGraphicsStateSetMatrix) + 9 * sizeof(s32) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( values != NULL );

    direct_memcpy( (char*) (args + 1), values, 9 * sizeof(s32) );

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetMatrix, args, sizeof(CoreGraphicsStateSetMatrix) + 9 * sizeof(s32), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetMatrix ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_SetSource2(IGraphicsState *thiz,
                    CoreSurface                               *surface
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetSource2       *args = (CoreGraphicsStateSetSource2*) args_alloc( args_static, sizeof(CoreGraphicsStateSetSource2) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( surface != NULL );

    args->surface_id = CoreSurface_GetID( surface );

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetSource2, args, sizeof(CoreGraphicsStateSetSource2), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetSource2 ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_SetFrom(IGraphicsState *thiz,
                    CoreSurfaceBufferRole                      role,
                    DFBSurfaceStereoEye                        eye
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetFrom       *args = (CoreGraphicsStateSetFrom*) args_alloc( args_static, sizeof(CoreGraphicsStateSetFrom) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );


    args->role = role;
    args->eye = eye;

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetFrom, args, sizeof(CoreGraphicsStateSetFrom), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetFrom ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_SetTo(IGraphicsState *thiz,
                    CoreSurfaceBufferRole                      role,
                    DFBSurfaceStereoEye                        eye
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetTo       *args = (CoreGraphicsStateSetTo*) args_alloc( args_static, sizeof(CoreGraphicsStateSetTo) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );


    args->role = role;
    args->eye = eye;

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetTo, args, sizeof(CoreGraphicsStateSetTo), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetTo ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_DrawRectangles(IGraphicsState *thiz,
                    const DFBRectangle                        *rects,
                    u32                                        num
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateDrawRectangles       *args = (CoreGraphicsStateDrawRectangles*) args_alloc( args_static, sizeof(CoreGraphicsStateDrawRectangles) + num * sizeof(DFBRectangle) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( rects != NULL );

    args->num = num;
    direct_memcpy( (char*) (args + 1), rects, num * sizeof(DFBRectangle) );

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_DrawRectangles, args, sizeof(CoreGraphicsStateDrawRectangles) + num * sizeof(DFBRectangle), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_DrawRectangles ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_DrawLines(IGraphicsState *thiz,
                    const DFBRegion                           *lines,
                    u32                                        num
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateDrawLines       *args = (CoreGraphicsStateDrawLines*) args_alloc( args_static, sizeof(CoreGraphicsStateDrawLines) + num * sizeof(DFBRegion) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( lines != NULL );

    args->num = num;
    direct_memcpy( (char*) (args + 1), lines, num * sizeof(DFBRegion) );

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_DrawLines, args, sizeof(CoreGraphicsStateDrawLines) + num * sizeof(DFBRegion), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_DrawLines ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_FillRectangles(IGraphicsState *thiz,
                    const DFBRectangle                        *rects,
                    u32                                        num
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateFillRectangles       *args = (CoreGraphicsStateFillRectangles*) args_alloc( args_static, sizeof(CoreGraphicsStateFillRectangles) + num * sizeof(DFBRectangle) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( rects != NULL );

    args->num = num;
    direct_memcpy( (char*) (args + 1), rects, num * sizeof(DFBRectangle) );

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_FillRectangles, args, sizeof(CoreGraphicsStateFillRectangles) + num * sizeof(DFBRectangle), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_FillRectangles ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_FillTriangles(IGraphicsState *thiz,
                    const DFBTriangle                         *triangles,
                    u32                                        num
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateFillTriangles       *args = (CoreGraphicsStateFillTriangles*) args_alloc( args_static, sizeof(CoreGraphicsStateFillTriangles) + num * sizeof(DFBTriangle) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( triangles != NULL );

    args->num = num;
    direct_memcpy( (char*) (args + 1), triangles, num * sizeof(DFBTriangle) );

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_FillTriangles, args, sizeof(CoreGraphicsStateFillTriangles) + num * sizeof(DFBTriangle), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_FillTriangles ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_FillTrapezoids(IGraphicsState *thiz,
                    const DFBTrapezoid                        *trapezoids,
                    u32                                        num
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateFillTrapezoids       *args = (CoreGraphicsStateFillTrapezoids*) args_alloc( args_static, sizeof(CoreGraphicsStateFillTrapezoids) + num * sizeof(DFBTrapezoid) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( trapezoids != NULL );

    args->num = num;
    direct_memcpy( (char*) (args + 1), trapezoids, num * sizeof(DFBTrapezoid) );

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_FillTrapezoids, args, sizeof(CoreGraphicsStateFillTrapezoids) + num * sizeof(DFBTrapezoid), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_FillTrapezoids ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_FillSpans(IGraphicsState *thiz,
                    s32                                        y,
                    const DFBSpan                             *spans,
                    u32                                        num
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateFillSpans       *args = (CoreGraphicsStateFillSpans*) args_alloc( args_static, sizeof(CoreGraphicsStateFillSpans) + num * sizeof(DFBSpan) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( spans != NULL );

    args->y = y;
    args->num = num;
    direct_memcpy( (char*) (args + 1), spans, num * sizeof(DFBSpan) );

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_FillSpans, args, sizeof(CoreGraphicsStateFillSpans) + num * sizeof(DFBSpan), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_FillSpans ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_Blit(IGraphicsState *thiz,
                    const DFBRectangle                        *rects,
                    const DFBPoint                            *points,
                    u32                                        num
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateBlit       *args = (CoreGraphicsStateBlit*) args_alloc( args_static, sizeof(CoreGraphicsStateBlit) + num * sizeof(DFBRectangle) + num * sizeof(DFBPoint) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( rects != NULL );
    D_ASSERT( points != NULL );

    args->num = num;
    direct_memcpy( (char*) (args + 1), rects, num * sizeof(DFBRectangle) );
    direct_memcpy( (char*) (args + 1) + num * sizeof(DFBRectangle), points, num * sizeof(DFBPoint) );

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_Blit, args, sizeof(CoreGraphicsStateBlit) + num * sizeof(DFBRectangle) + num * sizeof(DFBPoint), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_Blit ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_Blit2(IGraphicsState *thiz,
                    const DFBRectangle                        *rects,
                    const DFBPoint                            *points1,
                    const DFBPoint                            *points2,
                    u32                                        num
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateBlit2       *args = (CoreGraphicsStateBlit2*) args_alloc( args_static, sizeof(CoreGraphicsStateBlit2) + num * sizeof(DFBRectangle) + num * sizeof(DFBPoint) + num * sizeof(DFBPoint) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( rects != NULL );
    D_ASSERT( points1 != NULL );
    D_ASSERT( points2 != NULL );

    args->num = num;
    direct_memcpy( (char*) (args + 1), rects, num * sizeof(DFBRectangle) );
    direct_memcpy( (char*) (args + 1) + num * sizeof(DFBRectangle), points1, num * sizeof(DFBPoint) );
    direct_memcpy( (char*) (args + 1) + num * sizeof(DFBRectangle) + num * sizeof(DFBPoint), points2, num * sizeof(DFBPoint) );

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_Blit2, args, sizeof(CoreGraphicsStateBlit2) + num * sizeof(DFBRectangle) + num * sizeof(DFBPoint) + num * sizeof(DFBPoint), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_Blit2 ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_StretchBlit(IGraphicsState *thiz,
                    const DFBRectangle                        *srects,
                    const DFBRectangle                        *drects,
                    u32                                        num
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateStretchBlit       *args = (CoreGraphicsStateStretchBlit*) args_alloc( args_static, sizeof(CoreGraphicsStateStretchBlit) + num * sizeof(DFBRectangle) + num * sizeof(DFBRectangle) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( srects != NULL );
    D_ASSERT( drects != NULL );

    args->num = num;
    direct_memcpy( (char*) (args + 1), srects, num * sizeof(DFBRectangle) );
    direct_memcpy( (char*) (args + 1) + num * sizeof(DFBRectangle), drects, num * sizeof(DFBRectangle) );

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_StretchBlit, args, sizeof(CoreGraphicsStateStretchBlit) + num * sizeof(DFBRectangle) + num * sizeof(DFBRectangle), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_StretchBlit ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_TileBlit(IGraphicsState *thiz,
                    const DFBRectangle                        *rects,
                    const DFBPoint                            *points1,
                    const DFBPoint                            *points2,
                    u32                                        num
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateTileBlit       *args = (CoreGraphicsStateTileBlit*) args_alloc( args_static, sizeof(CoreGraphicsStateTileBlit) + num * sizeof(DFBRectangle) + num * sizeof(DFBPoint) + num * sizeof(DFBPoint) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( rects != NULL );
    D_ASSERT( points1 != NULL );
    D_ASSERT( points2 != NULL );

    args->num = num;
    direct_memcpy( (char*) (args + 1), rects, num * sizeof(DFBRectangle) );
    direct_memcpy( (char*) (args + 1) + num * sizeof(DFBRectangle), points1, num * sizeof(DFBPoint) );
    direct_memcpy( (char*) (args + 1) + num * sizeof(DFBRectangle) + num * sizeof(DFBPoint), points2, num * sizeof(DFBPoint) );

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_TileBlit, args, sizeof(CoreGraphicsStateTileBlit) + num * sizeof(DFBRectangle) + num * sizeof(DFBPoint) + num * sizeof(DFBPoint), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_TileBlit ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_TextureTriangles(IGraphicsState *thiz,
                    const DFBVertex                           *vertices,
                    u32                                        num,
                    DFBTriangleFormation                       formation
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateTextureTriangles       *args = (CoreGraphicsStateTextureTriangles*) args_alloc( args_static, sizeof(CoreGraphicsStateTextureTriangles) + num * sizeof(DFBVertex) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( vertices != NULL );

    args->num = num;
    args->formation = formation;
    direct_memcpy( (char*) (args + 1), vertices, num * sizeof(DFBVertex) );

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_TextureTriangles, args, sizeof(CoreGraphicsStateTextureTriangles) + num * sizeof(DFBVertex), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_TextureTriangles ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_Flush(IGraphicsState *thiz

)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateFlush       *args = (CoreGraphicsStateFlush*) args_alloc( args_static, sizeof(CoreGraphicsStateFlush) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );



    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_Flush, args, sizeof(CoreGraphicsStateFlush), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_Flush ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_ReleaseSource(IGraphicsState *thiz

)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateReleaseSource       *args = (CoreGraphicsStateReleaseSource*) args_alloc( args_static, sizeof(CoreGraphicsStateReleaseSource) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );



    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_ReleaseSource, args, sizeof(CoreGraphicsStateReleaseSource), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_ReleaseSource ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}


DFBResult
IGraphicsStateRequestor_SetSrcConvolution(IGraphicsState *thiz,
                    const DFBConvolutionFilter                *filter
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreGraphicsStateSetSrcConvolution       *args = (CoreGraphicsStateSetSrcConvolution*) args_alloc( args_static, sizeof(CoreGraphicsStateSetSrcConvolution) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "IGraphicsStateRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( filter != NULL );

    args->filter = *filter;

    ret = (DFBResult) CoreGraphicsState_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY | FCEF_QUEUE), CoreGraphicsStateCall_SetSrcConvolution, args, sizeof(CoreGraphicsStateSetSrcConvolution), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreGraphicsState_Call( CoreGraphicsState_SetSrcConvolution ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}

void IGraphicsStateRequestorInit(IGraphicsStateRequestor *thiz, CoreDFB *core, CoreGraphicsState *obj)
{
	thiz->base.core = core;
	thiz->base.obj = obj;

    thiz->base.SetDrawingFlags = IGraphicsStateRequestor_SetDrawingFlags;
    thiz->base.SetBlittingFlags =IGraphicsStateRequestor_SetBlittingFlags;
    thiz->base.SetClip = IGraphicsStateRequestor_SetClip;
    thiz->base.SetColor = IGraphicsStateRequestor_SetColor;
    thiz->base.SetColorAndIndex = IGraphicsStateRequestor_SetColorAndIndex;
    thiz->base.SetSrcBlend = IGraphicsStateRequestor_SetSrcBlend;
    thiz->base.SetDstBlend = IGraphicsStateRequestor_SetDstBlend;
    thiz->base.SetSrcColorKey = IGraphicsStateRequestor_SetSrcColorKey;
    thiz->base.SetDstColorKey = IGraphicsStateRequestor_SetDstColorKey;
    thiz->base.SetDestination = IGraphicsStateRequestor_SetDestination;
    thiz->base.SetSource = IGraphicsStateRequestor_SetSource;
    thiz->base.SetSourceMask = IGraphicsStateRequestor_SetSourceMask;
    thiz->base.SetSourceMaskVals = IGraphicsStateRequestor_SetSourceMaskVals;
    thiz->base.SetIndexTranslation = IGraphicsStateRequestor_SetIndexTranslation;
    thiz->base.SetColorKey = IGraphicsStateRequestor_SetColorKey;
    thiz->base.SetRenderOptions = IGraphicsStateRequestor_SetRenderOptions;
    thiz->base.SetMatrix = IGraphicsStateRequestor_SetMatrix;
    thiz->base.SetSource2 = IGraphicsStateRequestor_SetSource2;
    thiz->base.SetFrom = IGraphicsStateRequestor_SetFrom;
    thiz->base.SetTo = IGraphicsStateRequestor_SetTo;
    thiz->base.DrawRectangles = IGraphicsStateRequestor_DrawRectangles;
    thiz->base.DrawLines = IGraphicsStateRequestor_DrawLines;
    thiz->base.FillRectangles = IGraphicsStateRequestor_FillRectangles;
    thiz->base.FillTriangles = IGraphicsStateRequestor_FillTriangles;
    thiz->base.FillTrapezoids = IGraphicsStateRequestor_FillTrapezoids;
    thiz->base.FillSpans = IGraphicsStateRequestor_FillSpans;
    thiz->base.Blit = IGraphicsStateRequestor_Blit;
    thiz->base.Blit2 = IGraphicsStateRequestor_Blit2;
    thiz->base.StretchBlit = IGraphicsStateRequestor_StretchBlit;
    thiz->base.TileBlit = IGraphicsStateRequestor_TileBlit;
    thiz->base.TextureTriangles = IGraphicsStateRequestor_TextureTriangles;
    thiz->base.Flush = IGraphicsStateRequestor_Flush;
    thiz->base.ReleaseSource = IGraphicsStateRequestor_ReleaseSource;
    thiz->base.SetSrcConvolution = IGraphicsStateRequestor_SetSrcConvolution;
}


/*********************************************************************************************************************/

static DFBResult
__CoreGraphicsStateDispatch__Dispatch( CoreGraphicsState *obj,
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


	IGraphicsStateReal real;
	IGraphicsState *super = (IGraphicsState *)&real;
	IGraphicsStateRealInit( &real, core_dfb, obj );

    switch (method) {
        case CoreGraphicsStateCall_SetDrawingFlags: {
            D_UNUSED
            CoreGraphicsStateSetDrawingFlags       *args        = (CoreGraphicsStateSetDrawingFlags *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetDrawingFlags\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> flags = %x\n", args->flags );

            super->SetDrawingFlags( super, args->flags );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_SetBlittingFlags: {
            D_UNUSED
            CoreGraphicsStateSetBlittingFlags       *args        = (CoreGraphicsStateSetBlittingFlags *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetBlittingFlags\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> flags = %x\n", args->flags );

            super->SetBlittingFlags( super, args->flags );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_SetClip: {
            D_UNUSED
            CoreGraphicsStateSetClip       *args        = (CoreGraphicsStateSetClip *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetClip\n" );

         ;    // TODO: DFBRegion_debug args->region;

            super->SetClip( super, &args->region );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_SetColor: {
            D_UNUSED
            CoreGraphicsStateSetColor       *args        = (CoreGraphicsStateSetColor *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetColor\n" );

         ;    // TODO: DFBColor_debug args->color;

            super->SetColor( super, &args->color );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_SetColorAndIndex: {
            D_UNUSED
            CoreGraphicsStateSetColorAndIndex       *args        = (CoreGraphicsStateSetColorAndIndex *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetColorAndIndex\n" );

         ;    // TODO: DFBColor_debug args->color;
            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> index = %u\n", args->index );

            super->SetColorAndIndex( super, &args->color, args->index );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_SetSrcBlend: {
            D_UNUSED
            CoreGraphicsStateSetSrcBlend       *args        = (CoreGraphicsStateSetSrcBlend *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetSrcBlend\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> function = %x\n", args->function );

            super->SetSrcBlend( super, args->function );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_SetDstBlend: {
            D_UNUSED
            CoreGraphicsStateSetDstBlend       *args        = (CoreGraphicsStateSetDstBlend *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetDstBlend\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> function = %x\n", args->function );

            super->SetDstBlend( super, args->function );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_SetSrcColorKey: {
            D_UNUSED
            CoreGraphicsStateSetSrcColorKey       *args        = (CoreGraphicsStateSetSrcColorKey *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetSrcColorKey\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> key = %u\n", args->key );

            super->SetSrcColorKey( super, args->key );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_SetDstColorKey: {
            D_UNUSED
            CoreGraphicsStateSetDstColorKey       *args        = (CoreGraphicsStateSetDstColorKey *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetDstColorKey\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> key = %u\n", args->key );

            super->SetDstColorKey( super, args->key );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_SetDestination: {
    		CoreSurface *surface = NULL;
            D_UNUSED
            CoreGraphicsStateSetDestination       *args        = (CoreGraphicsStateSetDestination *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetDestination\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> surface = %d\n", args->surface_id );

            ret = (DFBResult) CoreSurface_Lookup( core_dfb, args->surface_id, caller, &surface );
            if (ret) {
                 D_DERROR( ret, "%s: Looking up surface by ID %u failed!\n", __FUNCTION__, args->surface_id );
                 return ret;
            }

            super->SetDestination( super, surface );

            if (surface)
                CoreSurface_Unref( surface );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_SetSource: {
    		CoreSurface *surface = NULL;
            D_UNUSED
            CoreGraphicsStateSetSource       *args        = (CoreGraphicsStateSetSource *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetSource\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> surface = %d\n", args->surface_id );

            ret = (DFBResult) CoreSurface_Lookup( core_dfb, args->surface_id, caller, &surface );
            if (ret) {
                 D_DERROR( ret, "%s: Looking up surface by ID %u failed!\n", __FUNCTION__, args->surface_id );
                 return ret;
            }

            super->SetSource( super, surface );

            if (surface)
                CoreSurface_Unref( surface );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_SetSourceMask: {
    		CoreSurface *surface = NULL;
            D_UNUSED
            CoreGraphicsStateSetSourceMask       *args        = (CoreGraphicsStateSetSourceMask *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetSourceMask\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> surface = %d\n", args->surface_id );

            ret = (DFBResult) CoreSurface_Lookup( core_dfb, args->surface_id, caller, &surface );
            if (ret) {
                 D_DERROR( ret, "%s: Looking up surface by ID %u failed!\n", __FUNCTION__, args->surface_id );
                 return ret;
            }

            super->SetSourceMask( super, surface );

            if (surface)
                CoreSurface_Unref( surface );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_SetSourceMaskVals: {
            D_UNUSED
            CoreGraphicsStateSetSourceMaskVals       *args        = (CoreGraphicsStateSetSourceMaskVals *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetSourceMaskVals\n" );

         ;    // TODO: DFBPoint_debug args->offset;
            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> flags = %x\n", args->flags );

            super->SetSourceMaskVals( super, &args->offset, args->flags );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_SetIndexTranslation: {
            D_UNUSED
            CoreGraphicsStateSetIndexTranslation       *args        = (CoreGraphicsStateSetIndexTranslation *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetIndexTranslation\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> num = %u\n", args->num );

            super->SetIndexTranslation( super, (s32*) ((char*)(args + 1)), args->num );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_SetColorKey: {
            D_UNUSED
            CoreGraphicsStateSetColorKey       *args        = (CoreGraphicsStateSetColorKey *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetColorKey\n" );

         ;    // TODO: DFBColorKey_debug args->key;

            super->SetColorKey( super, &args->key );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_SetRenderOptions: {
            D_UNUSED
            CoreGraphicsStateSetRenderOptions       *args        = (CoreGraphicsStateSetRenderOptions *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetRenderOptions\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> options = %x\n", args->options );

            super->SetRenderOptions( super, args->options );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_SetMatrix: {
            D_UNUSED
            CoreGraphicsStateSetMatrix       *args        = (CoreGraphicsStateSetMatrix *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetMatrix\n" );


            super->SetMatrix( super, (s32*) ((char*)(args + 1)) );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_SetSource2: {
    		CoreSurface *surface = NULL;
            D_UNUSED
            CoreGraphicsStateSetSource2       *args        = (CoreGraphicsStateSetSource2 *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetSource2\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> surface = %d\n", args->surface_id );

            ret = (DFBResult) CoreSurface_Lookup( core_dfb, args->surface_id, caller, &surface );
            if (ret) {
                 D_DERROR( ret, "%s: Looking up surface by ID %u failed!\n", __FUNCTION__, args->surface_id );
                 return ret;
            }

            super->SetSource2( super, surface );

            if (surface)
                CoreSurface_Unref( surface );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_SetFrom: {
            D_UNUSED
            CoreGraphicsStateSetFrom       *args        = (CoreGraphicsStateSetFrom *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetFrom\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> role = %x\n", args->role );
            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> eye = %x\n", args->eye );

            super->SetFrom( super, args->role, args->eye );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_SetTo: {
            D_UNUSED
            CoreGraphicsStateSetTo       *args        = (CoreGraphicsStateSetTo *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetTo\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> role = %x\n", args->role );
            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> eye = %x\n", args->eye );

            super->SetTo( super, args->role, args->eye );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_DrawRectangles: {
            D_UNUSED
            CoreGraphicsStateDrawRectangles       *args        = (CoreGraphicsStateDrawRectangles *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_DrawRectangles\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> num = %u\n", args->num );

            super->DrawRectangles( super, (DFBRectangle*) ((char*)(args + 1)), args->num );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_DrawLines: {
            D_UNUSED
            CoreGraphicsStateDrawLines       *args        = (CoreGraphicsStateDrawLines *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_DrawLines\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> num = %u\n", args->num );

            super->DrawLines( super, (DFBRegion*) ((char*)(args + 1)), args->num );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_FillRectangles: {
            D_UNUSED
            CoreGraphicsStateFillRectangles       *args        = (CoreGraphicsStateFillRectangles *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_FillRectangles\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> num = %u\n", args->num );

            super->FillRectangles( super, (DFBRectangle*) ((char*)(args + 1)), args->num );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_FillTriangles: {
            D_UNUSED
            CoreGraphicsStateFillTriangles       *args        = (CoreGraphicsStateFillTriangles *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_FillTriangles\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> num = %u\n", args->num );

            super->FillTriangles( super, (DFBTriangle*) ((char*)(args + 1)), args->num );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_FillTrapezoids: {
            D_UNUSED
            CoreGraphicsStateFillTrapezoids       *args        = (CoreGraphicsStateFillTrapezoids *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_FillTrapezoids\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> num = %u\n", args->num );

            super->FillTrapezoids( super, (DFBTrapezoid*) ((char*)(args + 1)), args->num );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_FillSpans: {
            D_UNUSED
            CoreGraphicsStateFillSpans       *args        = (CoreGraphicsStateFillSpans *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_FillSpans\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> y = %d\n", args->y );
            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> num = %u\n", args->num );

            super->FillSpans( super, args->y, (DFBSpan*) ((char*)(args + 1)), args->num );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_Blit: {
            D_UNUSED
            CoreGraphicsStateBlit       *args        = (CoreGraphicsStateBlit *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_Blit\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> num = %u\n", args->num );

            super->Blit( super, (DFBRectangle*) ((char*)(args + 1)), (DFBPoint*) ((char*)(args + 1) + args->num * sizeof(DFBRectangle)), args->num );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_Blit2: {
            D_UNUSED
            CoreGraphicsStateBlit2       *args        = (CoreGraphicsStateBlit2 *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_Blit2\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> num = %u\n", args->num );

            super->Blit2( super, (DFBRectangle*) ((char*)(args + 1)), (DFBPoint*) ((char*)(args + 1) + args->num * sizeof(DFBRectangle)), (DFBPoint*) ((char*)(args + 1) + args->num * sizeof(DFBRectangle) + args->num * sizeof(DFBPoint)), args->num );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_StretchBlit: {
            D_UNUSED
            CoreGraphicsStateStretchBlit       *args        = (CoreGraphicsStateStretchBlit *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_StretchBlit\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> num = %u\n", args->num );

            super->StretchBlit( super, (DFBRectangle*) ((char*)(args + 1)), (DFBRectangle*) ((char*)(args + 1) + args->num * sizeof(DFBRectangle)), args->num );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_TileBlit: {
            D_UNUSED
            CoreGraphicsStateTileBlit       *args        = (CoreGraphicsStateTileBlit *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_TileBlit\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> num = %u\n", args->num );

            super->TileBlit( super, (DFBRectangle*) ((char*)(args + 1)), (DFBPoint*) ((char*)(args + 1) + args->num * sizeof(DFBRectangle)), (DFBPoint*) ((char*)(args + 1) + args->num * sizeof(DFBRectangle) + args->num * sizeof(DFBPoint)), args->num );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_TextureTriangles: {
            D_UNUSED
            CoreGraphicsStateTextureTriangles       *args        = (CoreGraphicsStateTextureTriangles *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_TextureTriangles\n" );

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> num = %u\n", args->num );
            D_DEBUG_AT( DirectFB_CoreGraphicsState, "  -> formation = %x\n", args->formation );

            super->TextureTriangles( super, (DFBVertex*) ((char*)(args + 1)), args->num, args->formation );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_Flush: {
            D_UNUSED
            CoreGraphicsStateFlush       *args        = (CoreGraphicsStateFlush *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_Flush\n" );


            super->Flush( super );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_ReleaseSource: {
            D_UNUSED
            CoreGraphicsStateReleaseSource       *args        = (CoreGraphicsStateReleaseSource *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_ReleaseSource\n" );


            super->ReleaseSource( super );

            return DFB_OK;
        }

        case CoreGraphicsStateCall_SetSrcConvolution: {
            D_UNUSED
            CoreGraphicsStateSetSrcConvolution       *args        = (CoreGraphicsStateSetSrcConvolution *) ptr;

            D_DEBUG_AT( DirectFB_CoreGraphicsState, "=-> CoreGraphicsState_SetSrcConvolution\n" );

         ;    // TODO: DFBConvolutionFilter_debug args->filter;

            super->SetSrcConvolution( super, &args->filter );

            return DFB_OK;
        }

    }

    return DFB_NOSUCHMETHOD;
}
/*********************************************************************************************************************/

DFBResult
CoreGraphicsStateDispatch__Dispatch( CoreGraphicsState *obj,
                                FusionID      caller,
                                int           method,
                                void         *ptr,
                                unsigned int  length,
                                void         *ret_ptr,
                                unsigned int  ret_size,
                                unsigned int *ret_length )
{
    DFBResult ret = DFB_OK;

    D_DEBUG_AT( DirectFB_CoreGraphicsState, "CoreGraphicsStateDispatch::%s( %p )\n", __FUNCTION__, obj );

    Core_PushIdentity( caller );

    ret = __CoreGraphicsStateDispatch__Dispatch( obj, caller, method, ptr, length, ret_ptr, ret_size, ret_length );

    Core_PopIdentity();

    return ret;
}

