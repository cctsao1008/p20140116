.include    GPCE2064.inc
//.DEFINE     _ASM_PORT

.IFDEF      _ASM_PORT
.PUBLIC     _vPortStartFirstTask
.ENDIF

.IFDEF      _ASM_PORT
.PUBLIC     _vPortYield
.PUBLIC     _vPortYieldFromTick
.ENDIF

.PUBLIC     _uxPortReadFlagRegister
.PUBLIC     _vPortWriteFlagRegister
.PUBLIC     _portSAVE_CONTEXT
.PUBLIC     _portRESTORE_CONTEXT

.IFDEF      _ASM_PORT
.PUBLIC     _IRQ7
.ENDIF

.EXTERNAL   _pxCurrentTCB
.EXTERNAL   _vTaskSwitchContext
.EXTERNAL   _vTaskIncrementTick


// Macro definition
PUSHALL: .MACRO

    PUSH R1,R5 TO [SP]

    .ENDM

POPALL: .MACRO

    POP R1,R5 FROM [SP]

    .ENDM

PUSHFR: .MACRO

    SECBANK ON
    R1 = FR
    R2 = 0x1FFF
    R1 = R1 & R2
    PUSH R1 TO [SP]
    SECBANK OFF

    .ENDM

POPFR: .MACRO

    SECBANK ON
    POP R1 FROM [SP]
    R2 = 0x1FFF
    R1 = R1 & R2
    FR = R1
    SECBANK OFF

    .ENDM

// Code section
.CODE

_portSAVE_CONTEXT: .PROC

    SECBANK ON 
    POP R3,R4 FROM [SP]
    PUSH R3,R4 TO [SP]
    SECBANK OFF

    PUSHFR

    PUSHALL

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

    POPALL

    RETI

.ENDP

.IFDEF      _ASM_PORT
_vPortStartFirstTask: .PROC
    
    .IF 1
    R1 = [_pxCurrentTCB]
    SP = [R1]
    POPALL
    RETI
    .ELSE
    portRESTORE_CONTEXT
    .ENDIF

.ENDP
.ENDIF

.IFDEF      _ASM_PORT

_vPortYield: .PROC

    PUSHFR

    PUSHALL

    R1 = [_pxCurrentTCB]
    [R1] = SP

    CALL _vTaskSwitchContext

    R1 = [_pxCurrentTCB]
    SP = [R1]

    POPALL

    RETI

.ENDP

_vPortYieldFromTick .PROC

    PUSHFR

    PUSHALL

    R1 = [_pxCurrentTCB]
    [R1] = SP

    CALL _vTaskIncrementTick
    CALL _vTaskSwitchContext

    R1 = [_pxCurrentTCB]
    SP = [R1]

    POPALL

    RETI

.ENDP

.ENDIF

_uxPortReadFlagRegister: .PROC

    R1 = FR
    R2 = 0x1FFF
    R1 = R1 & R2

    RETF

.ENDP

_vPortWriteFlagRegister: .PROC

    PUSH R1,R5 TO [SP]		
    BP = SP + 5
    R1 = [BP+3]
    
    R2 = 0x1FFF
    R1 = R1 & R2
    FR = R1
    
    POP R1,R5 FROM [SP]

    RETF

.ENDP

// Text section
.TEXT

.IFDEF      _ASM_PORT
_IRQ7:

    PUSHALL

    R1 = C_IRQ7_64Hz
    [P_INT_Status] = R1

    R1 = C_Watchdog_Clear
    [P_Watchdog_Clear] = R1

    CALL _vTaskIncrementTick

    POPALL

    RETI

.ENDIF
