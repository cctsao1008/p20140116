/*********************************************************************
 * Platform/modules/fifo/rb.c
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *      This module performs Ring Buffer (RB) functionality.
 *
 *********************************************************************/
#include "rb.h"

ringbuf*
rb_create(uint16_t size){
    ringbuf *this = (ringbuf*)malloc(sizeof(ringbuf));

    if(NULL == this)
        return NULL;

    //allocate memory space for data
    this->data = (uint16_t*)malloc((this->size) * sizeof(uint16_t));

    if(NULL == this->data)
    {
        free(this);
        return NULL;
    }

    this->size = size;
    this->head = this->tail = 0;
    this->r_count = this->w_count = 0;

    //initialize data to all zeros
    bzero(this->data, sizeof(this->data));

    return this;
}

void
rb_destroy(ringbuf* this){
    if(this->data){
        free(this->data);
        //this->data = NULL;
    }

    if(this)
        free(this);

    //this->size = this->head = this->tail = 0;
    //this->r_count = this->w_count = 0;
}

int
rb_full(const ringbuf* this){
    return (this->w_count - this->r_count) == (int) this->size;
}

int
rb_empty(const ringbuf* this){
    return (this->r_count - this->w_count) == 0;
}

void
rb_write(ringbuf* this, const uint16_t data){
    this->data[this->tail] = data; //write data to buffer

    //update new write position
    this->tail = (this->tail + 1) % this->size;
    this->w_count = (this->w_count + 1) % this->size;
    
    //overwrite data if tail reaches head
    if(this->head == this->tail)
        this->head = (this->head + 1) & this->size;
}

void
rb_read(ringbuf* this, uint16_t* data){
    *data = this->data[this->head]; //get data from head
    //update head to next oldest data in buffer
    this->head= (this->head + 1) % this->size;

    this->r_count = (this->r_count + 1) % this->size;
}

void
rb_test(void)
{
    ringbuf* rb = rb_create(6);
    uint16_t i = 0;

    if(NULL == rb)
    {
        printf("no more heap!\n");
        return;
    }

    while(rb_full(rb))
        rb_write(rb, i++);

    printf("rb full!\n");

    while(rb_empty(rb))
        rb_read(rb, &i);

    printf("buffer empty!\n");

    return;
}

