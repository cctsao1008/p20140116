#include "msgout.h"

#if defined(DEBUG_MSG_OUTPUT_LCD)
 #define _putch(c) lcd7735_putc(c);
#elif defined(DEBUG_MSG_OUTPUT_UART)
 #define _putch(c) soft_uart_putc(c);
#endif

#if defined(DEBUG_MSG_OUTPUT_LCD)
puc_path _puc_path = lcd7735_putc;
#elif defined(DEBUG_MSG_OUTPUT_UART)
puc_path _puc_path = soft_uart_putc;
#endif

static ringbuf* rb;

#if 0
void _putch(char c)
{
#if defined(DEBUG_MSG_OUTPUT_LCD)
    lcd7735_putc(c);
#elif defined(DEBUG_MSG_OUTPUT_UART)
    soft_uart_putc(c);
#endif
}
#endif

uint8_t msgout_fifo_config(uint16_t size)
{
    if(NULL != rb) // rb already configured.
        return 0;

    rb = rb_create(size);

    if(NULL == rb)
        return 0;
    
    return 1;
}

void msgout_path_config( OUT_PATH path )
{
    if(PATH_LCD == path)
        _puc_path = lcd7735_putc;
    else if (PATH_UART == path)
        _puc_path = soft_uart_putc;
}

void msgout_putc( char c )
{
#ifndef NO_DEBUG_MSG_OUTPUT
    if(NULL == rb)
        _puc_path(c);

    if(!rb_full(rb))
        rb_write(rb, (uint16_t)c);
#endif
}

void msgout_service()
{
#ifndef NO_DEBUG_MSG_OUTPUT
    uint16_t c, count = 2;

    if(NULL == rb)
        return;
    
    while(!rb_empty(rb) && (0 < count--))
    {
        rb_read(rb, &c);
        _puc_path(c);
    }
#endif
}
