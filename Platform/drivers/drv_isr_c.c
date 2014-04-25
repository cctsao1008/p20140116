/*********************************************************************
 * Platform/drivers/drv_isr_c.c
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *      The driver performs interrupt service routine (ISR)
 *
 *********************************************************************/
#include "platform.h"

void BREAK(void) __attribute__ ((ISR));

#if 0
void FIQ(void) __attribute__ ((ISR));
#endif

void IRQ0(void) __attribute__ ((ISR));
void IRQ1(void) __attribute__ ((ISR));

#if 0
void IRQ2(void) __attribute__ ((ISR));
#endif

void IRQ3(void) __attribute__ ((ISR));
void IRQ4(void) __attribute__ ((ISR));
void IRQ5(void) __attribute__ ((ISR));

#if 0
void IRQ6(void) __attribute__ ((ISR));
void IRQ7(void) __attribute__ ((ISR));
#endif

void BREAK(void)
{
    //add your code here

}

#if 0
void FIQ(void)
{
    //add your code here

}
#endif

void IRQ0(void)
{
    //add your code here

}

void IRQ1(void)
{
    //add your code here

}

#if 0
void IRQ2(void)
{
    //add your code here

}
#endif

void IRQ3(void)
{
    //add your code here

}

void IRQ4(void)
{
    //add your code here

}

void IRQ5(void)
{
    //add your code here

}

#if 0
void IRQ6(void)
{
    //add your code here

}


void IRQ7(void)
{
    //add your code here

}
#endif

// Interrupt
void IRQ2(void) __attribute__ ((ISR)); // Timer C
void IRQ2(void)
{
    sbi_m(P_INT_Status, C_IRQ2_TMC);
}

void ISR_IRQ2(void)
{

}

void IRQ6(void) __attribute__ ((ISR));
void IRQ6(void)
{
    System_ServiceLoop();

    if(tstb_m(P_INT_Status, C_IRQ6_4096Hz))
    {
        //timer_isr();

        sbi_m(P_INT_Status, C_IRQ6_4096Hz);
    }
}

void IRQ7(void) __attribute__ ((ISR));
void IRQ7(void)
{
    System_ServiceLoop();

    if(tstb_m(P_INT_Status, C_IRQ7_2Hz))
    {
        sbi_m(P_INT_Status, C_IRQ7_2Hz);
    }

    if(tstb_m(P_INT_Status, C_IRQ7_64Hz))
    {
        sbi_m(P_INT_Status, C_IRQ7_64Hz);
    }
}

