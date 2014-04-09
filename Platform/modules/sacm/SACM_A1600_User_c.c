#include "SACM.h"
void USER_A1600_GetData(unsigned int *decode_buffer_address,unsigned int decode_buffer_data_length)
{
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
void USER_A1600_SetStartAddr(unsigned long SetStartAddr)
{
    #if 0
	MX25_SET_START_ADDRESS(SetStartAddr);
	//FlashAdd=SetStartAddr;
    #endif
}

