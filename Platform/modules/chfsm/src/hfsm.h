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
#ifndef _HFSM_H_
#define _HFSM_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define FSM_TRACE   8
#define DEBUGMSG    1

#if DEBUGMSG         

#define FSM_NAME(NAME)  .name       = NAME 
#define DEBUG(format, ...)   printf(format, ## __VA_ARGS__)
#else
#define FSM_NAME(NAME)
#define DEBUG(format, ...)
#endif

#if FSM_TRACE
#define TRACE() {fsm->state_trace[++fsm->state_trace_index] = fsm->current_state;fsm->state_trace_index &= (FSM_TRACE-1);}
#else
#define TRACE()
#endif
typedef bool (*FSMFunc)(void* fsm);

typedef struct {
     FSMFunc         entry_func;
     FSMFunc         exit_func;
    void            *parent_state;
    void            *child_state;
    void            *dispatch_tbl;
#if DEBUGMSG
     char            *name;
#endif
} STATE_T;


typedef struct dispatch{
     FSMFunc     guard_func;
     FSMFunc     action_func;
    /** NULL if no transition, or to self-state if self-transition */
     STATE_T     *next_state;
} DISPATCH_ENTRY;


typedef struct {
    STATE_T *current_state;
    // local vars
    STATE_T *work_state;
    void    *msg;

    DISPATCH_ENTRY  *dispatch;

#if FSM_TRACE
    // transition trace
    STATE_T *state_trace[FSM_TRACE];
    int     state_trace_index;

    // handler trace
    STATE_T *state_handler_trace[FSM_TRACE];
    int     state_handler_trace_index;    
#endif
    void    *user;
} FSM_T;

bool
state_dispatch(FSM_T *fsm, void *msg);

bool
dummy_func(void*);

void
hfsm_entry(FSM_T *fsm, STATE_T *state);
#endif
