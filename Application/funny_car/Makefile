#####################################################################
#																	 
#	Created by u'nSP IDE V3.0.8		13:52:04	04/17/14
#
#####################################################################




APPDIR	= C:\PROGRA~2\GENERA~1\UNSPID~1.8

OUTDIR	= .\Debug

CC	= $(APPDIR)\toolchain\gcc

AS	= $(APPDIR)\toolchain\xasm16

LD	= $(APPDIR)\toolchain\xlink16

AR	= $(APPDIR)\toolchain\xlib16

RESC	= $(APPDIR)\toolchain\resc

RM	= $(APPDIR)\toolchain\rm -f

INCLUDES	= -I"D:/funny_car/p20140116/Application/funny_car" -I"C:/Program Files (x86)/Generalplus/unSPIDE 3.0.8/library/include" -I"C:/Program Files (x86)/Generalplus/unSPIDE 3.0.8/library/include/sys" -I"../../Application/include" -I"../../Platform/include" -I"../../Platform/modules/pff/src" -I"../../Platform/drivers" -I"../../Platform/modules/freertos/source/include" -I"../../Platform/modules/freertos/source/portable/GCC/unsp_isa_v13" -I"../../Platform/modules/hash" -I"../../Platform/modules/printf" -I"../../Platform/modules/sfat" -I"../../Platform/modules/sacm" -I"../../Platform/modules/rinbufs" -I"../../Platform/modules/xprintf"

BODY	= -body GPCE2P064A -nobdy -bfile "D:\funny_car\p20140116\Application\funny_car\funny_car.bdy"

BODYFILE	= "D:\funny_car\p20140116\Application\funny_car\funny_car.bdy" 

BINFILE	= "$(OUTDIR)\funny_car.S37"

BINFILENOEXT	= $(OUTDIR)\funny_car

ARYFILE	= "$(OUTDIR)\funny_car.ary"

SBMFILE	= "$(OUTDIR)\funny_car.sbm"

OPT	= -S -Wall -gstabs -mglobal-var-iram

ASFLAGS	= -t5  -sr -d

CASFLAGS	= -t5  -sr -wpop

CFLAGS	= $(OPT) -B$(APPDIR)\toolchain\ $(INCLUDES) 

BINTYPE	= -as

LDFLAGS	=  -blank 0x00 -infblk "D:\funny_car\p20140116\Application\funny_car\funny_car.inb" -conf "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\Body\GPCE\GPCE2P064A\Checksum\GPCE2P064A.cks"

EXTRAFLAGS	= 


OBJFILES	= \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\drv_i2c.obj" \
	"$(OUTDIR)\drv_lcd.obj" \
	"$(OUTDIR)\drv_mtd.obj" \
	"$(OUTDIR)\drv_spi.obj" \
	"$(OUTDIR)\drv_uart.obj" \
	"$(OUTDIR)\SPI_Flash_CE063.obj" \
	"$(OUTDIR)\drv_gpio.obj" \
	"$(OUTDIR)\mmcbb.obj" \
	"$(OUTDIR)\pff.obj" \
	"$(OUTDIR)\port_a.obj" \
	"$(OUTDIR)\port_c.obj" \
	"$(OUTDIR)\heap_3.obj" \
	"$(OUTDIR)\croutine.obj" \
	"$(OUTDIR)\list.obj" \
	"$(OUTDIR)\queue.obj" \
	"$(OUTDIR)\tasks.obj" \
	"$(OUTDIR)\crc.obj" \
	"$(OUTDIR)\sfat.obj" \
	"$(OUTDIR)\printf.obj" \
	"$(OUTDIR)\SACM_A1600_User_a.obj" \
	"$(OUTDIR)\SACM_A1600_User_c.obj" \
	"$(OUTDIR)\modulo.obj" \
	"$(OUTDIR)\ringBufS.obj" \
	"$(OUTDIR)\main.obj" \
	"$(OUTDIR)\System.obj" \
	"$(OUTDIR)\isr_c.obj" \
	"$(OUTDIR)\isr_a.obj" \
	"$(OUTDIR)\ParTest.obj" 

"$(OUTDIR)\Resource.obj": "D:\funny_car\p20140116\Application\funny_car\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)\Resource.obj" "D:\funny_car\p20140116\Application\funny_car\Resource.asm" 

"$(OUTDIR)\drv_i2c.asm": "D:\funny_car\p20140116\Platform\drivers\drv_i2c.c" "D:\funny_car\p20140116\Platform\drivers\drv_i2c.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "D:\funny_car\p20140116\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/drv_i2c.asm" "D:/funny_car/p20140116/Platform/drivers/drv_i2c.c" 

"$(OUTDIR)\drv_i2c.obj": "$(OUTDIR)\drv_i2c.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\drv_i2c.obj" "$(OUTDIR)\drv_i2c.asm" 

"$(OUTDIR)\drv_lcd.asm": "D:\funny_car\p20140116\Platform\drivers\drv_lcd.c" "D:\funny_car\p20140116\Platform\drivers\drv_lcd.h" "D:\funny_car\p20140116\Platform\drivers\drv_spi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "D:\funny_car\p20140116\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/drv_lcd.asm" "D:/funny_car/p20140116/Platform/drivers/drv_lcd.c" 

"$(OUTDIR)\drv_lcd.obj": "$(OUTDIR)\drv_lcd.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\drv_lcd.obj" "$(OUTDIR)\drv_lcd.asm" 

"$(OUTDIR)\drv_mtd.asm": "D:\funny_car\p20140116\Platform\drivers\drv_mtd.c" "D:\funny_car\p20140116\Platform\drivers\drv_mtd.h" "D:\funny_car\p20140116\Platform\drivers\drv_spi.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "D:\funny_car\p20140116\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/drv_mtd.asm" "D:/funny_car/p20140116/Platform/drivers/drv_mtd.c" 

"$(OUTDIR)\drv_mtd.obj": "$(OUTDIR)\drv_mtd.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\drv_mtd.obj" "$(OUTDIR)\drv_mtd.asm" 

"$(OUTDIR)\drv_spi.asm": "D:\funny_car\p20140116\Platform\drivers\drv_spi.c" "D:\funny_car\p20140116\Platform\drivers\drv_spi.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "D:\funny_car\p20140116\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/drv_spi.asm" "D:/funny_car/p20140116/Platform/drivers/drv_spi.c" 

"$(OUTDIR)\drv_spi.obj": "$(OUTDIR)\drv_spi.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\drv_spi.obj" "$(OUTDIR)\drv_spi.asm" 

"$(OUTDIR)\drv_uart.asm": "D:\funny_car\p20140116\Platform\drivers\drv_uart.c" "D:\funny_car\p20140116\Platform\drivers\drv_uart.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdio.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "D:\funny_car\p20140116\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116\Platform\modules\pff\src\integer.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/drv_uart.asm" "D:/funny_car/p20140116/Platform/drivers/drv_uart.c" 

"$(OUTDIR)\drv_uart.obj": "$(OUTDIR)\drv_uart.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\drv_uart.obj" "$(OUTDIR)\drv_uart.asm" 

"$(OUTDIR)\SPI_Flash_CE063.obj": "D:\funny_car\p20140116\Platform\drivers\SPI_Flash_CE063.asm" "..\..\Platform\include\GPCE206x.inc" 
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)\SPI_Flash_CE063.obj" "D:\funny_car\p20140116\Platform\drivers\SPI_Flash_CE063.asm" 

"$(OUTDIR)\drv_gpio.asm": "D:\funny_car\p20140116\Platform\drivers\drv_gpio.c" "D:\funny_car\p20140116\Platform\drivers\drv_gpio.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "D:\funny_car\p20140116\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/drv_gpio.asm" "D:/funny_car/p20140116/Platform/drivers/drv_gpio.c" 

"$(OUTDIR)\drv_gpio.obj": "$(OUTDIR)\drv_gpio.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\drv_gpio.obj" "$(OUTDIR)\drv_gpio.asm" 

"$(OUTDIR)\mmcbb.asm": "D:\funny_car\p20140116\Platform\modules\pff\src\mmcbb.c" "D:\funny_car\p20140116\Platform\modules\pff\src\diskio.h" "D:\funny_car\p20140116\Platform\modules\pff\src\integer.h" "D:\funny_car\p20140116\Platform\modules\pff\src\pff.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "D:\funny_car\p20140116\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" "..\..\Platform\drivers\drv_spi.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/mmcbb.asm" "D:/funny_car/p20140116/Platform/modules/pff/src/mmcbb.c" 

"$(OUTDIR)\mmcbb.obj": "$(OUTDIR)\mmcbb.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\mmcbb.obj" "$(OUTDIR)\mmcbb.asm" 

"$(OUTDIR)\pff.asm": "D:\funny_car\p20140116\Platform\modules\pff\src\pff.c" "D:\funny_car\p20140116\Platform\modules\pff\src\pff.h" "D:\funny_car\p20140116\Platform\modules\pff\src\diskio.h" "D:\funny_car\p20140116\Platform\modules\pff\src\integer.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/pff.asm" "D:/funny_car/p20140116/Platform/modules/pff/src/pff.c" 

"$(OUTDIR)\pff.obj": "$(OUTDIR)\pff.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\pff.obj" "$(OUTDIR)\pff.asm" 

"$(OUTDIR)\port_a.obj": "D:\funny_car\p20140116\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\port_a.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)\port_a.obj" "D:\funny_car\p20140116\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\port_a.asm" 

"$(OUTDIR)\port_c.asm": "D:\funny_car\p20140116\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\port_c.c" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" "..\..\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "..\..\Platform\modules\freertos\source\include\task.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "D:\funny_car\p20140116\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/port_c.asm" "D:/funny_car/p20140116/Platform/modules/freertos/source/portable/GCC/unsp_isa_v13/port_c.c" 

"$(OUTDIR)\port_c.obj": "$(OUTDIR)\port_c.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\port_c.obj" "$(OUTDIR)\port_c.asm" 

"$(OUTDIR)\heap_3.asm": "D:\funny_car\p20140116\Platform\modules\freertos\source\portable\MemMang\heap_3.c" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "..\..\Platform\modules\freertos\source\include\task.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/heap_3.asm" "D:/funny_car/p20140116/Platform/modules/freertos/source/portable/MemMang/heap_3.c" 

"$(OUTDIR)\heap_3.obj": "$(OUTDIR)\heap_3.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\heap_3.obj" "$(OUTDIR)\heap_3.asm" 

"$(OUTDIR)\croutine.asm": "D:\funny_car\p20140116\Platform\modules\freertos\source\croutine.c" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" "..\..\Platform\modules\freertos\source\include\task.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "..\..\Platform\modules\freertos\source\include\croutine.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/croutine.asm" "D:/funny_car/p20140116/Platform/modules/freertos/source/croutine.c" 

"$(OUTDIR)\croutine.obj": "$(OUTDIR)\croutine.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\croutine.obj" "$(OUTDIR)\croutine.asm" 

"$(OUTDIR)\list.asm": "D:\funny_car\p20140116\Platform\modules\freertos\source\list.c" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "..\..\Platform\modules\freertos\source\include\list.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/list.asm" "D:/funny_car/p20140116/Platform/modules/freertos/source/list.c" 

"$(OUTDIR)\list.obj": "$(OUTDIR)\list.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\list.obj" "$(OUTDIR)\list.asm" 

"$(OUTDIR)\queue.asm": "D:\funny_car\p20140116\Platform\modules\freertos\source\queue.c" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "..\..\Platform\modules\freertos\source\include\task.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "..\..\Platform\modules\freertos\source\include\queue.h" "..\..\Platform\modules\freertos\source\include\croutine.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/queue.asm" "D:/funny_car/p20140116/Platform/modules/freertos/source/queue.c" 

"$(OUTDIR)\queue.obj": "$(OUTDIR)\queue.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\queue.obj" "$(OUTDIR)\queue.asm" 

"$(OUTDIR)\tasks.asm": "D:\funny_car\p20140116\Platform\modules\freertos\source\tasks.c" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "..\..\Platform\modules\freertos\source\include\task.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "..\..\Platform\modules\freertos\source\include\timers.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\StackMacros.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdio.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/tasks.asm" "D:/funny_car/p20140116/Platform/modules/freertos/source/tasks.c" 

"$(OUTDIR)\tasks.obj": "$(OUTDIR)\tasks.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\tasks.obj" "$(OUTDIR)\tasks.asm" 

"$(OUTDIR)\crc.asm": "D:\funny_car\p20140116\Platform\modules\hash\crc.c" "D:\funny_car\p20140116\Platform\modules\hash\crc.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "D:\funny_car\p20140116\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/crc.asm" "D:/funny_car/p20140116/Platform/modules/hash/crc.c" 

"$(OUTDIR)\crc.obj": "$(OUTDIR)\crc.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\crc.obj" "$(OUTDIR)\crc.asm" 

"$(OUTDIR)\sfat.asm": "D:\funny_car\p20140116\Platform\modules\sfat\sfat.c" "D:\funny_car\p20140116\Platform\modules\sfat\sfat.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "D:\funny_car\p20140116\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/sfat.asm" "D:/funny_car/p20140116/Platform/modules/sfat/sfat.c" 

"$(OUTDIR)\sfat.obj": "$(OUTDIR)\sfat.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\sfat.obj" "$(OUTDIR)\sfat.asm" 

"$(OUTDIR)\printf.asm": "D:\funny_car\p20140116\Platform\modules\printf\printf.c" "D:\funny_car\p20140116\Platform\modules\printf\printf.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/printf.asm" "D:/funny_car/p20140116/Platform/modules/printf/printf.c" 

"$(OUTDIR)\printf.obj": "$(OUTDIR)\printf.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\printf.obj" "$(OUTDIR)\printf.asm" 

"$(OUTDIR)\SACM_A1600_User_a.obj": "D:\funny_car\p20140116\Platform\modules\sacm\SACM_A1600_User_a.asm" "..\..\Platform\include\GPCE206x.inc" "A1600.inc" 
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)\SACM_A1600_User_a.obj" "D:\funny_car\p20140116\Platform\modules\sacm\SACM_A1600_User_a.asm" 

"$(OUTDIR)\SACM_A1600_User_c.asm": "D:\funny_car\p20140116\Platform\modules\sacm\SACM_A1600_User_c.c" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "D:\funny_car\p20140116\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/SACM_A1600_User_c.asm" "D:/funny_car/p20140116/Platform/modules/sacm/SACM_A1600_User_c.c" 

"$(OUTDIR)\SACM_A1600_User_c.obj": "$(OUTDIR)\SACM_A1600_User_c.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\SACM_A1600_User_c.obj" "$(OUTDIR)\SACM_A1600_User_c.asm" 

"$(OUTDIR)\modulo.asm": "D:\funny_car\p20140116\Platform\modules\rinbufs\modulo.c" "D:\funny_car\p20140116\Platform\modules\rinbufs\modulo.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/modulo.asm" "D:/funny_car/p20140116/Platform/modules/rinbufs/modulo.c" 

"$(OUTDIR)\modulo.obj": "$(OUTDIR)\modulo.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\modulo.obj" "$(OUTDIR)\modulo.asm" 

"$(OUTDIR)\ringBufS.asm": "D:\funny_car\p20140116\Platform\modules\rinbufs\ringBufS.c" "D:\funny_car\p20140116\Platform\modules\rinbufs\modulo.h" "D:\funny_car\p20140116\Platform\modules\rinbufs\ringBufS.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "D:\funny_car\p20140116\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/ringBufS.asm" "D:/funny_car/p20140116/Platform/modules/rinbufs/ringBufS.c" 

"$(OUTDIR)\ringBufS.obj": "$(OUTDIR)\ringBufS.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\ringBufS.obj" "$(OUTDIR)\ringBufS.asm" 

"$(OUTDIR)\main.asm": "D:\funny_car\p20140116\Application\funny_car\main.c" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "D:\funny_car\p20140116\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/main.asm" "D:/funny_car/p20140116/Application/funny_car/main.c" 

"$(OUTDIR)\main.obj": "$(OUTDIR)\main.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\main.obj" "$(OUTDIR)\main.asm" 

"$(OUTDIR)\System.obj": "D:\funny_car\p20140116\Application\funny_car\System.asm" "..\..\Platform\include\GPCE206x.inc" 
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)\System.obj" "D:\funny_car\p20140116\Application\funny_car\System.asm" 

"$(OUTDIR)\isr_c.asm": "D:\funny_car\p20140116\Application\funny_car\isr_c.c" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/isr_c.asm" "D:/funny_car/p20140116/Application/funny_car/isr_c.c" 

"$(OUTDIR)\isr_c.obj": "$(OUTDIR)\isr_c.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\isr_c.obj" "$(OUTDIR)\isr_c.asm" 

"$(OUTDIR)\isr_a.obj": "D:\funny_car\p20140116\Application\funny_car\isr_a.asm" ".\A1600.inc" "..\..\Platform\include\GPCE206x.inc" 
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)\isr_a.obj" "D:\funny_car\p20140116\Application\funny_car\isr_a.asm" 

"$(OUTDIR)\ParTest.asm": "D:\funny_car\p20140116\Application\ParTest\ParTest.c" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" "..\..\Platform\modules\freertos\source\include\task.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "D:\funny_car\p20140116\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/ParTest.asm" "D:/funny_car/p20140116/Application/ParTest/ParTest.c" 

"$(OUTDIR)\ParTest.obj": "$(OUTDIR)\ParTest.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\ParTest.obj" "$(OUTDIR)\ParTest.asm" 


.SUFFIXES : .c .asm .obj .s37 .tsk .res

all :	 BEFOREBUILD "$(OUTDIR)" $(BINFILE)

BEFOREBUILD :

"$(OUTDIR)" :
	if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

$(BINFILE) : $(OBJFILES) 
	$(LD) $(BINTYPE) $(ARYFILE) $(BINFILE) $(LDFLAGS) $(BODY) $(EXTRAFLAGS)

compile :	 $(OBJFILES)

clean :
	$(RM) "$(OUTDIR)\Resource.obj" 
	$(RM) "$(OUTDIR)\Resource.lst" 
	$(RM) "$(OUTDIR)\drv_i2c.obj" 
	$(RM) "$(OUTDIR)\drv_i2c.lst" 
	$(RM) "$(OUTDIR)\drv_i2c.asm" 
	$(RM) "$(OUTDIR)\drv_lcd.obj" 
	$(RM) "$(OUTDIR)\drv_lcd.lst" 
	$(RM) "$(OUTDIR)\drv_lcd.asm" 
	$(RM) "$(OUTDIR)\drv_mtd.obj" 
	$(RM) "$(OUTDIR)\drv_mtd.lst" 
	$(RM) "$(OUTDIR)\drv_mtd.asm" 
	$(RM) "$(OUTDIR)\drv_spi.obj" 
	$(RM) "$(OUTDIR)\drv_spi.lst" 
	$(RM) "$(OUTDIR)\drv_spi.asm" 
	$(RM) "$(OUTDIR)\drv_uart.obj" 
	$(RM) "$(OUTDIR)\drv_uart.lst" 
	$(RM) "$(OUTDIR)\drv_uart.asm" 
	$(RM) "$(OUTDIR)\SPI_Flash_CE063.obj" 
	$(RM) "$(OUTDIR)\SPI_Flash_CE063.lst" 
	$(RM) "$(OUTDIR)\drv_gpio.obj" 
	$(RM) "$(OUTDIR)\drv_gpio.lst" 
	$(RM) "$(OUTDIR)\drv_gpio.asm" 
	$(RM) "$(OUTDIR)\mmcbb.obj" 
	$(RM) "$(OUTDIR)\mmcbb.lst" 
	$(RM) "$(OUTDIR)\mmcbb.asm" 
	$(RM) "$(OUTDIR)\pff.obj" 
	$(RM) "$(OUTDIR)\pff.lst" 
	$(RM) "$(OUTDIR)\pff.asm" 
	$(RM) "$(OUTDIR)\port_a.obj" 
	$(RM) "$(OUTDIR)\port_a.lst" 
	$(RM) "$(OUTDIR)\port_c.obj" 
	$(RM) "$(OUTDIR)\port_c.lst" 
	$(RM) "$(OUTDIR)\port_c.asm" 
	$(RM) "$(OUTDIR)\heap_3.obj" 
	$(RM) "$(OUTDIR)\heap_3.lst" 
	$(RM) "$(OUTDIR)\heap_3.asm" 
	$(RM) "$(OUTDIR)\croutine.obj" 
	$(RM) "$(OUTDIR)\croutine.lst" 
	$(RM) "$(OUTDIR)\croutine.asm" 
	$(RM) "$(OUTDIR)\list.obj" 
	$(RM) "$(OUTDIR)\list.lst" 
	$(RM) "$(OUTDIR)\list.asm" 
	$(RM) "$(OUTDIR)\queue.obj" 
	$(RM) "$(OUTDIR)\queue.lst" 
	$(RM) "$(OUTDIR)\queue.asm" 
	$(RM) "$(OUTDIR)\tasks.obj" 
	$(RM) "$(OUTDIR)\tasks.lst" 
	$(RM) "$(OUTDIR)\tasks.asm" 
	$(RM) "$(OUTDIR)\crc.obj" 
	$(RM) "$(OUTDIR)\crc.lst" 
	$(RM) "$(OUTDIR)\crc.asm" 
	$(RM) "$(OUTDIR)\sfat.obj" 
	$(RM) "$(OUTDIR)\sfat.lst" 
	$(RM) "$(OUTDIR)\sfat.asm" 
	$(RM) "$(OUTDIR)\printf.obj" 
	$(RM) "$(OUTDIR)\printf.lst" 
	$(RM) "$(OUTDIR)\printf.asm" 
	$(RM) "$(OUTDIR)\SACM_A1600_User_a.obj" 
	$(RM) "$(OUTDIR)\SACM_A1600_User_a.lst" 
	$(RM) "$(OUTDIR)\SACM_A1600_User_c.obj" 
	$(RM) "$(OUTDIR)\SACM_A1600_User_c.lst" 
	$(RM) "$(OUTDIR)\SACM_A1600_User_c.asm" 
	$(RM) "$(OUTDIR)\modulo.obj" 
	$(RM) "$(OUTDIR)\modulo.lst" 
	$(RM) "$(OUTDIR)\modulo.asm" 
	$(RM) "$(OUTDIR)\ringBufS.obj" 
	$(RM) "$(OUTDIR)\ringBufS.lst" 
	$(RM) "$(OUTDIR)\ringBufS.asm" 
	$(RM) "$(OUTDIR)\main.obj" 
	$(RM) "$(OUTDIR)\main.lst" 
	$(RM) "$(OUTDIR)\main.asm" 
	$(RM) "$(OUTDIR)\System.obj" 
	$(RM) "$(OUTDIR)\System.lst" 
	$(RM) "$(OUTDIR)\isr_c.obj" 
	$(RM) "$(OUTDIR)\isr_c.lst" 
	$(RM) "$(OUTDIR)\isr_c.asm" 
	$(RM) "$(OUTDIR)\isr_a.obj" 
	$(RM) "$(OUTDIR)\isr_a.lst" 
	$(RM) "$(OUTDIR)\ParTest.obj" 
	$(RM) "$(OUTDIR)\ParTest.lst" 
	$(RM) "$(OUTDIR)\ParTest.asm" 
	$(RM) "$(BINFILENOEXT).s37" "$(BINFILENOEXT).tsk" "$(BINFILENOEXT).hdb" $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

