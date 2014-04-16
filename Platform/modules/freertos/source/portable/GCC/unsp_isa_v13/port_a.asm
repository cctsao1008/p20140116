// ****************************************************************************
// * Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\port_a.asm
// *
// *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
// *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
// *
// *   GENERAL DESCRIPTION
// *
// *
// ****************************************************************************
.INCLUDE    GPCE206x.inc

.PUBLIC     _uxPortReadFlagRegister
.PUBLIC     _vPortWriteFlagRegister
.PUBLIC     _portSAVE_CONTEXT
.PUBLIC     _portRESTORE_CONTEXT

.EXTERNAL   _pxCurrentTCB
.EXTERNAL   _vTaskSwitchContext
.EXTERNAL   _vTaskIncrementTick

// Macro Definition
PUSH_ALL: .MACRO

    PUSH R1,R5 TO [SP]

.ENDM

POP_ALL: .MACRO

    POP R1,R5 FROM [SP]

.ENDM

PUSH_FR: .MACRO

    SECBANK ON
    R1 = FR
    R2 = 0x1FFF
    R1 = R1 & R2
    PUSH R1 TO [SP]
    SECBANK OFF

.ENDM

POP_FR: .MACRO

    SECBANK ON
    POP R1 FROM [SP]
    R2 = 0x1FFF
    R1 = R1 & R2
    FR = R1
    SECBANK OFF

.ENDM

// Code Section
.CODE

_portSAVE_CONTEXT: .PROC

    SECBANK ON 
    POP R3,R4 FROM [SP]
    PUSH R3,R4 TO [SP]
    SECBANK OFF

    PUSH_FR
    PUSH_ALL

    R1 = [_pxCurrentTCB]
    [R1] = SP

    SECBANK ON 
    PUSH R3,R4 TO [SP]
    SECBANK OFF

    RETF

.ENDP

_portRESTORE_CONTEXT: .PROC

    R1 = [_pxCurrentTCB]
    SP = [R1]

    POP_ALL

    RETI

.ENDP

_uxPortReadFlagRegister: .PROC

    R1 = FR
    R2 = 0x1FFF
    R1 = R1 & R2

    RETF

.ENDP

_vPortWriteFlagRegister: .PROC

    PUSH_ALL

    BP = SP + 5
    R1 = [BP + 3]

    R2 = 0x1FFF
    R1 = R1 & R2
    FR = R1

    POP_ALL

    RETF

.ENDP

// Text Section
.TEXT

