#####################################################################
#																	 
#	Created by u'nSP IDE V3.0.8		23:09:48	04/03/14
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

INCLUDES	= -I"D:/funny_car/p20140116/Application/funny_car" -I"C:/Program Files (x86)/Generalplus/unSPIDE 3.0.8/library/include" -I"C:/Program Files (x86)/Generalplus/unSPIDE 3.0.8/library/include/sys" -I"../../Application/include" -I"../../Platform/include" -I"../../Platform/modules/pff/src" -I"../../Platform/drivers" -I"../../Platform/modules/freertos/source/include" -I"../../Platform/modules/freertos/source/portable/GCC/unsp_isa_v13"

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
	"$(OUTDIR)\mmcbb.obj" \
	"$(OUTDIR)\pff.obj" \
	"$(OUTDIR)\port_a.obj" \
	"$(OUTDIR)\port_c.obj" \
	"$(OUTDIR)\heap_3.obj" \
	"$(OUTDIR)\croutine.obj" \
	"$(OUTDIR)\list.obj" \
	"$(OUTDIR)\queue.obj" \
	"$(OUTDIR)\tasks.obj" \
	"$(OUTDIR)\timers.obj" \
	"$(OUTDIR)\event_groups.obj" \
	"$(OUTDIR)\main.obj" \
	"$(OUTDIR)\System.obj" \
	"$(OUTDIR)\SACM_A1600_User.obj" \
	"$(OUTDIR)\isr_c.obj" \
	"$(OUTDIR)\isr_a.obj" \
	"$(OUTDIR)\ParTest.obj" 

"$(OUTDIR)\Resource.obj": "D:\funny_car\p20140116\Application\funny_car\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)\Resource.obj" "D:\funny_car\p20140116\Application\funny_car\Resource.asm" 

"$(OUTDIR)\drv_i2c.asm": "D:\funny_car\p20140116\Platform\drivers\drv_i2c.c" "D:\funny_car\p20140116\Platform\drivers\drv_i2c.h" "..\..\Platform\include\GPCE206x.h" "..\..\Platform\include\stdint.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/drv_i2c.asm" "D:/funny_car/p20140116/Platform/drivers/drv_i2c.c" 

"$(OUTDIR)\drv_i2c.obj": "$(OUTDIR)\drv_i2c.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\drv_i2c.obj" "$(OUTDIR)\drv_i2c.asm" 

"$(OUTDIR)\drv_lcd.asm": "D:\funny_car\p20140116\Platform\drivers\drv_lcd.c" "D:\funny_car\p20140116\Platform\drivers\drv_lcd.h" "D:\funny_car\p20140116\Platform\drivers\drv_spi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" "..\..\Platform\include\GPCE206x.h" "..\..\Platform\include\stdint.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/drv_lcd.asm" "D:/funny_car/p20140116/Platform/drivers/drv_lcd.c" 

"$(OUTDIR)\drv_lcd.obj": "$(OUTDIR)\drv_lcd.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\drv_lcd.obj" "$(OUTDIR)\drv_lcd.asm" 

"$(OUTDIR)\drv_mtd.asm": "D:\funny_car\p20140116\Platform\drivers\drv_mtd.c" "D:\funny_car\p20140116\Platform\drivers\drv_mtd.h" "D:\funny_car\p20140116\Platform\drivers\drv_spi.h" "..\..\Platform\include\GPCE206x.h" "..\..\Platform\include\stdint.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/drv_mtd.asm" "D:/funny_car/p20140116/Platform/drivers/drv_mtd.c" 

"$(OUTDIR)\drv_mtd.obj": "$(OUTDIR)\drv_mtd.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\drv_mtd.obj" "$(OUTDIR)\drv_mtd.asm" 

"$(OUTDIR)\drv_spi.asm": "D:\funny_car\p20140116\Platform\drivers\drv_spi.c" "D:\funny_car\p20140116\Platform\drivers\drv_spi.h" "..\..\Platform\include\GPCE206x.h" "..\..\Platform\include\stdint.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/drv_spi.asm" "D:/funny_car/p20140116/Platform/drivers/drv_spi.c" 

"$(OUTDIR)\drv_spi.obj": "$(OUTDIR)\drv_spi.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\drv_spi.obj" "$(OUTDIR)\drv_spi.asm" 

"$(OUTDIR)\mmcbb.asm": "D:\funny_car\p20140116\Platform\modules\pff\src\mmcbb.c" "D:\funny_car\p20140116\Platform\modules\pff\src\diskio.h" "D:\funny_car\p20140116\Platform\modules\pff\src\integer.h" "D:\funny_car\p20140116\Platform\modules\pff\src\pff.h" "..\..\Platform\include\GPCE206x.h" "..\..\Platform\drivers\drv_spi.h" "..\..\Platform\include\stdint.h" 
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

"$(OUTDIR)\port_c.asm": "D:\funny_car\p20140116\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\port_c.c" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" "..\..\Platform\include\stdint.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "..\..\Platform\modules\freertos\source\include\task.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "..\..\Platform\include\GPCE206x.h" 
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

"$(OUTDIR)\timers.asm": "D:\funny_car\p20140116\Platform\modules\freertos\source\timers.c" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "..\..\Platform\modules\freertos\source\include\task.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "..\..\Platform\modules\freertos\source\include\queue.h" "..\..\Platform\modules\freertos\source\include\timers.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\task.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/timers.asm" "D:/funny_car/p20140116/Platform/modules/freertos/source/timers.c" 

"$(OUTDIR)\timers.obj": "$(OUTDIR)\timers.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\timers.obj" "$(OUTDIR)\timers.asm" 

"$(OUTDIR)\event_groups.asm": "D:\funny_car\p20140116\Platform\modules\freertos\source\event_groups.c" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "..\..\Platform\modules\freertos\source\include\task.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "..\..\Platform\modules\freertos\source\include\timers.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\task.h" "..\..\Platform\modules\freertos\source\include\event_groups.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\timers.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/event_groups.asm" "D:/funny_car/p20140116/Platform/modules/freertos/source/event_groups.c" 

"$(OUTDIR)\event_groups.obj": "$(OUTDIR)\event_groups.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\event_groups.obj" "$(OUTDIR)\event_groups.asm" 

"$(OUTDIR)\main.asm": "D:\funny_car\p20140116\Application\funny_car\main.c" ".\SACM.h" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" "..\..\Platform\modules\freertos\source\include\task.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "..\..\Platform\modules\freertos\source\include\croutine.h" "..\..\Platform\modules\freertos\source\include\semphr.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\queue.h" "..\..\Platform\include\GPCE206x.h" "..\..\Platform\drivers\drv_i2c.h" "..\..\Platform\drivers\drv_mtd.h" "..\..\Platform\drivers\drv_lcd.h" "..\..\Platform\modules\pff\src\pff.h" "D:\funny_car\p20140116\Platform\modules\pff\src\integer.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdio.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdarg.h" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/main.asm" "D:/funny_car/p20140116/Application/funny_car/main.c" 

"$(OUTDIR)\main.obj": "$(OUTDIR)\main.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\main.obj" "$(OUTDIR)\main.asm" 

"$(OUTDIR)\System.obj": "D:\funny_car\p20140116\Application\funny_car\System.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)\System.obj" "D:\funny_car\p20140116\Application\funny_car\System.asm" 

"$(OUTDIR)\SACM_A1600_User.obj": "D:\funny_car\p20140116\Application\funny_car\SACM_A1600_User.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)\SACM_A1600_User.obj" "D:\funny_car\p20140116\Application\funny_car\SACM_A1600_User.asm" 

"$(OUTDIR)\isr_c.asm": "D:\funny_car\p20140116\Application\funny_car\isr_c.c" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/isr_c.asm" "D:/funny_car/p20140116/Application/funny_car/isr_c.c" 

"$(OUTDIR)\isr_c.obj": "$(OUTDIR)\isr_c.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -o "$(OUTDIR)\isr_c.obj" "$(OUTDIR)\isr_c.asm" 

"$(OUTDIR)\isr_a.obj": "D:\funny_car\p20140116\Application\funny_car\isr_a.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)\isr_a.obj" "D:\funny_car\p20140116\Application\funny_car\isr_a.asm" 

"$(OUTDIR)\ParTest.asm": "D:\funny_car\p20140116\Application\ParTest\ParTest.c" "..\..\Platform\modules\freertos\source\include\FreeRTOS.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stddef.h" "..\..\Platform\include\stdint.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\projdefs.h" "..\..\Application\include\FreeRTOSConfig.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\portable.h" "..\..\Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\mpu_wrappers.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\string.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\memory.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\stdlib.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\sys\reent.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\_ansi.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\machine/_types.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\assert.h" "C:\Program Files (x86)\Generalplus\unSPIDE 3.0.8\library\include\limits.h" "..\..\Platform\modules\freertos\source\include\task.h" "D:\funny_car\p20140116\Platform\modules\freertos\source\include\list.h" "..\..\Platform\include\GPCE206x.h" 
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
	$(RM) "$(OUTDIR)\timers.obj" 
	$(RM) "$(OUTDIR)\timers.lst" 
	$(RM) "$(OUTDIR)\timers.asm" 
	$(RM) "$(OUTDIR)\event_groups.obj" 
	$(RM) "$(OUTDIR)\event_groups.lst" 
	$(RM) "$(OUTDIR)\event_groups.asm" 
	$(RM) "$(OUTDIR)\main.obj" 
	$(RM) "$(OUTDIR)\main.lst" 
	$(RM) "$(OUTDIR)\main.asm" 
	$(RM) "$(OUTDIR)\System.obj" 
	$(RM) "$(OUTDIR)\System.lst" 
	$(RM) "$(OUTDIR)\SACM_A1600_User.obj" 
	$(RM) "$(OUTDIR)\SACM_A1600_User.lst" 
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

