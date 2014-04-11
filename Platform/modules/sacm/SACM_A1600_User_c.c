#include "platform.h"

extern ringBufS rb;
uint32_t addr = 0x64;
uint8_t j = 0;
void USER_A1600_GetData(unsigned int *decode_buffer_address,unsigned int decode_buffer_data_length)
{
    uint32_t i;
    uint8_t dl, dh;
    uint8_t buff[2];

    j++;

    if(j > 2)
        j = j;
    
    reset_watch_dog();
    
    for(i = 0 ; i < decode_buffer_data_length ; i++)
    {
    	if(ringBufS_empty(&rb))
        {
        	mtd_read_data((uint32_t)addr, (uint8_t *)&buff, 2);
        	ringBufS_put(&rb, buff[0]);
            ringBufS_put(&rb, buff[1]);
            addr = addr + 2;
            //return;
        }

        dh = (uint8_t)ringBufS_get(&rb);
        dl = (uint8_t)ringBufS_get(&rb);
        *(decode_buffer_address++) = (uint16_t)(dl << 8) | dh;
    }
    j--;
    //vTaskSwitchContext();
    #if 0
	int i=0;
	unsigned int data,dataL,dataR;
	for(i=0;i<decode_buffer_data_length;i++)
	{
		data=SPI_READ_WORD();
		dataL=(data<<8);
		dataR=(data>>8);
		data=dataL|dataR;
		*(decode_buffer_address++)=data;
		//MX25_READ(FlashAdd,(unsigned int*)decode_buffer_address,decode_buffer_data_length);
	}
	//FlashAdd+=decode_buffer_data_length*2;
    #endif
}
void USER_A1600_SetStartAddr(unsigned AddrLow, unsigned AddrHigh)
{
    #if 0
	MX25_SET_START_ADDRESS(SetStartAddr);
	//FlashAdd=SetStartAddr;
    #endif
}

