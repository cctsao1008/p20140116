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

MSG_T   msgs_a[] = {{EVT_RESET}, {EVT_ADDR_ASSIGN}, {EVT_DEVICE_CONFIG}, {EVT_DEVICE_DECONFIG}};
MSG_T   msgs_b[] = {{EVT_RESET}, {EVT_DEVICE_CONFIG}, {EVT_ADDR_ASSIGN}, {EVT_RESET}};
MSG_T   msgs_c[] = {{EVT_ADDR_ASSIGN}, {EVT_DEVICE_CONFIG}, {EVT_DEVICE_DECONFIG}, {EVT_RESET}};



extern STATE_T powered;

int main (int argc, char **argv)
{
    FSM_T   f;

    FSM_T   *pf = &f;
    int     loop;
    
    hfsm_entry(pf, &powered);

    for ( loop = 0; loop < 4; ++loop )
    {
        printf("----msg %d is %d\n", loop, msgs_a[loop].event);
        state_dispatch(pf, &msgs_a[loop]);
    }

    printf("done stage a\n\n");

    hfsm_entry(pf, &powered);

    for ( loop = 0; loop < 4; ++loop )
    {
        printf("----msg %d is %d\n", loop, msgs_b[loop].event);
        state_dispatch(pf, &msgs_b[loop]);
    }

    printf("done stage b\n\n");


    hfsm_entry(pf, &powered);

    for ( loop = 0; loop < 4; ++loop )
    {
        printf("----msg %d is %d\n", loop, msgs_c[loop].event);
        state_dispatch(pf, &msgs_c[loop]);
    }

    printf("done stage c\n\n");

    return 0;
}
