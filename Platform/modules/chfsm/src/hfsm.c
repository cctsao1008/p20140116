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

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "hfsm.h"


bool
dummy_func(void *f)
{
    return true;
}



DISPATCH_ENTRY*
try_handle(FSM_T *fsm)
{
    DISPATCH_ENTRY  **tbl;
    DISPATCH_ENTRY  *e;
    fsm->work_state = fsm->current_state;

    //  recursively find the dispatch entry
    while ( fsm->work_state )
    {
        // search for real action
        tbl = (DISPATCH_ENTRY**)fsm->work_state->dispatch_tbl;
        if ( tbl ) 
        {
            e = *tbl;
            while ( e )
            {
                if ( e->guard_func(fsm) )
                {
                    return e;//fsm->dispatch;
                }
                // advance to next guard/action
                ++tbl;
                e = *tbl;
            }
        }
        fsm->work_state = fsm->work_state->parent_state;
    }

    return NULL;
}

void
hfsm_entry(FSM_T *fsm, STATE_T *state)
{
    fsm->work_state = state;

    // enter action (recursively)
    do {
        if ( fsm->work_state->entry_func )
        {
            fsm->work_state->entry_func(fsm);
        }
        fsm->current_state  = fsm->work_state;
        DEBUG("IN %s\n", fsm->current_state->name);
        fsm->work_state     = fsm->work_state->child_state;
    } while ( fsm->work_state );

    return;
}


bool
state_dispatch(FSM_T *fsm, void *msg)
{
    DISPATCH_ENTRY  *dispatch;

    //  fsm->work_state could be NULL 
    if ( !fsm->current_state )
    {
        return false;
    }

    fsm->msg        = msg;
    dispatch   = try_handle(fsm);

    if ( dispatch )
    {
        // recursively call exit
        if ( dispatch->next_state )
        {
            // work_state will be dispatch state
            while ( fsm->current_state != fsm->work_state )
            {
                DEBUG("EXIT %s\n", fsm->current_state->name);
                if ( fsm->current_state->exit_func )
                {
                    fsm->current_state->exit_func(fsm);
                }
                fsm->current_state = fsm->current_state->parent_state;
                DEBUG("IN %s\n", fsm->current_state->name);
            }
            if ( dispatch->next_state->parent_state != fsm->work_state )
                if ( fsm->current_state->exit_func )
                {
                    fsm->current_state->exit_func(fsm);
                }
        }

        if ( dispatch->action_func )
        {
            dispatch->action_func(fsm);
        }

        // transition
        if ( dispatch->next_state )
        {
            hfsm_entry(fsm, dispatch->next_state);
        }
        return true;
    }
    else
    {
        // can not dispatch
        return false;
    }
}

void
hfsm_init(FSM_T *fsm)
{
    int i;

#if FSM_TRACE
    fsm->state_trace_index          = 0;
    fsm->state_handler_trace_index  = 0;

    for ( i = 0; i < FSM_TRACE; ++i )
    {
        fsm->state_trace[i] = NULL;  
    }
#endif
}
