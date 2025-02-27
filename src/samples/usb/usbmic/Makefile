TARGET = usb_mic
OBJS = exports.o main.o

BUILD_PRX=1
PRX_EXPORTS=exports.exp

INCDIR =
CFLAGS = -G0 -Wall -O2
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR =
LDFLAGS =

LIBS= -lpspusbmic -lpspusb  -lpsphprm -lpspaudio

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = sceUsbMic

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak

lightmap.o : lightmap.raw
	bin2o -i lightmap.raw lightmap.o lightmap

copy:
	make clean
	make
	sudo mount /dev/sda1 mount
	sudo rm -rf mount/PSP/GAME/$(PSP_EBOOT_TITLE)
	sudo mkdir mount/PSP/GAME/$(PSP_EBOOT_TITLE)
	sudo cp EBOOT.PBP mount/PSP/GAME/$(PSP_EBOOT_TITLE)/EBOOT.PBP
	sudo umount mount
