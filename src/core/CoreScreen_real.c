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

#include "CoreScreen.h"

#include <directfb_util.h>

#include <direct/debug.h>
#include <direct/mem.h>
#include <direct/memcpy.h>
#include <direct/messages.h>

#include <core/screen.h>

D_DEBUG_DOMAIN( DirectFB_CoreScreen, "DirectFB/CoreScreen", "DirectFB CoreScreen" );

/*********************************************************************************************************************/

DFBResult
IScreenReal_SetPowerMode(IScreen *thiz,
                    DFBScreenPowerMode                         mode
)
{
    D_DEBUG_AT( DirectFB_CoreScreen, "IScreen_Real::%s()\n", __FUNCTION__ );

    return dfb_screen_set_powermode( thiz->obj, mode );
}


DFBResult
IScreenReal_WaitVSync(IScreen *thiz

)
{
    D_DEBUG_AT( DirectFB_CoreScreen, "IScreen_Real::%s()\n", __FUNCTION__ );

    return dfb_screen_wait_vsync( thiz->obj );
}

DFBResult
IScreenReal_WaitFence(IScreen *thiz

)
{
    D_DEBUG_AT( DirectFB_CoreScreen, "IScreen_Real::%s()\n", __FUNCTION__ );

    return dfb_screen_wait_fence( thiz->obj );
}


DFBResult
IScreenReal_GetVSyncCount(IScreen *thiz,
                    u64                                       *ret_count
)
{
    DFBResult     ret;
    unsigned long count;

    D_DEBUG_AT( DirectFB_CoreScreen, "IScreen_Real::%s()\n", __FUNCTION__ );

    ret = dfb_screen_get_vsync_count( thiz->obj, &count );
    if (ret)
        return ret;

    *ret_count = count;

    return DFB_OK;
}


DFBResult
IScreenReal_TestMixerConfig(IScreen *thiz,
                    u32                                        mixer,
                    const DFBScreenMixerConfig                *config,
                    DFBScreenMixerConfigFlags                 *ret_failed
)
{
    D_DEBUG_AT( DirectFB_CoreScreen, "IScreen_Real::%s()\n", __FUNCTION__ );

    D_ASSERT( config != NULL );

    return dfb_screen_test_mixer_config( thiz->obj, mixer, config, ret_failed );
}


DFBResult
IScreenReal_SetMixerConfig(IScreen *thiz,
                    u32                                        mixer,
                    const DFBScreenMixerConfig                *config
)
{
    D_DEBUG_AT( DirectFB_CoreScreen, "IScreen_Real::%s()\n", __FUNCTION__ );

    D_ASSERT( config != NULL );

    return dfb_screen_set_mixer_config( thiz->obj, mixer, config );
}


DFBResult
IScreenReal_TestEncoderConfig(IScreen *thiz,
                    u32                                        encoder,
                    const DFBScreenEncoderConfig              *config,
                    DFBScreenEncoderConfigFlags               *ret_failed
)
{
    D_DEBUG_AT( DirectFB_CoreScreen, "IScreen_Real::%s()\n", __FUNCTION__ );

    D_ASSERT( config != NULL );

    return dfb_screen_test_encoder_config( thiz->obj, encoder, config, ret_failed );
}


DFBResult
IScreenReal_SetEncoderConfig(IScreen *thiz,
                    u32                                        encoder,
                    const DFBScreenEncoderConfig              *config
)
{
    D_DEBUG_AT( DirectFB_CoreScreen, "IScreen_Real::%s()\n", __FUNCTION__ );

    D_ASSERT( config != NULL );

    return dfb_screen_set_encoder_config( thiz->obj, encoder, config );
}


DFBResult
IScreenReal_TestOutputConfig(IScreen *thiz,
                    u32                                        output,
                    const DFBScreenOutputConfig               *config,
                    DFBScreenOutputConfigFlags                *ret_failed
)
{
    D_DEBUG_AT( DirectFB_CoreScreen, "IScreen_Real::%s()\n", __FUNCTION__ );

    D_ASSERT( config != NULL );

    return dfb_screen_test_output_config( thiz->obj, output, config, ret_failed );
}


DFBResult
IScreenReal_SetOutputConfig(IScreen *thiz,
                    u32                                        output,
                    const DFBScreenOutputConfig               *config
)
{
    D_DEBUG_AT( DirectFB_CoreScreen, "IScreen_Real::%s()\n", __FUNCTION__ );

    D_ASSERT( config != NULL );

    return dfb_screen_set_output_config( thiz->obj, output, config );
}


DFBResult
IScreenReal_GetScreenSize(IScreen *thiz,
                    DFBDimension                              *ret_size
)
{
    D_DEBUG_AT( DirectFB_CoreScreen, "IScreen_Real::%s()\n", __FUNCTION__ );

    D_ASSERT( ret_size != NULL );

    return dfb_screen_get_screen_size( thiz->obj, &ret_size->w, &ret_size->h );
}


DFBResult
IScreenReal_GetLayerDimension(IScreen *thiz,
                    CoreLayer                                 *layer,
                    DFBDimension                              *ret_size
)
{
    D_DEBUG_AT( DirectFB_CoreScreen, "IScreen_Real::%s()\n", __FUNCTION__ );

    D_ASSERT( layer != NULL );
    D_ASSERT( ret_size != NULL );

    return dfb_screen_get_layer_dimension( thiz->obj, layer, &ret_size->w, &ret_size->h );
}

void IScreenRealInit(IScreenReal *thiz, CoreDFB *core, CoreScreen *obj)
{
    thiz->base.core = core;
    thiz->base.obj = obj;

    thiz->base.SetPowerMode = IScreenReal_SetPowerMode;
    thiz->base.WaitVSync = IScreenReal_WaitVSync;
    thiz->base.WaitFence = IScreenReal_WaitFence;
    thiz->base.GetVSyncCount = IScreenReal_GetVSyncCount;
    thiz->base.TestMixerConfig = IScreenReal_TestMixerConfig;
    thiz->base.SetMixerConfig = IScreenReal_SetMixerConfig;
    thiz->base.TestEncoderConfig = IScreenReal_TestEncoderConfig;
    thiz->base.SetEncoderConfig = IScreenReal_SetEncoderConfig;
    thiz->base.TestOutputConfig = IScreenReal_TestOutputConfig;
    thiz->base.SetOutputConfig = IScreenReal_SetOutputConfig;
    thiz->base.GetScreenSize = IScreenReal_GetScreenSize;
    thiz->base.GetLayerDimension = IScreenReal_GetLayerDimension;
}

