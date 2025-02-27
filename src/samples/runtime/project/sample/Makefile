TARGET = sample
OBJS = main.o

INCDIR = 
CFLAGS = -O2 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

BUILD_PRX = 1

LIBDIR =
LDFLAGS =
LIBS= -lpspsha1 -lpspmd5

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = sample

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak

copy:
	make clean
	make
	sudo mount /dev/sda1 mount
	sudo rm -rf mount/PSP/GAME/$(TARGET)
	sudo mkdir mount/PSP/GAME/$(TARGET)
	sudo cp  $(EXTRA_TARGETS) mount/PSP/GAME/$(TARGET)/$(EXTRA_TARGETS)
	sudo umount mount
