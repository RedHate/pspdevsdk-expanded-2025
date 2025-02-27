# PSP Software Development Kit - https://github.com/pspdev
# -----------------------------------------------------------------------
# Licensed under the BSD license, see LICENSE in PSPSDK root for details.
#
# build.mak - Base makefile for projects using PSPSDK.
#
# Copyright (c) 2005 Marcus R. Brown <mrbrown@ocgnet.org>
# Copyright (c) 2005 James Forshaw <tyranid@gmail.com>
# Copyright (c) 2005 John Kelley <ps2dev@kelley.ca>
#

# Note: The PSPSDK make variable must be defined before this file is included.
ifeq ($(PSPSDK),)
$(error $$(PSPSDK) is undefined.  Use "PSPSDK := $$(shell psp-config --pspsdk-path)" in your Makefile)
endif

CC       		= psp-gcc
CXX      		= psp-g++
AS       		= psp-gcc
LD       		= psp-gcc
AR       		= psp-gcc-ar
RANLIB   		= psp-gcc-ranlib
STRIP    		= psp-strip
MKSFO    		= mksfoex
PACK_PBP 		= pack-pbp
UNPACK_PBP		= unpack-pbp
FIXUP   		= psp-fixup-imports
##sign with all sorts of tags
SIGN_NP	 		= sign_np
##create eboot from iso
NP_ISO			= fake_np
##umd game sign with seboot
NP_UG 			= seboot
##mini game sign with PrxEncrypter
NP_MG	 		= PrxEncrypter
##generate a umd_data.bin
UMD_DATA 		= psp-umd-data-bin
##create iso file system
MKISOFS			= mkisofs
##a shady sfo program for iso (will replace with proper makesfoex)
SFO_GEN	 		= psp-sfo-gen

BIN2C	 		= bin2c
ECHO			= echo
MV		 		= mv
RM		 		= rm -rf
CP		 		= cp -R
MKDIR			= mkdir

# Add PSPSDK includes and libraries.
INCDIR   := $(INCDIR) . $(PSPDEV)/psp/include $(PSPSDK)/include
LIBDIR   := $(LIBDIR) . $(PSPDEV)/psp/lib $(PSPSDK)/lib

CFLAGS   := $(addprefix -I,$(INCDIR)) $(CFLAGS)
CXXFLAGS := $(CFLAGS) $(CXXFLAGS)
ASFLAGS  := $(CFLAGS) $(ASFLAGS)

ifeq ($(PSP_FW_VERSION),)
PSP_FW_VERSION=600
endif

EXPAND_MEMORY = 0

# CFW versions after M33 3.90 guard against expanding the
# user memory partition on PSP-1000, making MEMSIZE obsolete.
# It is now an opt-out policy with PSP_LARGE_MEMORY=0
ifeq ($(shell test $(PSP_FW_VERSION) -gt 390; echo $$?),0)
EXPAND_MEMORY = 1
ifeq ($(PSP_LARGE_MEMORY),1)
$(warning "PSP_LARGE_MEMORY" flag is not necessary targeting firmware versions above 3.90)
else ifeq ($(PSP_LARGE_MEMORY),0)
EXPAND_MEMORY = 0
endif # PSP_LARGE_MEMORY
else
ifeq ($(PSP_LARGE_MEMORY),1)
EXPAND_MEMORY = 1
endif # PSP_LARGE_MEMORY
endif # PSP_FW_VERSION

SFOFLAGS := -d MEMSIZE=$(EXPAND_MEMORY) $(SFOFLAGS)

CFLAGS += -D_PSP_FW_VERSION=$(PSP_FW_VERSION)
CXXFLAGS += -D_PSP_FW_VERSION=$(PSP_FW_VERSION)

ifeq ($(BUILD_PRX),1)
LDFLAGS  := $(addprefix -L,$(LIBDIR)) -specs=$(PSPSDK)/lib/prxspecs -Wl,-q,-T$(PSPSDK)/lib/linkfile.prx $(LDFLAGS)
EXTRA_CLEAN += $(TARGET).elf
# Setup default exports if needed
ifdef PRX_EXPORTS
EXPORT_OBJ=$(patsubst %.exp,%.o,$(PRX_EXPORTS))
EXTRA_CLEAN += $(EXPORT_OBJ)
else 
EXPORT_OBJ=$(PSPSDK)/lib/prxexports.o
endif
else
LDFLAGS  := $(addprefix -L,$(LIBDIR)) $(LDFLAGS)
endif

# Reduce binary size
LDFLAGS +=  -Wl,-zmax-page-size=128

ifeq ($(USE_KERNEL_LIBS),1)
LIBS := -nostdlib $(LIBS) -lpspdebug -lpspdisplay_driver -lpspctrl_driver -lpspmodinfo -lpspsdk -lpspkernel
else
LIBS := $(LIBS) -lpspdebug -lpspdisplay -lpspge -lpspctrl -lpspnet -lpspnet_apctl
endif

ifndef MOUNT_DEVICE
MOUNT_DEVICE 		= /dev/sda1
endif

ifndef EBOOT_BIN
EBOOT_BIN 			= EBOOT.BIN
endif

ifndef BOOT_BIN
BOOT_BIN 			= BOOT.BIN
endif


##default to minigame category for param.sfo
ifndef GAME_CAT
GAME_CAT 			= MG
endif

ifndef GAME_ID
GAME_ID 			= PSP0-12345
endif

ifndef TARGET_ISO
TARGET_ISO 			= $(GAME_ID).ISO
endif

ifndef GAME_VER
GAME_VER 			= 1.00
endif

ifndef FIRMWARE_VER
FIRMWARE_VER 		= 1.00
endif

ifndef PSP_EBOOT_TITLE
PSP_EBOOT_TITLE		= "PSPDEV HOMEBREW"
endif

ifndef EBOOT_PBP
EBOOT_PBP 			= EBOOT.PBP
endif

ifndef PSP_EBOOT_ICON
PSP_EBOOT_ICON 		= NULL
endif

ifndef PSP_EBOOT_ICON1
PSP_EBOOT_ICON1 	= NULL
endif

ifndef PSP_EBOOT_PIC1
PSP_EBOOT_PIC1 		= NULL
endif

ifndef PSP_EBOOT_SND0
PSP_EBOOT_SND0 		= NULL
endif

ifndef PSP_EBOOT_TITLE
PSP_EBOOT_TITLE 	= $(TARGET)
endif

ifndef PSP_EBOOT_SFO
PSP_EBOOT_SFO 		= PARAM.SFO
endif

ifndef PSP_EBOOT_UNKPNG
PSP_EBOOT_UNKPNG 	= NULL
endif

ifndef PSP_EBOOT_PSAR
PSP_EBOOT_PSAR 		= NULL
endif

ifndef UMD_DATA_BIN
UMD_DATA_BIN 		= UMD_DATA.BIN
endif

ifndef PSP_EBOOT
PSP_EBOOT = EBOOT.PBP
endif

ifeq ($(BUILD_PRX),1)
ifneq ($(TARGET_LIB),)
$(error TARGET_LIB should not be defined when building a prx)
else
FINAL_TARGET = $(TARGET).prx
endif
else
ifneq ($(TARGET_LIB),)
FINAL_TARGET = $(TARGET_LIB)
else
FINAL_TARGET = $(TARGET).elf
endif
endif

all: $(EXTRA_TARGETS) $(FINAL_TARGET)

kxploit: $(TARGET).elf $(PSP_EBOOT_SFO)
	mkdir -p "$(TARGET)"
	$(STRIP) $(TARGET).elf -o $(TARGET)/$(PSP_EBOOT)
	mkdir -p "$(TARGET)%"
	$(PACK_PBP) "$(TARGET)%/$(PSP_EBOOT)" $(PSP_EBOOT_SFO) $(PSP_EBOOT_ICON)  \
		$(PSP_EBOOT_ICON1) $(PSP_EBOOT_UNKPNG) $(PSP_EBOOT_PIC1)  \
		$(PSP_EBOOT_SND0) NULL $(PSP_EBOOT_PSAR)

SCEkxploit: $(TARGET).elf $(PSP_EBOOT_SFO)
	mkdir -p "__SCE__$(TARGET)"
	$(STRIP) $(TARGET).elf -o __SCE__$(TARGET)/$(PSP_EBOOT)
	mkdir -p "%__SCE__$(TARGET)"
	$(PACK_PBP) "%__SCE__$(TARGET)/$(PSP_EBOOT)" $(PSP_EBOOT_SFO) $(PSP_EBOOT_ICON)  \
		$(PSP_EBOOT_ICON1) $(PSP_EBOOT_UNKPNG) $(PSP_EBOOT_PIC1)  \
		$(PSP_EBOOT_SND0) NULL $(PSP_EBOOT_PSAR)

ifeq ($(NO_FIXUP_IMPORTS), 1)
$(TARGET).elf: $(OBJS) $(EXPORT_OBJ)
	$(LINK.c) $^ $(LIBS) -o $@
else
$(TARGET).elf: $(OBJS) $(EXPORT_OBJ)
	$(LINK.c) $^ $(LIBS) -o $@
	$(FIXUP) $@
endif

$(TARGET_LIB): $(OBJS)
	$(AR) cru $@ $(OBJS)
	$(RANLIB) $@

$(PSP_EBOOT_SFO):
	$(MKSFO) $(SFOFLAGS) '$(PSP_EBOOT_TITLE)' $@

ifeq ($(BUILD_PRX),1)
$(PSP_EBOOT): $(TARGET).prx $(PSP_EBOOT_SFO)
ifeq ($(ENCRYPT), 1)
	$(NP_MG) $(TARGET).prx $(TARGET).prx
endif
	$(PACK_PBP) $(PSP_EBOOT) $(PSP_EBOOT_SFO) $(PSP_EBOOT_ICON)  \
		$(PSP_EBOOT_ICON1) $(PSP_EBOOT_UNKPNG) $(PSP_EBOOT_PIC1)  \
		$(PSP_EBOOT_SND0)  $(TARGET).prx $(PSP_EBOOT_PSAR)
else
$(PSP_EBOOT): $(TARGET).elf $(PSP_EBOOT_SFO)
	$(STRIP) $(TARGET).elf -o $(TARGET)_strip.elf
	$(PACK_PBP) $(PSP_EBOOT) $(PSP_EBOOT_SFO) $(PSP_EBOOT_ICON)  \
		$(PSP_EBOOT_ICON1) $(PSP_EBOOT_UNKPNG) $(PSP_EBOOT_PIC1)  \
		$(PSP_EBOOT_SND0)  $(TARGET)_strip.elf $(PSP_EBOOT_PSAR)
	$(RM) $(TARGET)_strip.elf
endif

iso: $(TARGET).prx
##DELETE THE OLD FS STRUCTURE
	$(RM) $(GAME_ID)
##MAKE FS STRUCTURE
	$(MKDIR) $(GAME_ID)/
	$(MKDIR) $(GAME_ID)/PSP_GAME
	$(MKDIR) $(GAME_ID)/PSP_GAME/SYSDIR
	$(MKDIR) $(GAME_ID)/PSP_GAME/USRDIR
	$(MKDIR) $(GAME_ID)/PSP_GAME/USRDIR/module
##COPY ARTWORK
ifneq ($(PSP_EBOOT_ICON), NULL)
	$(CP) $(PSP_EBOOT_ICON)   $(GAME_ID)/PSP_GAME/ICON0.PNG
endif
ifneq ($(PSP_EBOOT_ICON1), NULL)
	$(CP) $(PSP_EBOOT_ICON1)  $(GAME_ID)/PSP_GAME/ICON1.PNG
endif
ifneq ($(PSP_EBOOT_PIC1), NULL)
	$(CP) $(PSP_EBOOT_PIC1)   $(GAME_ID)/PSP_GAME/PIC1.PNG
endif
ifneq ($(PSP_EBOOT_SND0), NULL)
	$(CP) $(PSP_EBOOT_SND0)   $(GAME_ID)/PSP_GAME/SND0.AT3
endif
##COPY ASSETS
	$(CP) module/* $(GAME_ID)/PSP_GAME/USRDIR/module/
##MAKE UMDDATA.BIN
	$(UMD_DATA) $(GAME_ID)
	$(CP) $(UMD_DATA_BIN) $(GAME_ID)/$(UMD_DATA_BIN)
##MAKE BOOT.BIN
	$(CP) $(TARGET).prx  $(GAME_ID)/PSP_GAME/SYSDIR/$(BOOT_BIN)
##MAKE EBOOT.BIN
	$(CP) $(TARGET).prx $(EBOOT_BIN)
ifeq ($(ENCRYPT), 1)
	$(NP_UG) $(EBOOT_BIN)
endif
	$(MV) $(EBOOT_BIN) $(GAME_ID)/PSP_GAME/SYSDIR/$(EBOOT_BIN)
##MAKE PARAM.SFO
	$(SFO_GEN) UG $(GAME_ID) $(GAME_VER) $(FIRMWARE_VER) "$(PSP_EBOOT_TITLE)"
	$(CP) $(PSP_EBOOT_SFO) $(GAME_ID)/PSP_GAME/$(PSP_EBOOT_SFO)
##GENERATE ISO
	$(MKISOFS) -iso-level 4 -xa -A "$(GAME_ID)" -V NA -sysid "$(GAME_ID)" -volset SSX_PSP -p SSX -o np.iso $(GAME_ID)/
ifeq ($(ENCRYPT), 1)
##PACK ISO INTO EBOOT
	$(NP_ISO)
##UPACK REPACK EBOOT.PBP
	$(UNPACK_PBP) $(EBOOT_PBP)
	#RESIGN THE DATA.PSP
	$(NP_MG) DATA.PSP
	#REPACK THE EBOOT.BIN
	$(PACK_PBP) $(EBOOT_PBP) $(PSP_EBOOT_SFO) $(PSP_EBOOT_ICON)  \
		$(PSP_EBOOT_ICON1) $(PSP_EBOOT_UNKPNG) $(PSP_EBOOT_PIC1)  \
		$(PSP_EBOOT_SND0) DATA.PSP DATA.PSAR
	$(RM) DATA.PSP DATA.PSAR
endif
##RENAME THE TARGET TO THE GAMEID
	$(MV) np.iso $(TARGET_ISO)

%.prx: %.elf
	psp-prxgen $< $@

%.c: %.exp
	psp-build-exports -b $< > $@

clean: 
	$(RM) $(FINAL_TARGET) $(EXTRA_CLEAN) $(OBJS) $(PSP_EBOOT_SFO) $(PSP_EBOOT) $(EXTRA_TARGETS) $(GAME_ID) $(UMD_DATA_BIN) $(TARGET_ISO) $(EBOOT_BIN)

rebuild: clean all

copy-iso: $(TARGET_ISO)
	mkdir -p mount
	sudo mount $(MOUNT_DEV) mount
	sudo cp  $(TARGET_ISO) mount/ISO/$(TARGET_ISO)
	sudo umount mount

test-iso: $(TARGET_ISO)
	mkdir -p tmp
	cp -Rp $(TARGET_ISO) tmp/
	$(PPSSPP)/PPSSPPSDL tmp/$(TARGET_ISO)
