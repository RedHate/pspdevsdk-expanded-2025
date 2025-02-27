TARGET = runtime_init
OBJS = main.o

MOUNT_DEV = /dev/sda1

INCDIR = 
CFLAGS = -O2 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

BUILD_PRX = 1
#ENCRYPT = 1

LIBDIR =
LDFLAGS =
LIBS = -lpspuser

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = runtime-module

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build_iso.mak

copy:
	mkdir -p mount
	sudo mount $(MOUNT_DEV) mount
	sudo mkdir -p mount/PSP/GAME/$(TARGET)
	sudo cp  $(EXTRA_TARGETS) mount/PSP/GAME/$(TARGET)/$(EXTRA_TARGETS)
	sudo cp  module/libsha1.prx mount/PSP/GAME/$(TARGET)/libsha1.prx
	sudo cp  module/libmd5.prx mount/PSP/GAME/$(TARGET)/libmd5.prx
	sudo cp  module/sample.prx mount/PSP/GAME/$(TARGET)/sample.prx
	sudo umount mount


