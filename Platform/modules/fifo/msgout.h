#ifndef MSGOUT_H_
#define MSGOUT_H_
#include "platform.h"

typedef void (*puc_path)(char c);   /* Pointer to the output stream */

typedef enum {
    PATH_LCD = 0,
    PATH_UART,
} OUT_PATH;

uint8_t msgout_fifo_config(uint16_t size);
void msgout_path_config( OUT_PATH path );
void msgout_putc( char c );
void msgout_service(void);

#endif /* MSGOUT_H_ */
