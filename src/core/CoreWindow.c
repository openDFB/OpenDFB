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

#include "CoreWindow.h"

#include <directfb_util.h>

#include <direct/debug.h>
#include <direct/mem.h>
#include <direct/memcpy.h>
#include <direct/messages.h>

#include <fusion/conf.h>

#include <core/core.h>

#include <core/CoreDFB_CallMode.h>

D_DEBUG_DOMAIN( DirectFB_CoreWindow, "DirectFB/CoreWindow", "DirectFB CoreWindow" );

/*********************************************************************************************************************/

DFBResult
CoreWindow_Repaint(
                    CoreWindow                                *obj,
                    const DFBRegion                           *left,
                    const DFBRegion                           *right,
                    DFBSurfaceFlipFlags                        flags
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->Repaint( super, left, right, flags );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->Repaint( super, left, right, flags );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_BeginUpdates(
                    CoreWindow                                *obj,
                    const DFBRegion                           *update
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->BeginUpdates( super, update );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->BeginUpdates( super, update );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_Restack(
                    CoreWindow                                *obj,
                    CoreWindow                                *relative,
                    int                                        relation
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->Restack( super, relative, relation );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->Restack( super, relative, relation );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_SetConfig(
                    CoreWindow                                *obj,
                    const CoreWindowConfig                    *config,
                    const DFBInputDeviceKeySymbol             *keys,
                    u32                                        num_keys,
                    CoreWindowConfigFlags                      flags
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetConfig( super, config, keys, num_keys, flags );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetConfig( super, config, keys, num_keys, flags );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_Bind(
                    CoreWindow                                *obj,
                    CoreWindow                                *source,
                    int                                        x,
                    int                                        y
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->Bind( super, source, x, y );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->Bind( super, source, x, y );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_Unbind(
                    CoreWindow                                *obj,
                    CoreWindow                                *source
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->Unbind( super, source );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->Unbind( super, source );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_RequestFocus(
                    CoreWindow                                *obj

)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->RequestFocus( super );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->RequestFocus( super );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_ChangeGrab(
                    CoreWindow                                *obj,
                    CoreWMGrabTarget                           target,
                    bool                                       grab
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->ChangeGrab( super, target, grab );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->ChangeGrab( super, target, grab );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_GrabKey(
                    CoreWindow                                *obj,
                    DFBInputDeviceKeySymbol                    symbol,
                    DFBInputDeviceModifierMask                 modifiers
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->GrabKey( super, symbol, modifiers );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->GrabKey( super, symbol, modifiers );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_UngrabKey(
                    CoreWindow                                *obj,
                    DFBInputDeviceKeySymbol                    symbol,
                    DFBInputDeviceModifierMask                 modifiers
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->UngrabKey( super, symbol, modifiers );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->UngrabKey( super, symbol, modifiers );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_Move(
                    CoreWindow                                *obj,
                    int                                        dx,
                    int                                        dy
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->Move( super, dx, dy );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->Move( super, dx, dy );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_MoveTo(
                    CoreWindow                                *obj,
                    int                                        x,
                    int                                        y
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->MoveTo( super, x, y );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->MoveTo( super, x, y );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_Resize(
                    CoreWindow                                *obj,
                    int                                        width,
                    int                                        height
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->Resize( super, width, height );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->Resize( super, width, height );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_Destroy(
                    CoreWindow                                *obj

)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->Destroy( super );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->Destroy( super );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_SetCursorPosition(
                    CoreWindow                                *obj,
                    int                                        x,
                    int                                        y
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetCursorPosition( super, x, y );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetCursorPosition( super, x, y );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_ChangeEvents(
                    CoreWindow                                *obj,
                    DFBWindowEventType                         disable,
                    DFBWindowEventType                         enable
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->ChangeEvents( super, disable, enable );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->ChangeEvents( super, disable, enable );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_ChangeOptions(
                    CoreWindow                                *obj,
                    DFBWindowOptions                           disable,
                    DFBWindowOptions                           enable
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->ChangeOptions( super, disable, enable );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->ChangeOptions( super, disable, enable );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_SetColor(
                    CoreWindow                                *obj,
                    const DFBColor                            *color
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetColor( super, color );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

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
CoreWindow_SetColorKey(
                    CoreWindow                                *obj,
                    u32                                        key
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetColorKey( super, key );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

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
CoreWindow_SetOpaque(
                    CoreWindow                                *obj,
                    const DFBRegion                           *opaque
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetOpaque( super, opaque );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetOpaque( super, opaque );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_SetOpacity(
                    CoreWindow                                *obj,
                    u8                                         opacity
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetOpacity( super, opacity );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetOpacity( super, opacity );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_SetStacking(
                    CoreWindow                                *obj,
                    DFBWindowStackingClass                     stacking
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetStacking( super, stacking );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetStacking( super, stacking );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_SetBounds(
                    CoreWindow                                *obj,
                    const DFBRectangle                        *bounds
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetBounds( super, bounds );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetBounds( super, bounds );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_SetKeySelection(
                    CoreWindow                                *obj,
                    DFBWindowKeySelection                      selection,
                    const DFBInputDeviceKeySymbol             *keys,
                    u32                                        num_keys
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetKeySelection( super, selection, keys, num_keys );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetKeySelection( super, selection, keys, num_keys );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_SetRotation(
                    CoreWindow                                *obj,
                    int                                        rotation
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetRotation( super, rotation );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetRotation( super, rotation );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_GetSurface(
                    CoreWindow                                *obj,
                    CoreSurface                              **ret_surface
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->GetSurface( super, ret_surface );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->GetSurface( super, ret_surface );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_SetCursorShape(
                    CoreWindow                                *obj,
                    CoreSurface                               *shape,
                    const DFBPoint                            *hotspot
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetCursorShape( super, shape, hotspot );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetCursorShape( super, shape, hotspot );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_AllowFocus(
                    CoreWindow                                *obj

)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->AllowFocus( super );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->AllowFocus( super );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreWindow_GetInsets(
                    CoreWindow                                *obj,
                    DFBInsets                                 *ret_insets
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            IWindowReal real;
			IWindow *super = (IWindow *)&real;
			IWindowRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->GetInsets( super, ret_insets );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
            IWindowRequestor requestor;
			IWindow *super = (IWindow *)&requestor;
			IWindowRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->GetInsets( super, ret_insets );
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
CoreWindow_Dispatch( int           caller,   /* fusion id of the caller */
                     int           call_arg, /* optional call parameter */
                     void         *ptr, /* optional call parameter */
                     unsigned int  length,
                     void         *ctx,      /* optional handler context */
                     unsigned int  serial,
                     void         *ret_ptr,
                     unsigned int  ret_size,
                     unsigned int *ret_length )
{
    CoreWindow *obj = (CoreWindow*) ctx;
    CoreWindowDispatch__Dispatch( obj, caller, call_arg, ptr, length, ret_ptr, ret_size, ret_length );

    return FCHR_RETURN;
}

void CoreWindow_Init_Dispatch(
                    CoreDFB              *core,
                    CoreWindow           *obj,
                    FusionCall           *call
)
{
    fusion_call_init3( call, CoreWindow_Dispatch, obj, core->world );
}

void  CoreWindow_Deinit_Dispatch(
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
IWindowRequestor_Repaint(IWindow *thiz,
                    const DFBRegion                           *left,
                    const DFBRegion                           *right,
                    DFBSurfaceFlipFlags                        flags
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowRepaint       *args = (CoreWindowRepaint*) args_alloc( args_static, sizeof(CoreWindowRepaint) );
    CoreWindowRepaintReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowRepaintReturn*) args_alloc( return_args_static, sizeof(CoreWindowRepaintReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );

    D_ASSERT( left != NULL );
    D_ASSERT( right != NULL );

    args->left = *left;
    args->right = *right;
    args->flags = flags;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_Repaint, args, sizeof(CoreWindowRepaint), return_args, sizeof(CoreWindowRepaintReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_Repaint ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_Repaint failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_BeginUpdates(IWindow *thiz,
                    const DFBRegion                           *update
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowBeginUpdates       *args = (CoreWindowBeginUpdates*) args_alloc( args_static, sizeof(CoreWindowBeginUpdates) );
    CoreWindowBeginUpdatesReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowBeginUpdatesReturn*) args_alloc( return_args_static, sizeof(CoreWindowBeginUpdatesReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );


  if (update) {
    args->update = *update;
    args->update_set = true;
  }
  else
    args->update_set = false;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_BeginUpdates, args, sizeof(CoreWindowBeginUpdates), return_args, sizeof(CoreWindowBeginUpdatesReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_BeginUpdates ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_BeginUpdates failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_Restack(IWindow *thiz,
                    CoreWindow                                *relative,
                    int                                        relation
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowRestack       *args = (CoreWindowRestack*) args_alloc( args_static, sizeof(CoreWindowRestack) );
    CoreWindowRestackReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowRestackReturn*) args_alloc( return_args_static, sizeof(CoreWindowRestackReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );


  if (relative) {
    args->relative_id = CoreWindow_GetID( relative );
    args->relative_set = true;
  }
  else
    args->relative_set = false;
    args->relation = relation;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_Restack, args, sizeof(CoreWindowRestack), return_args, sizeof(CoreWindowRestackReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_Restack ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_Restack failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_SetConfig(IWindow *thiz,
                    const CoreWindowConfig                    *config,
                    const DFBInputDeviceKeySymbol             *keys,
                    u32                                        num_keys,
                    CoreWindowConfigFlags                      flags
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowSetConfig       *args = (CoreWindowSetConfig*) args_alloc( args_static, sizeof(CoreWindowSetConfig) + num_keys * sizeof(DFBInputDeviceKeySymbol) );
    CoreWindowSetConfigReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowSetConfigReturn*) args_alloc( return_args_static, sizeof(CoreWindowSetConfigReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );

    D_ASSERT( config != NULL );

    args->config = *config;
    args->num_keys = num_keys;
    args->flags = flags;
  if (keys) {
    direct_memcpy( (char*) (args + 1), keys, num_keys * sizeof(DFBInputDeviceKeySymbol) );
    args->keys_set = true;
  }
  else {
    args->keys_set = false;
    keys = 0;
  }

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_SetConfig, args, sizeof(CoreWindowSetConfig) + num_keys * sizeof(DFBInputDeviceKeySymbol), return_args, sizeof(CoreWindowSetConfigReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_SetConfig ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_SetConfig failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_Bind(IWindow *thiz,
                    CoreWindow                                *source,
                    int                                        x,
                    int                                        y
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowBind       *args = (CoreWindowBind*) args_alloc( args_static, sizeof(CoreWindowBind) );
    CoreWindowBindReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowBindReturn*) args_alloc( return_args_static, sizeof(CoreWindowBindReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );

    D_ASSERT( source != NULL );

    args->source_id = CoreWindow_GetID( source );
    args->x = x;
    args->y = y;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_Bind, args, sizeof(CoreWindowBind), return_args, sizeof(CoreWindowBindReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_Bind ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_Bind failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_Unbind(IWindow *thiz,
                    CoreWindow                                *source
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowUnbind       *args = (CoreWindowUnbind*) args_alloc( args_static, sizeof(CoreWindowUnbind) );
    CoreWindowUnbindReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowUnbindReturn*) args_alloc( return_args_static, sizeof(CoreWindowUnbindReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );

    D_ASSERT( source != NULL );

    args->source_id = CoreWindow_GetID( source );

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_Unbind, args, sizeof(CoreWindowUnbind), return_args, sizeof(CoreWindowUnbindReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_Unbind ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_Unbind failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_RequestFocus(IWindow *thiz

)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowRequestFocus       *args = (CoreWindowRequestFocus*) args_alloc( args_static, sizeof(CoreWindowRequestFocus) );
    CoreWindowRequestFocusReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowRequestFocusReturn*) args_alloc( return_args_static, sizeof(CoreWindowRequestFocusReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );



    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_RequestFocus, args, sizeof(CoreWindowRequestFocus), return_args, sizeof(CoreWindowRequestFocusReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_RequestFocus ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_RequestFocus failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_ChangeGrab(IWindow *thiz,
                    CoreWMGrabTarget                           target,
                    bool                                       grab
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowChangeGrab       *args = (CoreWindowChangeGrab*) args_alloc( args_static, sizeof(CoreWindowChangeGrab) );
    CoreWindowChangeGrabReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowChangeGrabReturn*) args_alloc( return_args_static, sizeof(CoreWindowChangeGrabReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );


    args->target = target;
    args->grab = grab;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_ChangeGrab, args, sizeof(CoreWindowChangeGrab), return_args, sizeof(CoreWindowChangeGrabReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_ChangeGrab ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_ChangeGrab failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_GrabKey(IWindow *thiz,
                    DFBInputDeviceKeySymbol                    symbol,
                    DFBInputDeviceModifierMask                 modifiers
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowGrabKey       *args = (CoreWindowGrabKey*) args_alloc( args_static, sizeof(CoreWindowGrabKey) );
    CoreWindowGrabKeyReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowGrabKeyReturn*) args_alloc( return_args_static, sizeof(CoreWindowGrabKeyReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );


    args->symbol = symbol;
    args->modifiers = modifiers;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_GrabKey, args, sizeof(CoreWindowGrabKey), return_args, sizeof(CoreWindowGrabKeyReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_GrabKey ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_GrabKey failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_UngrabKey(IWindow *thiz,
                    DFBInputDeviceKeySymbol                    symbol,
                    DFBInputDeviceModifierMask                 modifiers
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowUngrabKey       *args = (CoreWindowUngrabKey*) args_alloc( args_static, sizeof(CoreWindowUngrabKey) );
    CoreWindowUngrabKeyReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowUngrabKeyReturn*) args_alloc( return_args_static, sizeof(CoreWindowUngrabKeyReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );


    args->symbol = symbol;
    args->modifiers = modifiers;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_UngrabKey, args, sizeof(CoreWindowUngrabKey), return_args, sizeof(CoreWindowUngrabKeyReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_UngrabKey ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_UngrabKey failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_Move(IWindow *thiz,
                    int                                        dx,
                    int                                        dy
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowMove       *args = (CoreWindowMove*) args_alloc( args_static, sizeof(CoreWindowMove) );
    CoreWindowMoveReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowMoveReturn*) args_alloc( return_args_static, sizeof(CoreWindowMoveReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );


    args->dx = dx;
    args->dy = dy;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_Move, args, sizeof(CoreWindowMove), return_args, sizeof(CoreWindowMoveReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_Move ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_Move failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_MoveTo(IWindow *thiz,
                    int                                        x,
                    int                                        y
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowMoveTo       *args = (CoreWindowMoveTo*) args_alloc( args_static, sizeof(CoreWindowMoveTo) );
    CoreWindowMoveToReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowMoveToReturn*) args_alloc( return_args_static, sizeof(CoreWindowMoveToReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );


    args->x = x;
    args->y = y;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_MoveTo, args, sizeof(CoreWindowMoveTo), return_args, sizeof(CoreWindowMoveToReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_MoveTo ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_MoveTo failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_Resize(IWindow *thiz,
                    int                                        width,
                    int                                        height
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowResize       *args = (CoreWindowResize*) args_alloc( args_static, sizeof(CoreWindowResize) );
    CoreWindowResizeReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowResizeReturn*) args_alloc( return_args_static, sizeof(CoreWindowResizeReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );


    args->width = width;
    args->height = height;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_Resize, args, sizeof(CoreWindowResize), return_args, sizeof(CoreWindowResizeReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_Resize ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_Resize failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_Destroy(IWindow *thiz

)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowDestroy       *args = (CoreWindowDestroy*) args_alloc( args_static, sizeof(CoreWindowDestroy) );
    CoreWindowDestroyReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowDestroyReturn*) args_alloc( return_args_static, sizeof(CoreWindowDestroyReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );



    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_Destroy, args, sizeof(CoreWindowDestroy), return_args, sizeof(CoreWindowDestroyReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_Destroy ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_Destroy failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_SetCursorPosition(IWindow *thiz,
                    int                                        x,
                    int                                        y
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowSetCursorPosition       *args = (CoreWindowSetCursorPosition*) args_alloc( args_static, sizeof(CoreWindowSetCursorPosition) );
    CoreWindowSetCursorPositionReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowSetCursorPositionReturn*) args_alloc( return_args_static, sizeof(CoreWindowSetCursorPositionReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );


    args->x = x;
    args->y = y;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_SetCursorPosition, args, sizeof(CoreWindowSetCursorPosition), return_args, sizeof(CoreWindowSetCursorPositionReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_SetCursorPosition ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_SetCursorPosition failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_ChangeEvents(IWindow *thiz,
                    DFBWindowEventType                         disable,
                    DFBWindowEventType                         enable
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowChangeEvents       *args = (CoreWindowChangeEvents*) args_alloc( args_static, sizeof(CoreWindowChangeEvents) );
    CoreWindowChangeEventsReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowChangeEventsReturn*) args_alloc( return_args_static, sizeof(CoreWindowChangeEventsReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );


    args->disable = disable;
    args->enable = enable;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_ChangeEvents, args, sizeof(CoreWindowChangeEvents), return_args, sizeof(CoreWindowChangeEventsReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_ChangeEvents ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_ChangeEvents failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_ChangeOptions(IWindow *thiz,
                    DFBWindowOptions                           disable,
                    DFBWindowOptions                           enable
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowChangeOptions       *args = (CoreWindowChangeOptions*) args_alloc( args_static, sizeof(CoreWindowChangeOptions) );
    CoreWindowChangeOptionsReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowChangeOptionsReturn*) args_alloc( return_args_static, sizeof(CoreWindowChangeOptionsReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );


    args->disable = disable;
    args->enable = enable;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_ChangeOptions, args, sizeof(CoreWindowChangeOptions), return_args, sizeof(CoreWindowChangeOptionsReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_ChangeOptions ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_ChangeOptions failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_SetColor(IWindow *thiz,
                    const DFBColor                            *color
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowSetColor       *args = (CoreWindowSetColor*) args_alloc( args_static, sizeof(CoreWindowSetColor) );
    CoreWindowSetColorReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowSetColorReturn*) args_alloc( return_args_static, sizeof(CoreWindowSetColorReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );

    D_ASSERT( color != NULL );

    args->color = *color;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_SetColor, args, sizeof(CoreWindowSetColor), return_args, sizeof(CoreWindowSetColorReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_SetColor ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_SetColor failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_SetColorKey(IWindow *thiz,
                    u32                                        key
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowSetColorKey       *args = (CoreWindowSetColorKey*) args_alloc( args_static, sizeof(CoreWindowSetColorKey) );
    CoreWindowSetColorKeyReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowSetColorKeyReturn*) args_alloc( return_args_static, sizeof(CoreWindowSetColorKeyReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );


    args->key = key;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_SetColorKey, args, sizeof(CoreWindowSetColorKey), return_args, sizeof(CoreWindowSetColorKeyReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_SetColorKey ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_SetColorKey failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_SetOpaque(IWindow *thiz,
                    const DFBRegion                           *opaque
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowSetOpaque       *args = (CoreWindowSetOpaque*) args_alloc( args_static, sizeof(CoreWindowSetOpaque) );
    CoreWindowSetOpaqueReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowSetOpaqueReturn*) args_alloc( return_args_static, sizeof(CoreWindowSetOpaqueReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );

    D_ASSERT( opaque != NULL );

    args->opaque = *opaque;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_SetOpaque, args, sizeof(CoreWindowSetOpaque), return_args, sizeof(CoreWindowSetOpaqueReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_SetOpaque ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_SetOpaque failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_SetOpacity(IWindow *thiz,
                    u8                                         opacity
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowSetOpacity       *args = (CoreWindowSetOpacity*) args_alloc( args_static, sizeof(CoreWindowSetOpacity) );
    CoreWindowSetOpacityReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowSetOpacityReturn*) args_alloc( return_args_static, sizeof(CoreWindowSetOpacityReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );


    args->opacity = opacity;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_SetOpacity, args, sizeof(CoreWindowSetOpacity), return_args, sizeof(CoreWindowSetOpacityReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_SetOpacity ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_SetOpacity failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_SetStacking(IWindow *thiz,
                    DFBWindowStackingClass                     stacking
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowSetStacking       *args = (CoreWindowSetStacking*) args_alloc( args_static, sizeof(CoreWindowSetStacking) );
    CoreWindowSetStackingReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowSetStackingReturn*) args_alloc( return_args_static, sizeof(CoreWindowSetStackingReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );


    args->stacking = stacking;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_SetStacking, args, sizeof(CoreWindowSetStacking), return_args, sizeof(CoreWindowSetStackingReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_SetStacking ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_SetStacking failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_SetBounds(IWindow *thiz,
                    const DFBRectangle                        *bounds
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowSetBounds       *args = (CoreWindowSetBounds*) args_alloc( args_static, sizeof(CoreWindowSetBounds) );
    CoreWindowSetBoundsReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowSetBoundsReturn*) args_alloc( return_args_static, sizeof(CoreWindowSetBoundsReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );

    D_ASSERT( bounds != NULL );

    args->bounds = *bounds;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_SetBounds, args, sizeof(CoreWindowSetBounds), return_args, sizeof(CoreWindowSetBoundsReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_SetBounds ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_SetBounds failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_SetKeySelection(IWindow *thiz,
                    DFBWindowKeySelection                      selection,
                    const DFBInputDeviceKeySymbol             *keys,
                    u32                                        num_keys
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowSetKeySelection       *args = (CoreWindowSetKeySelection*) args_alloc( args_static, sizeof(CoreWindowSetKeySelection) + num_keys * sizeof(DFBInputDeviceKeySymbol) );
    CoreWindowSetKeySelectionReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowSetKeySelectionReturn*) args_alloc( return_args_static, sizeof(CoreWindowSetKeySelectionReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );


    args->selection = selection;
    args->num_keys = num_keys;
  if (keys) {
    direct_memcpy( (char*) (args + 1), keys, num_keys * sizeof(DFBInputDeviceKeySymbol) );
    args->keys_set = true;
  }
  else {
    args->keys_set = false;
    keys = 0;
  }

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_SetKeySelection, args, sizeof(CoreWindowSetKeySelection) + num_keys * sizeof(DFBInputDeviceKeySymbol), return_args, sizeof(CoreWindowSetKeySelectionReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_SetKeySelection ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_SetKeySelection failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_SetRotation(IWindow *thiz,
                    int                                        rotation
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowSetRotation       *args = (CoreWindowSetRotation*) args_alloc( args_static, sizeof(CoreWindowSetRotation) );
    CoreWindowSetRotationReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowSetRotationReturn*) args_alloc( return_args_static, sizeof(CoreWindowSetRotationReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );


    args->rotation = rotation;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_SetRotation, args, sizeof(CoreWindowSetRotation), return_args, sizeof(CoreWindowSetRotationReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_SetRotation ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_SetRotation failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_GetSurface(IWindow *thiz,
                    CoreSurface                              **ret_surface
)
{
    DFBResult           ret = DFB_OK;
    CoreSurface *surface = NULL;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowGetSurface       *args = (CoreWindowGetSurface*) args_alloc( args_static, sizeof(CoreWindowGetSurface) );
    CoreWindowGetSurfaceReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowGetSurfaceReturn*) args_alloc( return_args_static, sizeof(CoreWindowGetSurfaceReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );

    D_ASSERT( ret_surface != NULL );


    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_GetSurface, args, sizeof(CoreWindowGetSurface), return_args, sizeof(CoreWindowGetSurfaceReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_GetSurface ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_GetSurface failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }


    ret = (DFBResult) CoreSurface_Catch( thiz->core, return_args->surface_ptr, &surface );
    if (ret) {
         D_DERROR( ret, "%s: Catching surface by ID %u failed!\n", __FUNCTION__, return_args->surface_id );
         goto out;
    }

    *ret_surface = surface;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_SetCursorShape(IWindow *thiz,
                    CoreSurface                               *shape,
                    const DFBPoint                            *hotspot
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowSetCursorShape       *args = (CoreWindowSetCursorShape*) args_alloc( args_static, sizeof(CoreWindowSetCursorShape) );
    CoreWindowSetCursorShapeReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowSetCursorShapeReturn*) args_alloc( return_args_static, sizeof(CoreWindowSetCursorShapeReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );

    D_ASSERT( hotspot != NULL );

  if (shape) {
    args->shape_id = CoreSurface_GetID( shape );
    args->shape_set = true;
  }
  else
    args->shape_set = false;
    args->hotspot = *hotspot;

    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_SetCursorShape, args, sizeof(CoreWindowSetCursorShape), return_args, sizeof(CoreWindowSetCursorShapeReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_SetCursorShape ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_SetCursorShape failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_AllowFocus(IWindow *thiz

)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowAllowFocus       *args = (CoreWindowAllowFocus*) args_alloc( args_static, sizeof(CoreWindowAllowFocus) );
    CoreWindowAllowFocusReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowAllowFocusReturn*) args_alloc( return_args_static, sizeof(CoreWindowAllowFocusReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );



    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_AllowFocus, args, sizeof(CoreWindowAllowFocus), return_args, sizeof(CoreWindowAllowFocusReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_AllowFocus ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_AllowFocus failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IWindowRequestor_GetInsets(IWindow *thiz,
                    DFBInsets                                 *ret_insets
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreWindowGetInsets       *args = (CoreWindowGetInsets*) args_alloc( args_static, sizeof(CoreWindowGetInsets) );
    CoreWindowGetInsetsReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreWindowGetInsetsReturn*) args_alloc( return_args_static, sizeof(CoreWindowGetInsetsReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreWindow, "IWindow_Requestor::%s()\n", __FUNCTION__ );

    D_ASSERT( ret_insets != NULL );


    ret = (DFBResult) CoreWindow_Call( thiz->obj, FCEF_NONE, CoreWindowCall_GetInsets, args, sizeof(CoreWindowGetInsets), return_args, sizeof(CoreWindowGetInsetsReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreWindow_Call( CoreWindow_GetInsets ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreWindow_GetInsets failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

    *ret_insets = return_args->insets;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}

void IWindowRequestorInit(IWindowRequestor *thiz, CoreDFB *core, CoreWindow *obj)
{
	thiz->base.core = core;
	thiz->base.obj = obj;

	thiz->base.Repaint = IWindowRequestor_Repaint;
	thiz->base.BeginUpdates = IWindowRequestor_BeginUpdates;
	thiz->base.Restack = IWindowRequestor_Restack;
	thiz->base.SetConfig = IWindowRequestor_SetConfig;
	thiz->base.Bind = IWindowRequestor_Bind;
	thiz->base.Unbind = IWindowRequestor_Unbind;
	thiz->base.RequestFocus = IWindowRequestor_RequestFocus;
	thiz->base.ChangeGrab = IWindowRequestor_ChangeGrab;
	thiz->base.GrabKey = IWindowRequestor_GrabKey;
	thiz->base.UngrabKey = IWindowRequestor_UngrabKey;
	thiz->base.Move = IWindowRequestor_Move;
	thiz->base.MoveTo = IWindowRequestor_MoveTo;
	thiz->base.Resize = IWindowRequestor_Resize;
	thiz->base.Destroy = IWindowRequestor_Destroy;
	thiz->base.SetCursorPosition = IWindowRequestor_SetCursorPosition;
	thiz->base.ChangeEvents = IWindowRequestor_ChangeEvents;
	thiz->base.ChangeOptions = IWindowRequestor_ChangeOptions;
	thiz->base.SetColor = IWindowRequestor_SetColor;
	thiz->base.SetColorKey = IWindowRequestor_SetColorKey;
	thiz->base.SetOpaque = IWindowRequestor_SetOpaque;
	thiz->base.SetOpacity = IWindowRequestor_SetOpacity;
	thiz->base.SetStacking = IWindowRequestor_SetStacking;
	thiz->base.SetBounds = IWindowRequestor_SetBounds;
	thiz->base.SetKeySelection = IWindowRequestor_SetKeySelection;
	thiz->base.SetRotation = IWindowRequestor_SetRotation;
	thiz->base.GetSurface = IWindowRequestor_GetSurface;
	thiz->base.SetCursorShape = IWindowRequestor_SetCursorShape;
	thiz->base.AllowFocus = IWindowRequestor_AllowFocus;
	thiz->base.GetInsets = IWindowRequestor_GetInsets;
}

/*********************************************************************************************************************/

static DFBResult
__CoreWindowDispatch__Dispatch( CoreWindow *obj,
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


	IWindowReal real;
	IWindow *super = (IWindow *)&real;
	IWindowRealInit( &real, core_dfb, obj );

    switch (method) {
        case CoreWindowCall_Repaint: {
            D_UNUSED
            CoreWindowRepaint       *args        = (CoreWindowRepaint *) ptr;
            CoreWindowRepaintReturn *return_args = (CoreWindowRepaintReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_Repaint\n" );

            return_args->result = super->Repaint( super, &args->left, &args->right, args->flags );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowRepaintReturn);

            return DFB_OK;
        }

        case CoreWindowCall_BeginUpdates: {
            D_UNUSED
            CoreWindowBeginUpdates       *args        = (CoreWindowBeginUpdates *) ptr;
            CoreWindowBeginUpdatesReturn *return_args = (CoreWindowBeginUpdatesReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_BeginUpdates\n" );

            return_args->result = super->BeginUpdates( super, args->update_set ? &args->update : NULL );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowBeginUpdatesReturn);

            return DFB_OK;
        }

        case CoreWindowCall_Restack: {
    CoreWindow *relative = NULL;
            D_UNUSED
            CoreWindowRestack       *args        = (CoreWindowRestack *) ptr;
            CoreWindowRestackReturn *return_args = (CoreWindowRestackReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_Restack\n" );

            if (args->relative_set) {
                ret = (DFBResult) CoreWindow_Lookup( core_dfb, args->relative_id, caller, &relative );
                if (ret) {
                     D_DERROR( ret, "%s: Looking up relative by ID %u failed!\n", __FUNCTION__, args->relative_id );
                     return_args->result = ret;
                     return ret;
                }
            }

            return_args->result = super->Restack( super, args->relative_set ? relative : NULL, args->relation );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowRestackReturn);

            if (relative)
                CoreWindow_Unref( relative );

            return DFB_OK;
        }

        case CoreWindowCall_SetConfig: {
            D_UNUSED
            CoreWindowSetConfig       *args        = (CoreWindowSetConfig *) ptr;
            CoreWindowSetConfigReturn *return_args = (CoreWindowSetConfigReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_SetConfig\n" );

            return_args->result = super->SetConfig( super, &args->config, args->keys_set ? (DFBInputDeviceKeySymbol*) ((char*)(args + 1)) : NULL, args->num_keys, args->flags );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowSetConfigReturn);

            return DFB_OK;
        }

        case CoreWindowCall_Bind: {
    CoreWindow *source = NULL;
            D_UNUSED
            CoreWindowBind       *args        = (CoreWindowBind *) ptr;
            CoreWindowBindReturn *return_args = (CoreWindowBindReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_Bind\n" );

            ret = (DFBResult) CoreWindow_Lookup( core_dfb, args->source_id, caller, &source );
            if (ret) {
                 D_DERROR( ret, "%s: Looking up source by ID %u failed!\n", __FUNCTION__, args->source_id );
                 return_args->result = ret;
                 return ret;
            }

            return_args->result = super->Bind( super, source, args->x, args->y );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowBindReturn);

            if (source)
                CoreWindow_Unref( source );

            return DFB_OK;
        }

        case CoreWindowCall_Unbind: {
    CoreWindow *source = NULL;
            D_UNUSED
            CoreWindowUnbind       *args        = (CoreWindowUnbind *) ptr;
            CoreWindowUnbindReturn *return_args = (CoreWindowUnbindReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_Unbind\n" );

            ret = (DFBResult) CoreWindow_Lookup( core_dfb, args->source_id, caller, &source );
            if (ret) {
                 D_DERROR( ret, "%s: Looking up source by ID %u failed!\n", __FUNCTION__, args->source_id );
                 return_args->result = ret;
                 return ret;
            }

            return_args->result = super->Unbind( super, source );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowUnbindReturn);

            if (source)
                CoreWindow_Unref( source );

            return DFB_OK;
        }

        case CoreWindowCall_RequestFocus: {
            D_UNUSED
            CoreWindowRequestFocus       *args        = (CoreWindowRequestFocus *) ptr;
            CoreWindowRequestFocusReturn *return_args = (CoreWindowRequestFocusReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_RequestFocus\n" );

            return_args->result = super->RequestFocus( super );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowRequestFocusReturn);

            return DFB_OK;
        }

        case CoreWindowCall_ChangeGrab: {
            D_UNUSED
            CoreWindowChangeGrab       *args        = (CoreWindowChangeGrab *) ptr;
            CoreWindowChangeGrabReturn *return_args = (CoreWindowChangeGrabReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_ChangeGrab\n" );

            return_args->result = super->ChangeGrab( super, args->target, args->grab );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowChangeGrabReturn);

            return DFB_OK;
        }

        case CoreWindowCall_GrabKey: {
            D_UNUSED
            CoreWindowGrabKey       *args        = (CoreWindowGrabKey *) ptr;
            CoreWindowGrabKeyReturn *return_args = (CoreWindowGrabKeyReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_GrabKey\n" );

            return_args->result = super->GrabKey( super, args->symbol, args->modifiers );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowGrabKeyReturn);

            return DFB_OK;
        }

        case CoreWindowCall_UngrabKey: {
            D_UNUSED
            CoreWindowUngrabKey       *args        = (CoreWindowUngrabKey *) ptr;
            CoreWindowUngrabKeyReturn *return_args = (CoreWindowUngrabKeyReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_UngrabKey\n" );

            return_args->result = super->UngrabKey( super, args->symbol, args->modifiers );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowUngrabKeyReturn);

            return DFB_OK;
        }

        case CoreWindowCall_Move: {
            D_UNUSED
            CoreWindowMove       *args        = (CoreWindowMove *) ptr;
            CoreWindowMoveReturn *return_args = (CoreWindowMoveReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_Move\n" );

            return_args->result = super->Move( super, args->dx, args->dy );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowMoveReturn);

            return DFB_OK;
        }

        case CoreWindowCall_MoveTo: {
            D_UNUSED
            CoreWindowMoveTo       *args        = (CoreWindowMoveTo *) ptr;
            CoreWindowMoveToReturn *return_args = (CoreWindowMoveToReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_MoveTo\n" );

            return_args->result = super->MoveTo( super, args->x, args->y );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowMoveToReturn);

            return DFB_OK;
        }

        case CoreWindowCall_Resize: {
            D_UNUSED
            CoreWindowResize       *args        = (CoreWindowResize *) ptr;
            CoreWindowResizeReturn *return_args = (CoreWindowResizeReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_Resize\n" );

            return_args->result = super->Resize( super, args->width, args->height );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowResizeReturn);

            return DFB_OK;
        }

        case CoreWindowCall_Destroy: {
            D_UNUSED
            CoreWindowDestroy       *args        = (CoreWindowDestroy *) ptr;
            CoreWindowDestroyReturn *return_args = (CoreWindowDestroyReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_Destroy\n" );

            return_args->result = super->Destroy( super );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowDestroyReturn);

            return DFB_OK;
        }

        case CoreWindowCall_SetCursorPosition: {
            D_UNUSED
            CoreWindowSetCursorPosition       *args        = (CoreWindowSetCursorPosition *) ptr;
            CoreWindowSetCursorPositionReturn *return_args = (CoreWindowSetCursorPositionReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_SetCursorPosition\n" );

            return_args->result = super->SetCursorPosition( super, args->x, args->y );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowSetCursorPositionReturn);

            return DFB_OK;
        }

        case CoreWindowCall_ChangeEvents: {
            D_UNUSED
            CoreWindowChangeEvents       *args        = (CoreWindowChangeEvents *) ptr;
            CoreWindowChangeEventsReturn *return_args = (CoreWindowChangeEventsReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_ChangeEvents\n" );

            return_args->result = super->ChangeEvents( super, args->disable, args->enable );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowChangeEventsReturn);

            return DFB_OK;
        }

        case CoreWindowCall_ChangeOptions: {
            D_UNUSED
            CoreWindowChangeOptions       *args        = (CoreWindowChangeOptions *) ptr;
            CoreWindowChangeOptionsReturn *return_args = (CoreWindowChangeOptionsReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_ChangeOptions\n" );

            return_args->result = super->ChangeOptions( super, args->disable, args->enable );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowChangeOptionsReturn);

            return DFB_OK;
        }

        case CoreWindowCall_SetColor: {
            D_UNUSED
            CoreWindowSetColor       *args        = (CoreWindowSetColor *) ptr;
            CoreWindowSetColorReturn *return_args = (CoreWindowSetColorReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_SetColor\n" );

            return_args->result = super->SetColor( super, &args->color );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowSetColorReturn);

            return DFB_OK;
        }

        case CoreWindowCall_SetColorKey: {
            D_UNUSED
            CoreWindowSetColorKey       *args        = (CoreWindowSetColorKey *) ptr;
            CoreWindowSetColorKeyReturn *return_args = (CoreWindowSetColorKeyReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_SetColorKey\n" );

            return_args->result = super->SetColorKey( super, args->key );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowSetColorKeyReturn);

            return DFB_OK;
        }

        case CoreWindowCall_SetOpaque: {
            D_UNUSED
            CoreWindowSetOpaque       *args        = (CoreWindowSetOpaque *) ptr;
            CoreWindowSetOpaqueReturn *return_args = (CoreWindowSetOpaqueReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_SetOpaque\n" );

            return_args->result = super->SetOpaque( super, &args->opaque );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowSetOpaqueReturn);

            return DFB_OK;
        }

        case CoreWindowCall_SetOpacity: {
            D_UNUSED
            CoreWindowSetOpacity       *args        = (CoreWindowSetOpacity *) ptr;
            CoreWindowSetOpacityReturn *return_args = (CoreWindowSetOpacityReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_SetOpacity\n" );

            return_args->result = super->SetOpacity( super, args->opacity );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowSetOpacityReturn);

            return DFB_OK;
        }

        case CoreWindowCall_SetStacking: {
            D_UNUSED
            CoreWindowSetStacking       *args        = (CoreWindowSetStacking *) ptr;
            CoreWindowSetStackingReturn *return_args = (CoreWindowSetStackingReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_SetStacking\n" );

            return_args->result = super->SetStacking( super, args->stacking );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowSetStackingReturn);

            return DFB_OK;
        }

        case CoreWindowCall_SetBounds: {
            D_UNUSED
            CoreWindowSetBounds       *args        = (CoreWindowSetBounds *) ptr;
            CoreWindowSetBoundsReturn *return_args = (CoreWindowSetBoundsReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_SetBounds\n" );

            return_args->result = super->SetBounds( super, &args->bounds );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowSetBoundsReturn);

            return DFB_OK;
        }

        case CoreWindowCall_SetKeySelection: {
            D_UNUSED
            CoreWindowSetKeySelection       *args        = (CoreWindowSetKeySelection *) ptr;
            CoreWindowSetKeySelectionReturn *return_args = (CoreWindowSetKeySelectionReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_SetKeySelection\n" );

            return_args->result = super->SetKeySelection( super, args->selection, args->keys_set ? (DFBInputDeviceKeySymbol*) ((char*)(args + 1)) : NULL, args->num_keys );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowSetKeySelectionReturn);

            return DFB_OK;
        }

        case CoreWindowCall_SetRotation: {
            D_UNUSED
            CoreWindowSetRotation       *args        = (CoreWindowSetRotation *) ptr;
            CoreWindowSetRotationReturn *return_args = (CoreWindowSetRotationReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_SetRotation\n" );

            return_args->result = super->SetRotation( super, args->rotation );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowSetRotationReturn);

            return DFB_OK;
        }

        case CoreWindowCall_GetSurface: {
    		CoreSurface *surface = NULL;
            D_UNUSED
            CoreWindowGetSurface       *args        = (CoreWindowGetSurface *) ptr;
            CoreWindowGetSurfaceReturn *return_args = (CoreWindowGetSurfaceReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_GetSurface\n" );

            return_args->result = super->GetSurface( super, &surface );
            if (return_args->result == DFB_OK) {
                CoreSurface_Throw( surface, caller, &return_args->surface_id );
                return_args->surface_ptr = (void*) surface;
            }

            *ret_length = sizeof(CoreWindowGetSurfaceReturn);

            return DFB_OK;
        }

        case CoreWindowCall_SetCursorShape: {
    		CoreSurface *shape = NULL;
            D_UNUSED
            CoreWindowSetCursorShape       *args        = (CoreWindowSetCursorShape *) ptr;
            CoreWindowSetCursorShapeReturn *return_args = (CoreWindowSetCursorShapeReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_SetCursorShape\n" );

            if (args->shape_set) {
                ret = (DFBResult) CoreSurface_Lookup( core_dfb, args->shape_id, caller, &shape );
                if (ret) {
                     D_DERROR( ret, "%s: Looking up shape by ID %u failed!\n", __FUNCTION__, args->shape_id );
                     return_args->result = ret;
                     return ret;
                }
            }

            return_args->result = super->SetCursorShape( super, args->shape_set ? shape : NULL, &args->hotspot );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowSetCursorShapeReturn);

            if (shape)
                CoreSurface_Unref( shape );

            return DFB_OK;
        }

        case CoreWindowCall_AllowFocus: {
            D_UNUSED
            CoreWindowAllowFocus       *args        = (CoreWindowAllowFocus *) ptr;
            CoreWindowAllowFocusReturn *return_args = (CoreWindowAllowFocusReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_AllowFocus\n" );

            return_args->result = super->AllowFocus( super );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowAllowFocusReturn);

            return DFB_OK;
        }

        case CoreWindowCall_GetInsets: {
            D_UNUSED
            CoreWindowGetInsets       *args        = (CoreWindowGetInsets *) ptr;
            CoreWindowGetInsetsReturn *return_args = (CoreWindowGetInsetsReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreWindow, "=-> CoreWindow_GetInsets\n" );

            return_args->result = super->GetInsets( super, &return_args->insets );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreWindowGetInsetsReturn);

            return DFB_OK;
        }

    }

    return DFB_NOSUCHMETHOD;
}
/*********************************************************************************************************************/

DFBResult
CoreWindowDispatch__Dispatch( CoreWindow *obj,
                                FusionID      caller,
                                int           method,
                                void         *ptr,
                                unsigned int  length,
                                void         *ret_ptr,
                                unsigned int  ret_size,
                                unsigned int *ret_length )
{
    DFBResult ret = DFB_OK;

    D_DEBUG_AT( DirectFB_CoreWindow, "CoreWindowDispatch::%s( %p )\n", __FUNCTION__, obj );

    Core_PushIdentity( caller );

    ret = __CoreWindowDispatch__Dispatch( obj, caller, method, ptr, length, ret_ptr, ret_size, ret_length );

    Core_PopIdentity();

    return ret;
}

