/*********************************************************************
 * Platform/modules/fifo/rb.h
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *      This module performs Ring Buffer (RB) functionality.
 *
 *********************************************************************/
#ifndef RB_H_
#define RB_H_
#include "platform.h"

//Ring Buffer object
typedef struct{
    unsigned int size;//size of buffer
    unsigned int head; //index to oldest data in buffer
    unsigned int tail; //index to next write position
    
    //these counters are used to check if the buffer is full and empty
    //if read_count - write count = 0, the buffer is empty
    //if write_count - read_count = length, the buffer is full
    int r_count; //number of reads performed
    int w_count; //number of writes performed
    
    uint16_t* data; //data for buffer
}ringbuf;

//Initialize RingBuffer
ringbuf*
rb_create(uint16_t size);

//destroys ringbuffer and resets all its values
void
rb_destroy(ringbuf* buf);

//check if RingBuffer is full
int
rb_full(const ringbuf* buf);

//check if RingBuffer is empty
int
rb_empty(const ringbuf* buf);

//write data to the RingBuffer
void
rb_write(ringbuf* buf, const uint16_t data);

//read data from the RingBuffer
void
rb_read(ringbuf* buf, uint16_t* data);

void
rb_test(void);

#endif /* RB_H_ */
