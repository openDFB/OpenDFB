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

#ifndef ___SaWManProcess__H___
#define ___SaWManProcess__H___

#include "SaWManProcess_includes.h"

/**********************************************************************************************************************
 * SaWManProcess
 */

DFBResult SaWManProcess_SetExiting(
                    SaWManProcess                             *obj
);

DFBResult SaWManProcess_RegisterManager(
                    SaWManProcess                             *obj,
                    const SaWManRegisterManagerData           *data,
                    SaWManManager                            **ret_manager);


void SaWManProcess_Init_Dispatch(
                    CoreDFB              *core,
                    SaWManProcess        *obj,
                    FusionCall           *call
);

void  SaWManProcess_Deinit_Dispatch(
                    FusionCall           *call
);


/*
 * SaWManProcess Calls
 */
typedef enum {
    SaWManProcessCall_SetExiting = 1,
    SaWManProcessCall_RegisterManager = 2,
} SaWManProcessCall;

/*
 * SaWManProcess_SetExiting
 */
typedef struct {
} SaWManProcessSetExiting;

typedef struct {
    DFBResult                                  result;
} SaWManProcessSetExitingReturn;


/*
 * SaWManProcess_RegisterManager
 */
typedef struct {
    SaWManRegisterManagerData                  data;
} SaWManProcessRegisterManager;

typedef struct {
    DFBResult                                  result;
    u32                                        manager_id;
} SaWManProcessRegisterManagerReturn;


typedef struct _ISaWManProcess ISaWManProcess;
typedef struct _ISaWManProcessReal ISaWManProcessReal;
typedef struct _ISaWManProcessRequestor ISaWManProcessRequestor;

struct _ISaWManProcess
{
    SaWManProcess *obj;
	CoreDFB *core;

    DFBResult (*SetExiting)(ISaWManProcess *thiz

    );

    DFBResult (*RegisterManager)(ISaWManProcess *thiz,
                    const SaWManRegisterManagerData           *data,
                    SaWManManager                            **ret_manager
    );
};

struct _ISaWManProcessReal
{
	ISaWManProcess base;
};


void ISaWManProcessRealInit(ISaWManProcessReal *thiz, CoreDFB *core, SaWManProcess *obj);

struct _ISaWManProcessRequestor
{
	ISaWManProcess base;
};

void ISaWManProcessRequestorInit(ISaWManProcessRequestor *thiz, CoreDFB *core, SaWManProcess *obj);


DFBResult SaWManProcessDispatch__Dispatch( SaWManProcess *obj,
                    FusionID      caller,
                    int           method,
                    void         *ptr,
                    unsigned int  length,
                    void         *ret_ptr,
                    unsigned int  ret_size,
                    unsigned int *ret_length );


#endif
