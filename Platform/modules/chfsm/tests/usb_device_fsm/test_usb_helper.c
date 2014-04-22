/* 
 * Copyright (c) 2014 Faraday Technology
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "usb_fsm.h"
#include "test_usb.h"

#define DEBUG_TRACE()   printf("%s\n", __func__);

//  guard functions

/* powered */
bool guard_reset(void *fsm)
{
    FSM_T   *_f = (FSM_T*)fsm;
    MSG_T   *_m = (MSG_T*)_f->msg;

    DEBUG_TRACE();
        
    if ( EVT_RESET == _m->event )
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* address */
bool guard_device_configured(void *fsm)
{
    FSM_T   *_f = (FSM_T*)fsm;
    MSG_T   *_m = (MSG_T*)_f->msg;
    
    DEBUG_TRACE();

    if ( EVT_DEVICE_CONFIG == _m->event )
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Default */
bool guard_address_assign(void *fsm)
{
    FSM_T   *_f = (FSM_T*)fsm;
    MSG_T   *_m = (MSG_T*)_f->msg;

    DEBUG_TRACE();

    if ( EVT_ADDR_ASSIGN == _m->event )
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* ready_state */

/* configured */
bool guard_device_deconfigured(void *fsm)
{
    FSM_T   *_f = (FSM_T*)fsm;
    MSG_T   *_m = (MSG_T*)_f->msg;

    DEBUG_TRACE();

    if ( EVT_DEVICE_DECONFIG == _m->event )
    {
        return true;
    }
    else
    {
        return false;
    }
}


// entry, exit functions

/* powered */

/* address */
bool hw_set_address(void *fsm)
{
    DEBUG_TRACE();
    return true;
}

/* Default */

/* ready_state */

/* configured */
