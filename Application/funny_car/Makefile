#####################################################################
#																	 
#	Created by u'nSP IDE V3.0.8		11:48:35	04/22/14
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

INCLUDES	= -I"D:/funny_car/p20140116_test/Application/funny_car" -I"C:/Program Files (x86)/Generalplus/unSPIDE 3.0.8/library/include" -I"C:/Program Files (x86)/Generalplus/unSPIDE 3.0.8/library/include/sys" -I"../../Platform/include" -I"../../Platform/modules/pff/src" -I"../../Platform/drivers" -I"../../Platform/modules/freertos/source/include" -I"../../Platform/modules/freertos/source/portable/GCC/unsp_isa_v13" -I"../../Platform/modules/hash" -I"../../Platform/modules/printf" -I"../../Platform/modules/sfat" -I"../../Platform/modules/sacm" -I"../../Platform/modules/rinbufs" -I"../../Platform/modules/xprintf" -I"../../Platform/modules/rtclib"

BODY	= -body GPCE2P064A -nobdy -bfile "D:\funny_car\p20140116_test\Application\funny_car\funny_car.bdy"

BODYFILE	= "D:\funny_car\p20140116_test\Application\funny_car\funny_car.bdy" 

BINFILE	= "$(OUTDIR)\funny_car.S37"

BINFILENOEXT	= $(OUTDIR)\funny_car

ARYFILE	= "$(OUTDIR)\funny_car.ary"

SBMFILE	= "$(OUTDIR)\funny_car.sbm"

OPT	= -S -Wall -gstabs -mglobal-var-iram

ASFLAGS	= -t5  -sr -d

CASFLAGS	= -t5  -sr -wpop

CFLAGS	= $(OPT) -B$(APPDIR)\toolchain\ $(INCLUDES) 

BINTYPE	= -as

LDFLAGS	=  -blank 0x00 -infblk "D:\funny_car\p20140116_test\Application\funny_car\funny_car.inb" -conf "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\Body\GPCE\GPCE2P064A\Checksum\GPCE2P064A.cks"

EXTRAFLAGS	= 


OBJFILES	= \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\drv_i2c.obj" \
	"$(OUTDIR)\drv_lcd.obj" \
	"$(OUTDIR)\drv_mtd.obj" \
	"$(OUTDIR)\drv_spi.obj" \
	"$(OUTDIR)\drv_uart.obj" \
	"$(OUTDIR)\drv_gpio.obj" \
	"$(OUTDIR)\drv_isr_a.obj" \
	"$(OUTDIR)\drv_isr_c.obj" \
	"$(OUTDIR)\drv_sys.obj" \
	"$(OUTDIR)\mmcbb.obj" \
	"$(OUTDIR)\pff.obj" \
	"$(OUTDIR)\crc.obj" \
	"$(OUTDIR)\sfat.obj" \
	"$(OUTDIR)\printf.obj" \
	"$(OUTDIR)\SACM_A1600_User_a.obj" \
	"$(OUTDIR)\SACM_A1600_User_c.obj" \
	"$(OUTDIR)\modulo.obj" \
	"$(OUTDIR)\ringBufS.obj" \
	"$(OUTDIR)\main.obj" 

"$(OUTDIR)\Resource.obj": "D:\funny_car\p20140116_test\Application\funny_car\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)\Resource.obj" "D:\funny_car\p20140116_test\Application\funny_car\Resource.asm" 

"$(OUTDIR)\drv_i2c.asm": "D:\funny_car\p20140116_test\Platform\drivers\drv_i2c.c" "D:\funny_car\p20140116_test\Platform\drivers\drv_i2c.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116_test\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdbool.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "D:\funny_car\p20140116_test\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\drivers\drv_uart.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "..\..\Platform\modules\rtclib\rtclib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\projdefs.h" "..\..\Platform\include\FreeRTOSConfig.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116_test\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/drv_i2c.asm" "D:/funny_car/p20140116_test/Platform/drivers/drv_i2c.c" 

"$(OUTDIR)\drv_i2c.obj": "$(OUTDIR)\drv_i2c.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\drv_i2c.obj" "$(OUTDIR)\drv_i2c.asm" 

"$(OUTDIR)\drv_lcd.asm": "D:\funny_car\p20140116_test\Platform\drivers\drv_lcd.c" "D:\funny_car\p20140116_test\Platform\drivers\drv_lcd.h" "D:\funny_car\p20140116_test\Platform\drivers\drv_spi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116_test\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdbool.h" "D:\funny_car\p20140116_test\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\drivers\drv_uart.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "..\..\Platform\modules\rtclib\rtclib.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\projdefs.h" "..\..\Platform\include\FreeRTOSConfig.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116_test\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/drv_lcd.asm" "D:/funny_car/p20140116_test/Platform/drivers/drv_lcd.c" 

"$(OUTDIR)\drv_lcd.obj": "$(OUTDIR)\drv_lcd.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\drv_lcd.obj" "$(OUTDIR)\drv_lcd.asm" 

"$(OUTDIR)\drv_mtd.asm": "D:\funny_car\p20140116_test\Platform\drivers\drv_mtd.c" "D:\funny_car\p20140116_test\Platform\drivers\drv_mtd.h" "D:\funny_car\p20140116_test\Platform\drivers\drv_spi.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116_test\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdbool.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "D:\funny_car\p20140116_test\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\drivers\drv_uart.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "..\..\Platform\modules\rtclib\rtclib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\projdefs.h" "..\..\Platform\include\FreeRTOSConfig.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116_test\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/drv_mtd.asm" "D:/funny_car/p20140116_test/Platform/drivers/drv_mtd.c" 

"$(OUTDIR)\drv_mtd.obj": "$(OUTDIR)\drv_mtd.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\drv_mtd.obj" "$(OUTDIR)\drv_mtd.asm" 

"$(OUTDIR)\drv_spi.asm": "D:\funny_car\p20140116_test\Platform\drivers\drv_spi.c" "D:\funny_car\p20140116_test\Platform\drivers\drv_spi.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116_test\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdbool.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "D:\funny_car\p20140116_test\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\drivers\drv_uart.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "..\..\Platform\modules\rtclib\rtclib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\projdefs.h" "..\..\Platform\include\FreeRTOSConfig.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116_test\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/drv_spi.asm" "D:/funny_car/p20140116_test/Platform/drivers/drv_spi.c" 

"$(OUTDIR)\drv_spi.obj": "$(OUTDIR)\drv_spi.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\drv_spi.obj" "$(OUTDIR)\drv_spi.asm" 

"$(OUTDIR)\drv_uart.asm": "D:\funny_car\p20140116_test\Platform\drivers\drv_uart.c" "D:\funny_car\p20140116_test\Platform\drivers\drv_uart.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdio.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116_test\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdbool.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "D:\funny_car\p20140116_test\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\drivers\drv_uart.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "..\..\Platform\modules\rtclib\rtclib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\projdefs.h" "..\..\Platform\include\FreeRTOSConfig.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116_test\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/drv_uart.asm" "D:/funny_car/p20140116_test/Platform/drivers/drv_uart.c" 

"$(OUTDIR)\drv_uart.obj": "$(OUTDIR)\drv_uart.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\drv_uart.obj" "$(OUTDIR)\drv_uart.asm" 

"$(OUTDIR)\drv_gpio.asm": "D:\funny_car\p20140116_test\Platform\drivers\drv_gpio.c" "D:\funny_car\p20140116_test\Platform\drivers\drv_gpio.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116_test\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdbool.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "D:\funny_car\p20140116_test\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\drivers\drv_uart.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "..\..\Platform\modules\rtclib\rtclib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\projdefs.h" "..\..\Platform\include\FreeRTOSConfig.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116_test\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/drv_gpio.asm" "D:/funny_car/p20140116_test/Platform/drivers/drv_gpio.c" 

"$(OUTDIR)\drv_gpio.obj": "$(OUTDIR)\drv_gpio.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\drv_gpio.obj" "$(OUTDIR)\drv_gpio.asm" 

"$(OUTDIR)\drv_isr_a.obj": "D:\funny_car\p20140116\Platform\drivers\drv_isr_a.asm" "..\..\Platform\include\GPCE206x.inc" "..\..\Platform\modules\sacm\A1600.inc" 
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)\drv_isr_a.obj" "D:\funny_car\p20140116\Platform\drivers\drv_isr_a.asm" 

"$(OUTDIR)\drv_isr_c.asm": "D:\funny_car\p20140116\Platform\drivers\drv_isr_c.c" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116_test\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdbool.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "D:\funny_car\p20140116_test\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\drivers\drv_uart.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "..\..\Platform\modules\rtclib\rtclib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\projdefs.h" "..\..\Platform\include\FreeRTOSConfig.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116_test\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/drv_isr_c.asm" "D:/funny_car/p20140116/Platform/drivers/drv_isr_c.c" 

"$(OUTDIR)\drv_isr_c.obj": "$(OUTDIR)\drv_isr_c.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\drv_isr_c.obj" "$(OUTDIR)\drv_isr_c.asm" 

"$(OUTDIR)\drv_sys.obj": "D:\funny_car\p20140116_test\Platform\drivers\drv_sys.asm" "..\..\Platform\include\GPCE206x.inc" 
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)\drv_sys.obj" "D:\funny_car\p20140116_test\Platform\drivers\drv_sys.asm" 

"$(OUTDIR)\mmcbb.asm": "D:\funny_car\p20140116_test\Platform\modules\pff\src\mmcbb.c" "D:\funny_car\p20140116_test\Platform\modules\pff\src\diskio.h" "D:\funny_car\p20140116_test\Platform\modules\pff\src\integer.h" "D:\funny_car\p20140116_test\Platform\modules\pff\src\pff.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116_test\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdbool.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "D:\funny_car\p20140116_test\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\drivers\drv_uart.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "..\..\Platform\modules\rtclib\rtclib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\projdefs.h" "..\..\Platform\include\FreeRTOSConfig.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116_test\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" "..\..\Platform\drivers\drv_spi.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/mmcbb.asm" "D:/funny_car/p20140116_test/Platform/modules/pff/src/mmcbb.c" 

"$(OUTDIR)\mmcbb.obj": "$(OUTDIR)\mmcbb.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\mmcbb.obj" "$(OUTDIR)\mmcbb.asm" 

"$(OUTDIR)\pff.asm": "D:\funny_car\p20140116_test\Platform\modules\pff\src\pff.c" "D:\funny_car\p20140116_test\Platform\modules\pff\src\pff.h" "D:\funny_car\p20140116_test\Platform\modules\pff\src\diskio.h" "D:\funny_car\p20140116_test\Platform\modules\pff\src\integer.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/pff.asm" "D:/funny_car/p20140116_test/Platform/modules/pff/src/pff.c" 

"$(OUTDIR)\pff.obj": "$(OUTDIR)\pff.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\pff.obj" "$(OUTDIR)\pff.asm" 

"$(OUTDIR)\crc.asm": "D:\funny_car\p20140116_test\Platform\modules\hash\crc.c" "D:\funny_car\p20140116_test\Platform\modules\hash\crc.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116_test\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdbool.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "D:\funny_car\p20140116_test\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\drivers\drv_uart.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "..\..\Platform\modules\rtclib\rtclib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\projdefs.h" "..\..\Platform\include\FreeRTOSConfig.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116_test\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/crc.asm" "D:/funny_car/p20140116_test/Platform/modules/hash/crc.c" 

"$(OUTDIR)\crc.obj": "$(OUTDIR)\crc.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\crc.obj" "$(OUTDIR)\crc.asm" 

"$(OUTDIR)\sfat.asm": "D:\funny_car\p20140116_test\Platform\modules\sfat\sfat.c" "D:\funny_car\p20140116_test\Platform\modules\sfat\sfat.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116_test\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdbool.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "D:\funny_car\p20140116_test\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\drivers\drv_uart.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "..\..\Platform\modules\rtclib\rtclib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\projdefs.h" "..\..\Platform\include\FreeRTOSConfig.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116_test\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/sfat.asm" "D:/funny_car/p20140116_test/Platform/modules/sfat/sfat.c" 

"$(OUTDIR)\sfat.obj": "$(OUTDIR)\sfat.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\sfat.obj" "$(OUTDIR)\sfat.asm" 

"$(OUTDIR)\printf.asm": "D:\funny_car\p20140116_test\Platform\modules\printf\printf.c" "D:\funny_car\p20140116_test\Platform\modules\printf\printf.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116_test\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdbool.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "D:\funny_car\p20140116_test\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\drivers\drv_uart.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "..\..\Platform\modules\rtclib\rtclib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\projdefs.h" "..\..\Platform\include\FreeRTOSConfig.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116_test\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/printf.asm" "D:/funny_car/p20140116_test/Platform/modules/printf/printf.c" 

"$(OUTDIR)\printf.obj": "$(OUTDIR)\printf.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\printf.obj" "$(OUTDIR)\printf.asm" 

"$(OUTDIR)\SACM_A1600_User_a.obj": "D:\funny_car\p20140116_test\Platform\modules\sacm\SACM_A1600_User_a.asm" "D:\funny_car\p20140116_test\Platform\modules\sacm\A1600.inc" "..\..\Platform\include\GPCE206x.inc" 
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)\SACM_A1600_User_a.obj" "D:\funny_car\p20140116_test\Platform\modules\sacm\SACM_A1600_User_a.asm" 

"$(OUTDIR)\SACM_A1600_User_c.asm": "D:\funny_car\p20140116_test\Platform\modules\sacm\SACM_A1600_User_c.c" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116_test\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdbool.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "D:\funny_car\p20140116_test\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\drivers\drv_uart.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "..\..\Platform\modules\rtclib\rtclib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\projdefs.h" "..\..\Platform\include\FreeRTOSConfig.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116_test\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/SACM_A1600_User_c.asm" "D:/funny_car/p20140116_test/Platform/modules/sacm/SACM_A1600_User_c.c" 

"$(OUTDIR)\SACM_A1600_User_c.obj": "$(OUTDIR)\SACM_A1600_User_c.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\SACM_A1600_User_c.obj" "$(OUTDIR)\SACM_A1600_User_c.asm" 

"$(OUTDIR)\modulo.asm": "D:\funny_car\p20140116_test\Platform\modules\rinbufs\modulo.c" "D:\funny_car\p20140116_test\Platform\modules\rinbufs\modulo.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/modulo.asm" "D:/funny_car/p20140116_test/Platform/modules/rinbufs/modulo.c" 

"$(OUTDIR)\modulo.obj": "$(OUTDIR)\modulo.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\modulo.obj" "$(OUTDIR)\modulo.asm" 

"$(OUTDIR)\ringBufS.asm": "D:\funny_car\p20140116_test\Platform\modules\rinbufs\ringBufS.c" "D:\funny_car\p20140116_test\Platform\modules\rinbufs\modulo.h" "D:\funny_car\p20140116_test\Platform\modules\rinbufs\ringBufS.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116_test\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdbool.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "D:\funny_car\p20140116_test\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\drivers\drv_uart.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "..\..\Platform\modules\rtclib\rtclib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\projdefs.h" "..\..\Platform\include\FreeRTOSConfig.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116_test\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/ringBufS.asm" "D:/funny_car/p20140116_test/Platform/modules/rinbufs/ringBufS.c" 

"$(OUTDIR)\ringBufS.obj": "$(OUTDIR)\ringBufS.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\ringBufS.obj" "$(OUTDIR)\ringBufS.asm" 

"$(OUTDIR)\main.asm": "D:\funny_car\p20140116_test\Application\funny_car\main.c" "..\..\Platform\include\platform.h" "D:\funny_car\p20140116_test\Platform\include\GPCE206x.h" "..\..\Platform\modules\sacm\SACM.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdbool.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "D:\funny_car\p20140116_test\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "..\..\Platform\drivers\drv_gpio.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\drivers\drv_uart.h" "..\..\Platform\modules\pff\src\pff.h" "..\..\Platform\modules\hash\crc.h" "..\..\Platform\modules\sfat\sfat.h" "..\..\Platform\modules\printf\printf.h" "..\..\Platform\modules\xprintf\xprintf.h" "..\..\Platform\modules\rinbufs\ringBufS.h" "..\..\Platform\modules\rtclib\rtclib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\projdefs.h" "..\..\Platform\include\FreeRTOSConfig.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\portable.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\list.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\queue.h" "D:\funny_car\p20140116_test\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116_test\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/main.asm" "D:/funny_car/p20140116_test/Application/funny_car/main.c" 

"$(OUTDIR)\main.obj": "$(OUTDIR)\main.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\main.obj" "$(OUTDIR)\main.asm" 


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
	$(RM) "$(OUTDIR)\drv_gpio.obj" 
	$(RM) "$(OUTDIR)\drv_gpio.lst" 
	$(RM) "$(OUTDIR)\drv_gpio.asm" 
	$(RM) "$(OUTDIR)\drv_isr_a.obj" 
	$(RM) "$(OUTDIR)\drv_isr_a.lst" 
	$(RM) "$(OUTDIR)\drv_isr_c.obj" 
	$(RM) "$(OUTDIR)\drv_isr_c.lst" 
	$(RM) "$(OUTDIR)\drv_isr_c.asm" 
	$(RM) "$(OUTDIR)\drv_sys.obj" 
	$(RM) "$(OUTDIR)\drv_sys.lst" 
	$(RM) "$(OUTDIR)\mmcbb.obj" 
	$(RM) "$(OUTDIR)\mmcbb.lst" 
	$(RM) "$(OUTDIR)\mmcbb.asm" 
	$(RM) "$(OUTDIR)\pff.obj" 
	$(RM) "$(OUTDIR)\pff.lst" 
	$(RM) "$(OUTDIR)\pff.asm" 
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
	$(RM) "$(BINFILENOEXT).s37" "$(BINFILENOEXT).tsk" "$(BINFILENOEXT).hdb" $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

