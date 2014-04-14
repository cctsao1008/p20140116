#define MMC_CS PIN_A5

int mmc_response(unsigned char response)
{
   unsigned long count = 0x0FFF;
   while (spi_read(0xFF) != response && --count > 0);
   
   if (count == 0)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

char mmc_open_block(int32 block_number)
{
   int8 addr[4];
   
   output_low(MMC_CS);

   block_number *= 512;
   addr[0] = MAKE8(block_number, 3);
   addr[1] = MAKE8(block_number, 2);
   addr[2] = MAKE8(block_number, 1);
   addr[3] = MAKE8(block_number, 0);
   
   SPI_WRITE(0x51);
   SPI_WRITE(addr[0]);
   SPI_WRITE(addr[1]);
   SPI_WRITE(addr[2]);
   SPI_WRITE(addr[3]);
   SPI_WRITE(0xFF);
   
   if((mmc_response(0x00))==1) return 1;
   if((mmc_response(0xFE))==1) return 1;
   
   return 0;
}

void mmc_close_block(void){
   SPI_READ(0xFF);
   SPI_READ(0xFF);
   output_high(MMC_CS);
   SPI_WRITE(0xFF);
}

int mmc_read_block_to_serial(int16 block_number)
{
   unsigned long i;
   unsigned long j;
   
   printf("\r\n");
   mmc_open_block(block_number);
   for (i = 0; i < 32; i++)
   {
      for (j = 0; j < 16; j++)
      {
         printf("%2X ", spi_read(0xFF));
      }
      printf("\r\n");
   }
   mmc_close_block();
   
   return 0;
}

int mmc_init()
{
   int i;
   
   printf("Configuring the SPI module...\r\n");
   setup_spi(SPI_MASTER | SPI_L_TO_H | SPI_XMIT_L_TO_H | SPI_CLK_DIV_4);
   //setup_spi(SPI_MASTER | SPI_L_TO_H | SPI_XMIT_L_TO_H);
   
   printf("Initializing MMC/SD memory card...\r\n");

   output_high(MMC_CS);
   for(i = 0; i < 10; i++)
   {
      spi_write(0xFF);
   }
   output_low(MMC_CS);
   
   spi_write(0x40);
   spi_write(0x00);
   spi_write(0x00);
   spi_write(0x00);
   spi_write(0x00);

   spi_write(0x95);
   
   if (mmc_response(0x01) == 1)
   {
      printf("Timeout (1)!\r\n");
      return 1;
   }

   i = 0;
   while((i < 255) && (mmc_response(0x00) == 1))
   {
      spi_write(0x41);
      spi_write(0x00);
      spi_write(0x00);
      spi_write(0x00);
      spi_write(0x00);
      spi_write(0xFF);
      i++;
   }
   
   if(i >= 254)
   {
      printf("Timeout (2)!\r\n");
      return 1;
   }
   
   output_high(MMC_CS);
   spi_write(0xFF);
   output_low(MMC_CS);

   SPI_WRITE(0x50);
   SPI_WRITE(0x00);
   SPI_WRITE(0x00);
   SPI_WRITE(0x02);
   SPI_WRITE(0x00);
   SPI_WRITE(0xFF);
   
   if((mmc_response(0x00)) == 1)
   {
      printf("Timeout (3)!\r\n");
      return 1;
   }
   
   output_high(MMC_CS);
   
   printf("The MMC/SD memory card has been initialized successfuly.\r\n");
   return 0;
}
