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

#ifndef ___SaWManManager__H___
#define ___SaWManManager__H___

#include "SaWManManager_includes.h"

/**********************************************************************************************************************
 * SaWManManager
 */

DFBResult SaWManManager_Activate(
                    SaWManManager                             *obj
);

DFBResult SaWManManager_QueueUpdate(
                    SaWManManager                             *obj,
                    DFBWindowStackingClass                     stacking,
                    const DFBRegion                           *update);

DFBResult SaWManManager_ProcessUpdates(
                    SaWManManager                             *obj,
                    DFBSurfaceFlipFlags                        flags);

DFBResult SaWManManager_CloseWindow(
                    SaWManManager                             *obj,
                    SaWManWindow                              *window);

DFBResult SaWManManager_InsertWindow(
                    SaWManManager                             *obj,
                    SaWManWindow                              *window,
                    SaWManWindow                              *relative,
                    SaWManWindowRelation                       relation);

DFBResult SaWManManager_RemoveWindow(
                    SaWManManager                             *obj,
                    SaWManWindow                              *window);

DFBResult SaWManManager_SwitchFocus(
                    SaWManManager                             *obj,
                    SaWManWindow                              *window);

DFBResult SaWManManager_SetScalingMode(
                    SaWManManager                             *obj,
                    SaWManScalingMode                          mode);

DFBResult SaWManManager_SetWindowConfig(
                    SaWManManager                             *obj,
                    SaWManWindow                              *window,
                    const SaWManWindowConfig                  *config,
                    SaWManWindowConfigFlags                    flags);

DFBResult SaWManManager_IsShowingWindow(
                    SaWManManager                             *obj,
                    SaWManWindow                              *window,
                    DFBBoolean                                *ret_showing);


void SaWManManager_Init_Dispatch(
                    CoreDFB              *core,
                    SaWManManager        *obj,
                    FusionCall           *call
);

void  SaWManManager_Deinit_Dispatch(
                    FusionCall           *call
);

/*
 * SaWManManager Calls
 */
typedef enum {
    SaWManManagerCall_Activate = 1,
    SaWManManagerCall_QueueUpdate = 2,
    SaWManManagerCall_ProcessUpdates = 3,
    SaWManManagerCall_CloseWindow = 4,
    SaWManManagerCall_InsertWindow = 5,
    SaWManManagerCall_RemoveWindow = 6,
    SaWManManagerCall_SwitchFocus = 7,
    SaWManManagerCall_SetScalingMode = 8,
    SaWManManagerCall_SetWindowConfig = 9,
    SaWManManagerCall_IsShowingWindow = 10,
} SaWManManagerCall;

/*
 * SaWManManager_Activate
 */
typedef struct {
} SaWManManagerActivate;

typedef struct {
    DFBResult                                  result;
} SaWManManagerActivateReturn;


/*
 * SaWManManager_QueueUpdate
 */
typedef struct {
    DFBWindowStackingClass                     stacking;
    bool                                       update_set;
    DFBRegion                                  update;
} SaWManManagerQueueUpdate;

typedef struct {
    DFBResult                                  result;
} SaWManManagerQueueUpdateReturn;


/*
 * SaWManManager_ProcessUpdates
 */
typedef struct {
    DFBSurfaceFlipFlags                        flags;
} SaWManManagerProcessUpdates;

typedef struct {
    DFBResult                                  result;
} SaWManManagerProcessUpdatesReturn;


/*
 * SaWManManager_CloseWindow
 */
typedef struct {
    u32                                        window_id;
} SaWManManagerCloseWindow;

typedef struct {
    DFBResult                                  result;
} SaWManManagerCloseWindowReturn;


/*
 * SaWManManager_InsertWindow
 */
typedef struct {
    u32                                        window_id;
    bool                                       relative_set;
    u32                                        relative_id;
    SaWManWindowRelation                       relation;
} SaWManManagerInsertWindow;

typedef struct {
    DFBResult                                  result;
} SaWManManagerInsertWindowReturn;


/*
 * SaWManManager_RemoveWindow
 */
typedef struct {
    u32                                        window_id;
} SaWManManagerRemoveWindow;

typedef struct {
    DFBResult                                  result;
} SaWManManagerRemoveWindowReturn;


/*
 * SaWManManager_SwitchFocus
 */
typedef struct {
    u32                                        window_id;
} SaWManManagerSwitchFocus;

typedef struct {
    DFBResult                                  result;
} SaWManManagerSwitchFocusReturn;


/*
 * SaWManManager_SetScalingMode
 */
typedef struct {
    SaWManScalingMode                          mode;
} SaWManManagerSetScalingMode;

typedef struct {
    DFBResult                                  result;
} SaWManManagerSetScalingModeReturn;


/*
 * SaWManManager_SetWindowConfig
 */
typedef struct {
    u32                                        window_id;
    SaWManWindowConfig                         config;
    SaWManWindowConfigFlags                    flags;
} SaWManManagerSetWindowConfig;

typedef struct {
    DFBResult                                  result;
} SaWManManagerSetWindowConfigReturn;


/*
 * SaWManManager_IsShowingWindow
 */
typedef struct {
    u32                                        window_id;
} SaWManManagerIsShowingWindow;

typedef struct {
    DFBResult                                  result;
    DFBBoolean                                 showing;
} SaWManManagerIsShowingWindowReturn;


typedef struct _ISaWManManagerX ISaWManManagerX;
typedef struct _ISaWManManagerXReal ISaWManManagerXReal;
typedef struct _ISaWManManagerXRequestor ISaWManManagerXRequestor;

struct _ISaWManManagerX
{
    SaWManManager *obj;
	CoreDFB *core;

    DFBResult (*Activate)(ISaWManManagerX* thiz

    );

    DFBResult (*QueueUpdate)(ISaWManManagerX* thiz,
                    DFBWindowStackingClass                     stacking,
                    const DFBRegion                           *update
    );

    DFBResult (*ProcessUpdates)(ISaWManManagerX* thiz,
                    DFBSurfaceFlipFlags                        flags
    );

    DFBResult (*CloseWindow)(ISaWManManagerX* thiz,
                    SaWManWindow                              *window
    );

    DFBResult (*InsertWindow)(ISaWManManagerX* thiz,
                    SaWManWindow                              *window,
                    SaWManWindow                              *relative,
                    SaWManWindowRelation                       relation
    );

    DFBResult (*RemoveWindow)(ISaWManManagerX* thiz,
                    SaWManWindow                              *window
    );

    DFBResult (*SwitchFocus)(ISaWManManagerX* thiz,
                    SaWManWindow                              *window
    );

    DFBResult (*SetScalingMode)(ISaWManManagerX* thiz,
                    SaWManScalingMode                          mode
    );

    DFBResult (*SetWindowConfig)(ISaWManManagerX* thiz,
                    SaWManWindow                              *window,
                    const SaWManWindowConfig                  *config,
                    SaWManWindowConfigFlags                    flags
    );

    DFBResult (*IsShowingWindow)(ISaWManManagerX* thiz,
                    SaWManWindow                              *window,
                    DFBBoolean                                *ret_showing
    );

};

struct _ISaWManManagerXReal
{
	ISaWManManagerX base;
};

void ISaWManManagerRealInit(ISaWManManagerXReal *thiz, CoreDFB *core, SaWManManager *obj);


struct _ISaWManManagerXRequestor
{
	ISaWManManagerX base;
};


void ISaWManManagerRequestorInit(ISaWManManagerXRequestor *thiz, CoreDFB *core, SaWManManager *obj);


DFBResult SaWManManagerDispatch__Dispatch( SaWManManager *obj,
                    FusionID      caller,
                    int           method,
                    void         *ptr,
                    unsigned int  length,
                    void         *ret_ptr,
                    unsigned int  ret_size,
                    unsigned int *ret_length );


#endif
