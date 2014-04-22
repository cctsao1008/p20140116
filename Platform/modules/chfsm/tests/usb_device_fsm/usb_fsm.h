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

//  guard functions

/* powered */
bool guard_reset(void *fsm);

/* address */
bool guard_device_configured(void *fsm);


/* Default */
bool guard_address_assign(void *fsm);


/* ready_state */
bool guard_reset(void *fsm);

/* configured */
bool guard_device_deconfigured(void *fsm);


// entry, exit functions

/* powered */

/* address */
bool hw_set_address(void *fsm);

/* Default */

/* ready_state */

/* configured */

