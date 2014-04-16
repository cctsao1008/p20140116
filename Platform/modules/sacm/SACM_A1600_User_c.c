#include "platform.h"

extern ringBufS rb;
extern uint32_t addr;

/*
        dba : decode buffer address
        dbl : decode buffer data length
  */
void USER_A1600_GetData(unsigned int *dba,unsigned int dbl)
{
    uint8_t i = 0, buff[2];
    
    for(i = 0 ; i < dbl ; i++)
    {
        #ifdef USE_RINGBUFS
    	if(ringBufS_empty(&rb))
        {
        	mtd_read_data((uint32_t)addr, (uint8_t *)&buff, 2);
        	ringBufS_put(&rb, buff[0]);
            ringBufS_put(&rb, buff[1]);
            addr = addr + 2;
        }

        buff[1] = (uint8_t)ringBufS_get(&rb);
        buff[0] = (uint8_t)ringBufS_get(&rb);
        *(dba++) = (uint16_t)(buff[1] << 8) | buff[0];
        #else
        mtd_read_data((uint32_t)addr, (uint8_t *)&buff, 2);
        addr = addr + 2;
        *(dba++) = (uint16_t)(buff[1] << 8) | buff[0];
        #endif
    }
}

void USER_A1600_SetStartAddr(unsigned AddrLow, unsigned AddrHigh)
{

}

