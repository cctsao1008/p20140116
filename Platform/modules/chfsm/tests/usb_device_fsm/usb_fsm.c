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
#include "hfsm.h"
#include "usb_fsm.h"


STATE_T powered;
STATE_T address;
STATE_T Default;
STATE_T ready_state;
STATE_T configured;


DISPATCH_ENTRY powered_entry[] = {
    {   
        .guard_func = guard_reset,
        .action_func = dummy_func,
        .next_state = &ready_state
    }
};

DISPATCH_ENTRY address_entry[] = {
    {   
        .guard_func = guard_device_configured,
        .action_func = dummy_func,
        .next_state = &configured
    }
};


DISPATCH_ENTRY Default_entry[] = {
    {   
        .guard_func = guard_address_assign,
        .action_func = dummy_func,
        .next_state = &address
    }
};


DISPATCH_ENTRY ready_state_entry[] = {
    {   
        .guard_func = guard_reset,
        .action_func = dummy_func,
        .next_state = &ready_state
    }
};

DISPATCH_ENTRY configured_entry[] = {
    {   
        .guard_func = guard_device_deconfigured,
        .action_func = dummy_func,
        .next_state = &address
    }
};



DISPATCH_ENTRY *powered_tbl[] = {
    &powered_entry[0], 
    NULL};

DISPATCH_ENTRY *address_tbl[] = {
    &address_entry[0], 
    NULL};

DISPATCH_ENTRY *Default_tbl[] = {
    &Default_entry[0], 
    NULL};

DISPATCH_ENTRY *ready_state_tbl[] = {
    &ready_state_entry[0], 
    NULL};

DISPATCH_ENTRY *configured_tbl[] = {
    &configured_entry[0], 
    NULL};



STATE_T powered = {
    .entry_func = NULL,
    .exit_func  = NULL,
    .dispatch_tbl = powered_tbl,
    .parent_state = NULL,
    .child_state = NULL,
    FSM_NAME("powered")
};

STATE_T address = {
    .entry_func = hw_set_address,
    .exit_func  = NULL,
    .dispatch_tbl = address_tbl,
    .parent_state = &ready_state,
    .child_state = NULL,
    FSM_NAME("address")
};

STATE_T Default = {
    .entry_func = NULL,
    .exit_func  = NULL,
    .dispatch_tbl = Default_tbl,
    .parent_state = &ready_state,
    .child_state = NULL,
    FSM_NAME("Default")
};

STATE_T ready_state = {
    .entry_func = NULL,
    .exit_func  = NULL,
    .dispatch_tbl = ready_state_tbl,
    .parent_state = NULL,
    .child_state = &Default,
    FSM_NAME("ready_state")
};

STATE_T configured = {
    .entry_func = NULL,
    .exit_func  = NULL,
    .dispatch_tbl = configured_tbl,
    .parent_state = &ready_state,
    .child_state = NULL,
    FSM_NAME("configured")
};


