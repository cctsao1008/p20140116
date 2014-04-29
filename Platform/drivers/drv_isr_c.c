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
#include "drv_isr.h"

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

uint32_t _count = 0, _sec = 0;

sll* isr7_timer_list = NULL;
sll* isr2_cbfun_list = NULL;

HANDLE
timer_create(uint32_t ms)
{
    uint32_t* count = (uint32_t*)malloc(sizeof(uint32_t));

    if( NULL == count)
        return NULL;

    *count = (ms / IRQ_PERIOD_MS) ;

    if(NULL == isr7_timer_list)
        isr7_timer_list = sll_create();

    sll_insert_node(isr7_timer_list, NULL, (void*)count);

    return (HANDLE)(isr7_timer_list->head);
}

uint16_t
timer_expired(HANDLE h, uint32_t ms)
{
    sll_node* node = (sll_node*) h;

    if(NULL == node)
        return 0;

    if(*((uint32_t*)node->data) == 0)
    {
        if(ms != 0)
            *((uint32_t*)node->data) = (ms / IRQ_PERIOD_MS);

        return 1;
    }

    return 0;
}

void timer_performer(sll* list, sll_node* node)
{
    if( 0 != (*((uint32_t*)node->data)))
        (*((uint32_t*)node->data))-- ;
}

HANDLE
cbfun_create(cbfun callback)
{
    if( NULL == callback)
        return NULL;


    if(NULL == isr2_cbfun_list)
        isr2_cbfun_list = sll_create();

    sll_insert_node(isr2_cbfun_list, NULL, (void*)callback);

    return (HANDLE)(isr2_cbfun_list->head);
}

void
cbfun_performer(sll* list, sll_node* node)
{
    ((cbfun)node->data)();
}

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
void ISR2(void)
{
    sll_foreach(isr2_cbfun_list, cbfun_performer);
}

void IRQ2(void) __attribute__ ((ISR)); // Timer C
void IRQ2(void)
{
    sbi_m(P_INT_Status, C_IRQ2_TMC);
    ISR2();
}

void IRQ6(void) __attribute__ ((ISR));
void IRQ6(void)
{
    if(tstb_m(P_INT_Status, C_IRQ6_4096Hz))
    {
        sbi_m(P_INT_Status, C_IRQ6_4096Hz);
    }
}

void IRQ7(void) __attribute__ ((ISR));
void IRQ7(void)
{
    if(tstb_m(P_INT_Status, C_IRQ7_2Hz))
    {
        sbi_m(P_INT_Status, C_IRQ7_2Hz);

        if(_count++ % 2)
            _sec++;

        reset_watch_dog();
    }

    if(tstb_m(P_INT_Status, C_IRQ7_64Hz))
    {
        sbi_m(P_INT_Status, C_IRQ7_64Hz);

        sll_foreach(isr7_timer_list, timer_performer);
    }
}

