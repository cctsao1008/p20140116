//==========================================================================
// File Name   : GPCE206x.H
// Description : GPCE206x registers and constants definition
// Written by  : Caspar Chi
// Last modified date:
//              2011/06/03
//==========================================================================

//--------------------------------------------------------------------------------------------------------------------------------------------
//	GPIO Configration
//	Dir		Att		Dat		Function Description			Wakeup
//	0		0		0		Input Pull Low					Yes
//	0		0		1		Input Pull High					Yes
//	0		1		0		Input Floating					Yes
//	0		1		1		Input Floating					Yes
//	1		0		0		Output High (Inverted)			No		(With Io Toggle Capability)
//	1		0		1		Output Low (Inverted)			No		(With Io Toggle Capability)
//	1		1		0		Output Low						No
//	1		1		1		Output High						No
//--------------------------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------------------------------------------
//	Special IO Function
//	IOA_Func	Bit15	Bit14	Bit13	Bit12	Bit11	Bit10	Bit9	Bit8	Bit7	Bit6	Bit5	Bit4	Bit3	Bit2	Bit1	Bit0
//	IR			-		-		-		-		-		-		-		-		-		-		-		-		-		-		IROUT	-
//	Wakeup		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes
//	FB/OSC		-		-		-		-		FO2		FI2		FO1		FI1		-		-		-		-		-		-		-		-
//	Ext_Int		-		-		-		-		-		EXT2	-		EXT1	-		-		-		-		-		-		-		-
//	IOPWM		-		-		-		-		-		-		-		-		-		-		-		-		-		-		-		IOPWM
//	SPI			SPIRX	SPITX	SPICK	SPICS	-		-		-		-		-		-		-		-		-		-		-		-
//	HighDriving	-		-		-		-		-		-		-		-		Yes		Yes		Yes		Yes		-		-		-		-
//	IOToggle	Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes
//--------------------------------------------------------------------------------------------------------------------------------------------
//	IOB_Func	Bit15	Bit14	Bit13	Bit12	Bit11	Bit10	Bit9	Bit8	Bit7	Bit6	Bit5	Bit4	Bit3	Bit2	Bit1	Bit0
//	ADC_CH		I2S_WS	I2S_DA	I2S_CK	-		-		-		-		-		-		AN7		AN6		AN5		AN4		AN3		AN2		AN1		AN0
//	IOToggle	Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes		Yes
//--------------------------------------------------------------------------------------------------------------------------------------------

#ifndef    __GPCE206x_H__
#define    __GPCE206x_H__

typedef union tagREG {

    unsigned int w;

    struct {
        unsigned b_0 :1;
        unsigned b_1 :1;
        unsigned b_2 :1;
        unsigned b_3 :1;
        unsigned b_4 :1;
        unsigned b_5 :1;
        unsigned b_6 :1;
        unsigned b_7 :1;
        unsigned b_8 :1;
        unsigned b_9 :1;
        unsigned b_10 :1;
        unsigned b_11 :1;
        unsigned b_12 :1;
        unsigned b_13 :1;
        unsigned b_14 :1;
        unsigned b_15 :1;
    };
} *REG;

//////////////////////////////////////////////////////////////////////////////////////
//====================================================================================
//  Port Definition
//====================================================================================
//////////////////////////////////////////////////////////////////////////////////////
#define P_IOA_Data            ((volatile  REG)       0x2000)
#define P_IOA_Buffer          ((volatile  REG)       0x2001)
#define P_IOA_Dir             ((volatile  REG)       0x2002)
#define P_IOA_Attrib          ((volatile  REG)       0x2003)
#define P_IOB_Data            ((volatile  REG)       0x2004)
#define P_IOB_Buffer          ((volatile  REG)       0x2005)
#define P_IOB_Dir             ((volatile  REG)       0x2006)
#define P_IOB_Attrib          ((volatile  REG)       0x2007)
#define P_IO_Ctrl             ((volatile  REG)       0x2008)
#define P_IOA_WakeUp_Mask		0x2009		// New Register

#define P_IOA_DA              ((volatile  REG)       0x2000)
#define P_IOA_BU              ((volatile  REG)       0x2001)
#define P_IOA_DI              ((volatile  REG)       0x2002)
#define P_IOA_AT              ((volatile  REG)       0x2003)
#define P_IOB_DA              ((volatile  REG)       0x2004)
#define P_IOB_BU              ((volatile  REG)       0x2005)
#define P_IOB_DI              ((volatile  REG)       0x2006)
#define P_IOB_AT              ((volatile  REG)       0x2007)
#define P_IOX_CT              ((volatile  REG)       0x2008)

//---------------------------------------------------
#define P_TimerA_Data         (*(volatile unsigned int*) 0x2010)
#define P_TimerA_CNTR         (*(volatile unsigned int*) 0x2011)
#define P_TimerB_Data         (*(volatile unsigned int*) 0x2012)
#define P_TimerB_CNTR         (*(volatile unsigned int*) 0x2013)
#define P_TimerC_Data         (*(volatile unsigned int*) 0x2014)
#define P_TimerC_CNTR         (*(volatile unsigned int*) 0x2015)
#define P_Timer_Ctrl          (*(volatile unsigned int*) 0x2016)

//---------------------------------------------------
#define P_PWM_Ctrl            (*(volatile unsigned int*) 0x2020)

//---------------------------------------------------
#define P_System_Clock        (*(volatile unsigned int*) 0x2030)
#define P_System_Reset        (*(volatile unsigned int*) 0x2031)
#define P_Reset_LVD_Ctrl      (*(volatile unsigned int*) 0x2032)
#define P_TimeBase_Clear      (*(volatile unsigned int*) 0x2033)
#define P_Watchdog_Clear      (*(volatile unsigned int*) 0x2034)
#define P_Wait_Ctrl           (*(volatile unsigned int*) 0x2035)
#define P_System_Sleep        (*(volatile unsigned int*) 0x2036)

//---------------------------------------------------
#define P_DAC_Ctrl            (*(volatile unsigned int*) 0x2040)
#define P_DAC_CH1_Data        (*(volatile unsigned int*) 0x2041)
#define P_DAC_CH2_Data			0x2042		// New Register
#define P_PPAMP_Ctrl			0x2043		// New Register

//---------------------------------------------------
#define P_INT_Ctrl            (*(volatile unsigned int*) 0x2050)
#define P_INT_Status          (*(volatile unsigned int*) 0x2051)
#define P_FIQ_Sel             (*(volatile unsigned int*) 0x2052)

//---------------------------------------------------
#define P_SPI_Ctrl            (*(volatile unsigned int*) 0x2060)
#define P_SPI_TX_Status       (*(volatile unsigned int*) 0x2061)
#define P_SPI_TX_Data         (*(volatile unsigned int*) 0x2062)
#define P_SPI_RX_Status       (*(volatile unsigned int*) 0x2063)
#define P_SPI_RX_Data         (*(volatile unsigned int*) 0x2064)
#define P_SPI_Misc            (*(volatile unsigned int*) 0x2065)

//---------------------------------------------------
#define P_ADC_Ctrl            (*(volatile unsigned int*) 0x2070)
#define P_ADC_Data            (*(volatile unsigned int*) 0x2071)
#define P_ADC_LineIn_BitCtrl  (*(volatile unsigned int*) 0x2072)
#define P_ADC_PGA_Ctrl			0x2073		// New Register

//---------------------------------------------------
#define P_Flash_Ctrl          (*(volatile unsigned int*) 0x26FF)

//---------------------------------------------------
//---------------------------------------------------
//---------------------------------------------------


//////////////////////////////////////////////////////////////////////////////////////
//====================================================================================
// Constant Definition
//====================================================================================
//////////////////////////////////////////////////////////////////////////////////////

//====================================================================================
// P_IO_Ctrl (0x2008)
//====================================================================================
// Bit[15:12] : Reserved
// Bit[11] : IO_Toggle_En
#define	C_IO_Toggle_Disable		0x0000		// IO Toggle Disable 
#define	C_IO_Toggle_Enable		0x0800		// IO Toggle Enable 
// Bit[10] : FW_SPI_CS
#define C_FW_SPI_CS				0x0400
#define	C_SPI_CS_Firmware		0x0000		// Set CS_Pin as SPI_CS, Control by Hardware SPI
#define	C_SPI_CS_Hardware		0x0400		// Set CS_Pin as GPIO, Control by Program (Only by Output Configuration)
// Bit[9:8] : IR_Duty === IRout:IOA1
#define	C_IR_Duty				0x0300
#define C_IR_Duty_DIV_2         0x0000    // 1/2 Duty
#define C_IR_Duty_DIV_3         0x0100    // 1/3 Duty
#define C_IR_Duty_DIV_4         0x0200    // 1/4 Duty
#define C_IR_Duty_DIV_5         0x0300    // 1/5 Duty
// Bit[7:6] : IR_Ctrl
#define C_IR_Ctrl               0x00C0
#define C_IR_Disable            0x0000    // IR Disable ; IOA1 as Normal IO
#define C_IR_With_TimerA        0x0040    // IR Function Enable with Timer A as Source
#define C_IR_With_TimerB        0x0080    // IR Function Enable with Timer B as Source
#define C_IR_With_TimerC        0x00C0    // IR Function Enable with Timer C as Source
// Bit[5:4] : EXT2_Ctrl === FI2:IOA10  FO2:IOA11
#define C_EXT2_Ctrl             0x0030
#define C_EXT2_Normal_Rising    0x0000    // Normal IO With Rising Edge Trigger
#define C_EXT2_Normal_Falling   0x0010    // Normal IO With Falling Edge Trigger
#define C_EXT2_Feedback_Rising  0x0020    // Feedback Oscillator With Rising Edge Trigger
#define C_EXT2_Feedback_Falling 0x0030    // Feedback Oscillator With Falling Edge Trigger
// Bit[3:2] : EXT1_Ctrl === FI1:IOA8  FO1:IOA9
#define C_EXT1_Ctrl             0x000C
#define C_EXT1_Normal_Rising    0x0000    // Normal IO With Rising Edge Trigger
#define C_EXT1_Normal_Falling   0x0004    // Normal IO With Falling Edge Trigger
#define C_EXT1_Feedback_Rising  0x0008    // Feedback Oscillator With Rising Edge Trigger
#define	C_EXT1_Feedback_Falling	0x000C		// Feedback Oscillator With Falling Edge Trigger
// Bit[1:0] : IO_Toggle_Ctrl 
#define	C_IO_Toggle_Ctrl		0x0003
#define C_IO_Toggle_With_FRTC	0x0000		// IO Toggle Function Source form FRTC directly
#define C_IO_Toggle_With_TimerA	0x0001		// IO Toggle Function with Timer A
#define C_IO_Toggle_With_TimerB	0x0002		// IO Toggle Function with Timer B
#define C_IO_Toggle_With_TimerC	0x0003		// IO Toggle Function with Timer C

//====================================================================================
// P_IOA_WakeUp_Mask (0x2009)
//====================================================================================
// Bit[15:0] : Wakeup Mask Control (Bit Control)
#define C_IOA_WakeUp_UnMask		0x0000
#define C_IOA_WakeUp_Mask		0xFFFF

//====================================================================================
// P_Timer_Ctrl (0x2016)  Timer Setting
//====================================================================================
// Bit[15:12] : Reserved
// Bit[11:8] : TMCSEL
#define C_TimerC_Sel			0x0F00
#define C_TimerC_Disable		0x0000
#define C_TimerC_Software_Count	0x0100
#define C_TimerC_FRTC_EXT2		0x0200
#define C_TimerC_EXT1_EXT2		0x0200
#define C_TimerC_FPLL_EXT2		0x0300
#define C_TimerC_EXT2_64Hz		0x0400
#define C_TimerC_EXT2_16Hz		0x0500
#define C_TimerC_EXT2_2Hz		0x0600
#define C_TimerC_EXT2			0x0700
#define C_TimerC_FRTC_64Hz		0x0800
#define C_TimerC_FRTC_16Hz		0x0900
#define C_TimerC_FRTC_2Hz		0x0A00
#define C_TimerC_FRTC			0x0B00
#define C_TimerC_FPLL_64Hz		0x0C00
#define C_TimerC_FPLL_16Hz		0x0D00
#define C_TimerC_FPLL_2Hz		0x0E00
#define C_TimerC_FPLL			0x0F00
// Bit[7:4] : TMBSEL
#define C_TimerB_Sel			0x00F0
#define C_TimerB_Disable		0x0000
#define C_TimerB_Software_Count	0x0010
#define C_TimerB_FRTC_EXT2		0x0020
#define C_TimerB_EXT1_EXT2		0x0020
#define C_TimerB_FPLL_EXT2		0x0030
#define C_TimerB_EXT2_64Hz		0x0040
#define C_TimerB_EXT2_16Hz		0x0050
#define C_TimerB_EXT2_2Hz		0x0060
#define C_TimerB_EXT2			0x0070
#define C_TimerB_FRTC_64Hz		0x0080
#define C_TimerB_FRTC_16Hz		0x0090
#define C_TimerB_FRTC_2Hz		0x00A0
#define C_TimerB_FRTC			0x00B0
#define C_TimerB_FPLL_64Hz		0x00C0
#define C_TimerB_FPLL_16Hz		0x00D0
#define C_TimerB_FPLL_2Hz		0x00E0
#define C_TimerB_FPLL			0x00F0
// Bit[3:0] : TMASEL
#define C_TimerA_Sel			0x000F
#define C_TimerA_Disable		0x0000
#define C_TimerA_Software_Count	0x0001
#define C_TimerA_FRTC_EXT2		0x0002
#define C_TimerA_EXT1_EXT2		0x0002
#define C_TimerA_FPLL_EXT2		0x0003
#define C_TimerA_EXT2_64Hz		0x0004
#define C_TimerA_EXT2_16Hz		0x0005
#define C_TimerA_EXT2_2Hz		0x0006
#define C_TimerA_EXT2			0x0007
#define C_TimerA_FRTC_64Hz		0x0008
#define C_TimerA_FRTC_16Hz		0x0009
#define C_TimerA_FRTC_2Hz		0x000A
#define C_TimerA_FRTC			0x000B
#define C_TimerA_FPLL_64Hz		0x000C
#define C_TimerA_FPLL_16Hz		0x000D
#define C_TimerA_FPLL_2Hz		0x000E
#define C_TimerA_FPLL			0x000F


//====================================================================================
// Timer Data and System Clock Definition
// P_TimerA_Data (0x2010)  Timer Data 
// P_TimerB_Data (0x2012)  Timer Data 
// P_TimerC_Data (0x2014)  Timer Data 
//====================================================================================
//#define SystemClock				20480000
//#define SystemClock				24576000
//#define SystemClock				32768000
//#define SystemClock				40960000
#define SystemClock				49152000
//#define SystemClock				12000000		// For FPGA Test
//#define SystemClock            24000000    // For FPGA Test
//#define SystemClock            48000000    // For FPGA Test

#define C_Timer_Setting_1K      65536 - (SystemClock / 1000)
#define C_Timer_Setting_2K      65536 - (SystemClock / 2000)
#define C_Timer_Setting_3K      65536 - (SystemClock / 3000)
#define C_Timer_Setting_4K      65536 - (SystemClock / 4000)
#define C_Timer_Setting_5K      65536 - (SystemClock / 5000)
#define C_Timer_Setting_6K      65536 - (SystemClock / 6000)
#define C_Timer_Setting_7K      65536 - (SystemClock / 7000)
#define C_Timer_Setting_8K      65536 - (SystemClock / 8000)
#define C_Timer_Setting_9K      65536 - (SystemClock / 9000)
#define C_Timer_Setting_10K     65536 - (SystemClock / 10000)
#define C_Timer_Setting_11K     65536 - (SystemClock / 11000)
#define C_Timer_Setting_12K     65536 - (SystemClock / 12000)
#define C_Timer_Setting_13K     65536 - (SystemClock / 13000)
#define C_Timer_Setting_14K     65536 - (SystemClock / 14000)
#define C_Timer_Setting_15K     65536 - (SystemClock / 15000)
#define C_Timer_Setting_16K     65536 - (SystemClock / 16000)
#define C_Timer_Setting_20K     65536 - (SystemClock / 20000)
#define C_Timer_Setting_24K     65536 - (SystemClock / 24000)
#define C_Timer_Setting_28K     65536 - (SystemClock / 28000)
#define C_Timer_Setting_32K     65536 - (SystemClock / 32000)
#define C_Timer_Setting_36K     65536 - (SystemClock / 36000)
#define C_Timer_Setting_40K     65536 - (SystemClock / 40000)
#define C_Timer_Setting_48K    	65536 - (SystemClock / 48000)
#define C_Timer_Setting_64K    	65536 - (SystemClock / 64000)
#define C_Timer_Setting_96K    	65536 - (SystemClock / 96000)
#define C_Timer_Setting_500K   	65536 - (SystemClock / 500000)

#define C_Timer_Setting_15555  	65536 - (SystemClock / 15555)	// For FPGA Test
#define C_Timer_Setting_17777  	65536 - (SystemClock / 17777)	// For FPGA Test

//====================================================================================
// P_PWM_Ctrl (0x2020)  IOPWM
//====================================================================================
// Bit[15] : IOPWM_CNT_Clear
#define	C_IOPWM_CNT_Clear		0x8000
// Bit[14:11] : Reserved
// Bit[10] : IOPWM_Mask
#define	C_IOPWM_Mask			0x0400
#define	C_IOPWM_Mask_Disable	0x0000		//default
#define	C_IOPWM_Mask_Enable		0x0400
// Bit[9:8] : Clock Source for IOPWM
#define	C_IOPWM_CLK_SRC			0x0300
#define	C_IOPWM_SRC_FRTC_Div2	0x0000
#define	C_IOPWM_SRC_TimerA		0x0100
#define	C_IOPWM_SRC_TimerB		0x0200
#define	C_IOPWM_SRC_TimerC		0x0300
// Bit[7:0] : PWM_Duty => have 256 steps
#define	C_IOPWM_Duty			0x00FF
#define C_IOPWM_OFF				0x0000
#define C_IOPWM_1_Div_256		0x0001
#define C_IOPWM_128_Div_256		0x0080
#define C_IOPWM_254_Div_256		0x00FE
#define C_IOPWM_1_Div_2			0x00FF

//====================================================================================
// P_System_Clock (0x2030)  
// The System Clock can be configured form 24.576MHz to 49.152MHz
//====================================================================================
// Bit[15:8] : Reserved
// Bit[7:5] : FOSC
#define C_FOSC					0x00E0
#define C_FOSC_24576KHz           0x0000
#define C_FOSC_20480KHz           0x0020
#define C_FOSC_32768KHz           0x0040
#define C_FOSC_40960KHz           0x0060
#define C_FOSC_49152KHz           0x0080
#define C_FOSC_49152KHz_M1        0x00A0
#define C_FOSC_49152KHz_M2        0x00C0
#define C_FOSC_49152KHz_M3        0x00E0
// Bit[4] : 32KHz Sleep Status
#define C_Sleep_RTC_Status        0x0010
#define C_Sleep_RTC_SLP_Off       0x0000
#define C_Sleep_RTC_SLP_Work      0x0010
// Bit[3] : Strong Mode
#define C_RTC_Mode_Sel            0x0008
#define C_RTC_Mode_Weak           0x0000
#define C_RTC_Mode_Strong         0x0008
// Bit[2:0] : CPU Clock
#define C_CPU_CLK                 0x0007
#define C_CPU_CLK_FOSC            0x0000
#define C_CPU_CLK_FOSC_DIV_2      0x0001
#define C_CPU_CLK_FOSC_DIV_4      0x0002
#define C_CPU_CLK_FOSC_DIV_8      0x0003      // Default Value
#define C_CPU_CLK_FOSC_DIV_16     0x0004
#define C_CPU_CLK_FOSC_DIV_32     0x0005
#define C_CPU_CLK_FOSC_DIV_64     0x0006
#define C_CPU_CLK_FOSC_DIV_128    0x0007

// P_System_Sleep (0x2036)
#define C_System_Sleep            0x5555
// P_System_Reset (0x2031)
#define C_Software_Reset          0x5555
// P_TimeBase_Clear (0x2033)
#define C_TimeBase_Clear          0x5555      // Write any value to clear
// P_Watchdog_Clear (0x2034)
#define C_Watchdog_Clear          0x5555

//====================================================================================
// P_Reset_LVD_Ctrl (0x2032)
//====================================================================================
// Bit[15]
#define C_Watchdog_Reset_Flag     0x8000      // Flag
// Bit[14]
#define C_Software_Reset_Flag     0x4000      // Flag
// Bit[13]
#define C_Wathcdog_Reset_Err_Flag 0x2000      // Flag
// Bit[12]
#define C_ILL_Addr_Reset_Flag     0x1000      // Flag
// Bit[11]
#define C_LVD_Status_Flag         0x0800      // Flag
// Bit[9:2] Reserved
// Bit[1:0] : LVD_Ctrl
#define C_LVD_Ctrl                0x0003
#define C_LVD_Ctrl_3D2V           0x0000      // Default Value
#define C_LVD_Ctrl_3D0V           0x0001
#define C_LVD_Ctrl_2D8V           0x0002
#define	C_LVD_Ctrl_2D6V			0x0003
// LVR always setting as 2.2v

//====================================================================================
// P_Wait_Ctrl (0x2035)
//====================================================================================
// Bit[15:4] : Reserved
// Bit[3:0] : Wait State Value
#define	C_Wait_State_Reg		0x000F
#define C_Wait_State_2Cycles1     0x0000
#define C_Wait_State_2Cycles2     0x0001
#define C_Wait_State_2Cycles      0x0002
#define C_Wait_State_3Cycles      0x0003      // Default Value
#define C_Wait_State_4Cycles      0x0004
#define C_Wait_State_5Cycles      0x0005
#define C_Wait_State_6Cycles      0x0006
#define C_Wait_State_7Cycles      0x0007
#define C_Wait_State_8Cycles      0x0008
#define C_Wait_State_9Cycles      0x0009
#define C_Wait_State_10Cycles     0x000A
#define C_Wait_State_11Cycles     0x000B
#define C_Wait_State_12Cycles     0x000C
#define C_Wait_State_13Cycles     0x000D
#define C_Wait_State_14Cycles     0x000E
#define C_Wait_State_15Cycles     0x000F

//====================================================================================
// P_DAC_Ctrl (0x2040)
//====================================================================================
// Bit[15] : Reserved
// Bit[14] : Scaler Enable
#define	C_DAC_Scaler_Disable		0x0000
#define	C_DAC_Scaler_Enable			0x4000
// Bit[13] : Half Volume Enable
#define	C_DAC_Half_Vol_Disable		0x0000
#define	C_DAC_Half_Vol_Enable		0x2000
// Bit[12] : Voltage DAC Enable
#define	C_DAC_Disable				0x0000
#define	C_DAC_Enable				0x1000
// Bit[11] : DAC CH2 UpSample Enable
#define	C_DAC_CH2_Up_Sample_Disable	0x0000
#define	C_DAC_CH2_Up_Sample_Enable	0x0800
// Bit[10] : DAC Channel 2 Data Enable
#define	C_DAC_CH2_Disable			0x0000
#define	C_DAC_CH2_Enable			0x0400
// Bit[9:8] : DAC CH2 Timer Select
#define C_DAC_CH2_TMR_Sel			0x0300
#define C_DAC_CH2_TMR_Sel_Manual	0x0000
#define C_DAC_CH2_TMR_Sel_TimerA	0x0100
#define C_DAC_CH2_TMR_Sel_TimerB	0x0200
#define C_DAC_CH2_TMR_Sel_TimerC	0x0300
// Bit[7:4] : Reserved
// Bit[3] : DAC CH1 UpSample Enable
#define	C_DAC_CH1_Up_Sample_Disable	0x0000
#define	C_DAC_CH1_Up_Sample_Enable	0x0008
// Bit[2] : DAC Channel 1 Data Enable
#define	C_DAC_CH1_Disable			0x0000
#define	C_DAC_CH1_Enable			0x0004		// DAC1 Mixer Enable
// Bit[1:0] : DAC CH1 Timer Select
#define C_DAC_CH1_TMR_Sel			0x0003
#define C_DAC_CH1_TMR_Sel_Manual	0x0000
#define C_DAC_CH1_TMR_Sel_TimerA	0x0001
#define C_DAC_CH1_TMR_Sel_TimerB	0x0002
#define C_DAC_CH1_TMR_Sel_TimerC	0x0003

//====================================================================================
// P_PPAMP_Ctrl (0x2043)
//====================================================================================
// Bit[15:8] : Reserved
// Bit[7] : Extenal Line In Signal Mixer Enable
#define	C_Ext_DAC_In_Disable	0x0000
#define	C_Ext_DAC_In_Enable		0x0080
// Bit[6] : Push-Pull PMOS Enable
#define	C_PP_PMOS_Disable		0x0000
#define	C_PP_PMOS_Enable		0x0040
// Bit[5] : Push-Pull NMOS Enable
#define	C_PP_NMOS_Disable		0x0000
#define	C_PP_NMOS_Enable		0x0020
// Bit[4] : Reserved
// Bit[3:0] : Push-Pull Gain Select
#define C_PP_Gain_Sel			0x000F
#define C_PP_Gain_LV0			0x0000
#define C_PP_Gain_LV0_1			0x0001
#define C_PP_Gain_LV0_2			0x0002
#define C_PP_Gain_LV0_3			0x0003
#define C_PP_Gain_LV0_4			0x0004
#define C_PP_Gain_LV1			0x0005
#define C_PP_Gain_LV2			0x0006
#define C_PP_Gain_LV3			0x0007
#define C_PP_Gain_LV4			0x0008
#define C_PP_Gain_LV5			0x0009
#define C_PP_Gain_LV6			0x000A
#define C_PP_Gain_LV7			0x000B
#define C_PP_Gain_LV8			0x000C
#define C_PP_Gain_LV9			0x000D
#define C_PP_Gain_LV10			0x000E
#define C_PP_Gain_LV11			0x000F


//====================================================================================
// P_INT_Ctrl (0x2050)
// P_INT_Status (0x2051)
// P_FIQ_Sel (0x2052)
//====================================================================================
// Bit[15:13] : Reserve
// Bit[12:0] : All Interrupt Vector
#define C_IRQ0_TMA					0x1000
#define C_IRQ1_TMB					0x0800
#define C_IRQ2_TMC					0x0400
#define C_IRQ3_SPI					0x0200
#define C_IRQ4_KEY					0x0100
#define C_IRQ5_EXT1					0x0080
#define C_IRQ5_EXT2					0x0040
#define C_IRQ6_4096Hz				0x0020
#define C_IRQ6_2048Hz				0x0010
#define C_IRQ6_512Hz				0x0008
#define C_IRQ7_64Hz					0x0004
#define C_IRQ7_16Hz					0x0002
#define C_IRQ7_2Hz					0x0001

//====================================================================================
// P_SPI_Ctrl (0x2060)
//====================================================================================
// Bit[15] : SPI Enable
#define C_SPI_Disable				0x0000
#define C_SPI_Enable				0x8000
// Bit[14] : Reserved
// Bit[13] : Loop Back Mode Selection
#define	C_SPI_LBM_Normal			0x0000
#define	C_SPI_LBM_Enable			0x2000
// Bit[12] : Reserved
// Bit[11] : SPI Reset
#define C_SPI_Reset					0x0800
// Bit[10:9] : Reserved
// Bit[8] : SPI Mode
#define	C_SPI_Mode					0x0100
#define C_MasterMode				0x0000
#define C_SlaveMode  				0x0100
// Bit[7:6] : Reserved
// Bit[5] : SPI Clock Phase
#define C_SPI_Clock_Phase			0x0020
#define C_SPI_Clock_Phase_Normal	0x0000	// Rising Edge Trigger or Falling Edge Trigger depend on Polarity
#define C_SPI_Clock_Phase_Shift		0x0020  // (POL=0, PHA=1)
// Bit[4] : SPI Clock Polarity
#define	C_SPI_Clock_Pol				0x0010
#define C_SPI_Clock_Pol_Normal		0x0000	// Clock Normal or Inverted 
#define C_SPI_Clock_Pol_Inverse		0x0010
// Bit[3] : Reserved
// Bit[2:0] : Master Mode clock selection : 111b is reserved
#define C_SPI_SCK_SEL				0x0007
#define C_SCKSEL_FPLL_Div_2       0x0000
#define C_SCKSEL_FPLL_Div_4       0x0001
#define C_SCKSEL_FPLL_Div_8       0x0002
#define C_SCKSEL_FPLL_Div_16      0x0003
#define C_SCKSEL_FPLL_Div_32      0x0004
#define C_SCKSEL_FPLL_Div_64		0x0005	
#define C_SCKSEL_FPLL_Div_128		0x0006

//====================================================================================
// P_SPI_TX_Status (0x2061)
//====================================================================================
// Bit[15] : SPI TX interrupt flag
#define C_SPI_TX_INT_Flag			0x8000
// Bit[14] : SPI TX interrupt enable
#define C_SPI_TX_INT_DIS			0x0000
#define C_SPI_TX_INT_EN				0x4000
// Bit[13:8] : Reserved
// Bit[7:4] : SPI TX level setting
#define C_SPI_TX_FIFO_Level			0x0070		// 0 ~ 7
#define C_SPI_TX_FIFO_Level_0		0x0000
#define C_SPI_TX_FIFO_Level_1		0x0010
#define C_SPI_TX_FIFO_Level_2		0x0020
#define C_SPI_TX_FIFO_Level_3		0x0030
#define C_SPI_TX_FIFO_Level_4		0x0040
#define C_SPI_TX_FIFO_Level_5		0x0050
#define C_SPI_TX_FIFO_Level_6		0x0060
#define C_SPI_TX_FIFO_Level_7		0x0070
// Bit[3:0] : SPI TX Flag (read only) : Only 8 FIFOs  
#define	C_SPI_TX_Flag				0x0007		// 0 ~ 7

//====================================================================================
// P_SPI_RX_Status (0x2063)
//====================================================================================
// Bit[15] : SPI RX interrupt flag
#define C_SPI_RX_INT_Flag			0x8000
// Bit[14] : SPI Rx interrupt enable
#define C_SPI_RX_INT_DIS			0x0000
#define C_SPI_RX_INT_EN				0x4000
// Bit[13:10] : Reserved
// Bit[9] : SPI RX buffer full (read only)
#define C_SPI_RX_BUF_Full			0x0200
// Bit[8] : SPI RX buffer overwrite (read only)
#define C_SPI_RX_BUF_OVER_ERROR		0x0100
// Bit[7:4] : SPI RX full level setting
#define C_SPI_RX_FIFO_Level			0x0070
#define C_SPI_RX_FIFO_Level_1		0x0000
#define C_SPI_RX_FIFO_Level_2		0x0010
#define C_SPI_RX_FIFO_Level_3		0x0020
#define C_SPI_RX_FIFO_Level_4		0x0030
#define C_SPI_RX_FIFO_Level_5		0x0040
#define C_SPI_RX_FIFO_Level_6		0x0050
#define C_SPI_RX_FIFO_Level_7		0x0060
#define C_SPI_RX_FIFO_Level_8		0x0070
// Bit[3:0] : SPI RX Flag (read only)
#define	C_SPI_RX_Flag				0x0007		// 0 ~ 7

//====================================================================================
// P_SPI_Misc (0x2065)
//====================================================================================
// Bit[15:10] : Reserved
// Bit[9] : SPI FIFO Over Write Mode
#define	C_SPI_FIFO_Full_Write_Skipped	0x0000
#define	C_SPI_FIFO_Full_Overwrite		0x0200
// Bit[8] : SPI FIFO Smart Mode Register
#define	C_SPI_FIFO_Normal_Mode			0x0000
#define	C_SPI_FIFO_Smart_Mode			0x0100
// Bit[7:5] : Reserved
// Bit[4] : SPI Controller Busy Flag
#define	C_SPI_Busy_Flag					0x0010
// Bit[3] : Receive FIFO Full Flag
#define	C_SPI_RX_Full_Flag				0x0008
// Bit[2] : Receive FIFO Empty Flag
#define	C_SPI_RX_Empty_Flag				0x0004
// Bit[1] : Transmit FIFO Not Full Flag
#define	C_SPI_TX_NonFull_Flag			0x0002
// Bit[0] : Transmit FIFO Empty Flag
#define	C_SPI_TX_Empty_Flag				0x0001

//====================================================================================
// P_ADC_Ctrl (0x2070)
//====================================================================================
// Bit[15] : ADC busy (read only)
#define C_ADC_Busy						0x8000
// Bit[14] : Auto scan busy (read only)
#define C_ADC_Auto_Scan_Busy			0x4000
// Bit[13:12] : Timer select for auto scan mode
#define C_ADC_Manual					0x0000
#define C_ADC_Timer_A					0x1000
#define C_ADC_Timer_B					0x2000
#define C_ADC_Timer_C					0x3000
// Bit[11:9] : ADC manual mode channel setting
#define C_ADC_Manual_AN0				0x0000
#define C_ADC_Manual_AN1				0x0200
#define C_ADC_Manual_AN2              0x0400
#define C_ADC_Manual_AN3              0x0600
#define C_ADC_Manual_AN4              0x0800
#define C_ADC_Manual_AN5              0x0A00
#define C_ADC_Manual_AN6				0x0C00
#define C_ADC_Manual_AN7				0x0E00
// Bit[8:7] : ADC clock setting
#define C_ADC_CLK_Sel					0x0180
#define C_ADC_CLK_FPLL_Div_16			0x0000
#define C_ADC_CLK_FPLL_Div_32			0x0080
#define C_ADC_CLK_FPLL_Div_64			0x0100
#define C_ADC_CLK_FPLL_Div_128			0x0180
// Bit[6] : ADC Chip Enable for Bias Circuit
#define	C_ADC_Bias_Disable				0x0000
#define	C_ADC_Bias_Enable				0x0040
// Bit[5] : V_MIC Power Supply Enable
#define	C_ADC_MIC_Disable				0x0000
#define	C_ADC_MIC_Enable				0x0020
// Bit[4] : A/D Input Select in Manual Mode
#define C_ADC_Ch0_in_MIC 				0x0000
#define C_ADC_Ch0_in_LineinPB0			0x0010
// Bit[3] : AGC Enable 
#define	C_AGC_Disable					0x0000
#define	C_AGC_Enable					0x0008
// Bit[2] : ADC Enable 
#define	C_ADC_Disable					0x0000
#define	C_ADC_Enable					0x0004
// Bit[1:0] : Conversion Cycle Select
#define	C_ADC_Conv_Cycle				0x0003
#define	C_ADC_Conv_Cyc_8				0x0000	// Default
#define	C_ADC_Conv_Cyc_16				0x0001
#define	C_ADC_Conv_Cyc_32				0x0002
#define	C_ADC_Conv_Cyc_64				0x0003

//====================================================================================
// P_ADC_LineIn_BitCtrl (0x2072)
//====================================================================================
#define	C_ADC_Linein_Enable				0x00FF
#define	C_ADC_AN0_Enable				0x0001
#define	C_ADC_AN1_Enable				0x0002
#define	C_ADC_AN2_Enable				0x0004
#define	C_ADC_AN3_Enable				0x0008
#define	C_ADC_AN4_Enable				0x0010
#define	C_ADC_AN5_Enable				0x0020
#define	C_ADC_AN6_Enable				0x0040
#define	C_ADC_AN7_Enable				0x0080

//====================================================================================
// P_ADC_PGA_Ctrl (0x2072)
//====================================================================================
// Bit[15:8] : Reserved
// Bit[7] : PGA Function Enable
#define C_ADC_PGA_Disable				0x0000
#define C_ADC_PGA_Enable				0x0080
// Bit[6:5] : Reserved
// Bit[4:0] : PGA's Gain Stage Select
#define C_ADC_PGA_Gain_Sel				0x001F
#define C_ADC_PGA_Gain_Sel_0			0x0000		//    0dB
#define C_ADC_PGA_Gain_Sel_1			0x0001		//  1.5dB
#define C_ADC_PGA_Gain_Sel_2			0x0002		//    3dB
#define C_ADC_PGA_Gain_Sel_3			0x0003		//  4.5dB
#define C_ADC_PGA_Gain_Sel_4			0x0004		//    6dB
#define C_ADC_PGA_Gain_Sel_5			0x0005		//  7.5dB
#define C_ADC_PGA_Gain_Sel_6			0x0006		//    9dB
#define C_ADC_PGA_Gain_Sel_7			0x0007		// 10.5dB
#define C_ADC_PGA_Gain_Sel_8			0x0008		//   12dB
#define C_ADC_PGA_Gain_Sel_9			0x0009		// 13.5dB
#define C_ADC_PGA_Gain_Sel_A			0x000A		//   15dB
#define C_ADC_PGA_Gain_Sel_B			0x000B		// 16.5dB
#define C_ADC_PGA_Gain_Sel_C			0x000C		//   18dB -> Default Value
#define C_ADC_PGA_Gain_Sel_D			0x000D		// 19.5dB
#define C_ADC_PGA_Gain_Sel_E			0x000E		//   21dB
#define C_ADC_PGA_Gain_Sel_F			0x000F		// 22.5dB
#define C_ADC_PGA_Gain_Sel_10			0x0010		//   24dB
#define C_ADC_PGA_Gain_Sel_11			0x0011		// 25.5dB
#define C_ADC_PGA_Gain_Sel_12			0x0012		//   27dB
#define C_ADC_PGA_Gain_Sel_13			0x0013		// 28.5dB
#define C_ADC_PGA_Gain_Sel_14			0x0014		//   30dB

//====================================================================================
// P_Flash_Ctrl (0x26FF)
//====================================================================================
#define C_Flash_Enable_Access_CMD		0xAAAA
#define C_Flash_PageErase_CMD			0x5511
#define C_Flash_Program_CMD				0x5533

//====================================================================================
// Bits Definition
//====================================================================================
#define	C_Bit15							0x8000
#define	C_Bit14							0x4000
#define	C_Bit13							0x2000
#define	C_Bit12							0x1000
#define	C_Bit11							0x0800
#define	C_Bit10							0x0400
#define	C_Bit9							0x0200
#define	C_Bit8							0x0100
#define	C_Bit7							0x0080
#define	C_Bit6							0x0040
#define	C_Bit5							0x0020
#define	C_Bit4							0x0010
#define	C_Bit3							0x0008
#define	C_Bit2							0x0004
#define	C_Bit1							0x0002
#define	C_Bit0							0x0001

#ifndef sbi
#define sbi(x,y)    x|=(1 << (y))
#endif

#ifndef cbi
#define cbi(x,y)    x&=~(1 << (y))
#endif

#ifndef tstb
#define tstb(x,y)    (x & (1 << (y)) ? 1 : 0)
#endif

#ifndef toggle
#define toggle(x,y)    x^=(1 << (y))
#endif

#ifndef BIT
#define BIT(x)    (1 << (x))
#endif

#define reset_watch_dog() (P_Watchdog_Clear = C_Watchdog_Clear)

#endif __GPCE206x_H__
