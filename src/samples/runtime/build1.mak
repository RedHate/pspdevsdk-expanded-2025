# -----------------------------------------------------------------------
# PSP Software Development Kit - http://www.pspdev.org
# -----------------------------------------------------------------------
# Licensed under the BSD license, see LICENSE in PSPSDK root for details.
#
# build.mak - Base makefile for projects using PSPSDK.
#
# Copyright (c) 2005 Marcus R. Brown <mrbrown@ocgnet.org>
# Copyright (c) 2005 James Forshaw <tyranid@gmail.com>
# Copyright (c) 2005 John Kelley <ps2dev@kelley.ca>
#
# $Id: build.mak 2333 2007-10-31 19:37:40Z tyranid $
# Note: The PSPSDK make variable must be defined before this file is included.
# -----------------------------------------------------------------------

# -----------------------------------------------------------------------
#
# NPDRM Friendly build.mak using available signing utils from the scene, as well
# as some utils for gu, png to raw header conversion util as well as an obj to
# vertex list utility:
#
# -----------------------------------------------------------------------
# Sig Utils:
# -----------------------------------------------------------------------
# 	prxEncryptor encrypts user mode prxs and elfs
# 	seboot	   encrypts eboot.bin's to be used with fake_np
# 	fake_np	   fake_np creates an eboot from an iso, (this allows you to contain about 750 mb of 
# shit in your usermode homebrew)
#
# -----------------------------------------------------------------------
# GU Utils:
# -----------------------------------------------------------------------
# 	psp-obj2h.exe  (Obj utility) Creates a vertex list from an ".obj" model
# 	psp-png2h.exe  (Texture Utility) A header with a list of pixels from an image.
# 	psp-png2hm.exe (Heightmap utility) Generates a vertex list via an image, works best with 32 x 32
#													- RedHate :P
#
# -----------------------------------------------------------------------

ifeq ($(PSPSDK),)
$(error $$(PSPSDK) is undefined.  Use "PSPSDK := $$(shell psp-config --pspsdk-path)" in your Makefile)
endif

CC				= psp-gcc
CXX      		= psp-g++
AS       		= psp-gcc
LD       		= psp-gcc
AR       		= psp-ar -cru
RANLIB   		= psp-ranlib
STRIP    		= psp-strip
PRX_GEN  		= psp-prxgen
PACK_PBP 		= pack-pbp
UNPACK_PBP		= unpack-pbp
FIXUP    		= psp-fixup-imports
BUILD_EXPORTS 	= psp-build-exports
SFO_GEN	 		= psp-sfo-gen
UMD_DATA		= psp-umd-data-bin
COMPRESS 		= psp-packer
PNG2HGU  		= psp-png2h
PNG2HMAP 		= psp-png2hm
OBJ2HGU  		= psp-obj2h
BIN2C	 		= bin2c
ECHO			= echo
MV		 		= mv
RM		 		= rm -rf
CP		 		= cp -Rp
MKDIR			= mkdir
MKISOFS			= mkisofs
NP_ISO			= fake_np
NP_UG 			= seboot
NP_MG	 		= prxEncryptor

INCDIR   		:= $(INCDIR) . $(PSPSDK)/include
LIBDIR   		:= $(LIBDIR) . $(PSPSDK)/lib
CFLAGS   		:= $(addprefix -I,$(INCDIR)) $(CFLAGS)
CXXFLAGS 		:= $(CFLAGS) $(CXXFLAGS)
ASFLAGS  		:= $(CFLAGS) $(ASFLAGS)

ifeq ($(FAKE_NP_EBOOT),1)
BUILD_PRX			= 1
SIGN_HOMEBREW		= 1
endif

ifeq ($(PSP_LARGE_MEMORY),1)
MKSFO = mksfoex -d MEMSIZE=1
endif

ifeq ($(PSP_FW_VERSION),)
PSP_FW_VERSION=150
endif

EXTRA_TARGETS += $(MODELS) $(TEXTURES)

CFLAGS += -D_PSP_FW_VERSION=$(PSP_FW_VERSION)
CXXFLAGS += -D_PSP_FW_VERSION=$(PSP_FW_VERSION)

ifeq ($(BUILD_PRX),1)
LDFLAGS  := $(addprefix -L,$(LIBDIR)) -specs=$(PSPSDK)/lib/prxspecs -Wl,-q,-T$(PSPSDK)/lib/linkfile.prx $(LDFLAGS)
EXTRA_CLEAN += $(TARGET).elf

ifdef PRX_EXPORTS
EXPORT_OBJ=$(patsubst %.exp,%.o,$(PRX_EXPORTS))
EXTRA_CLEAN += $(EXPORT_OBJ)
else 
EXPORT_OBJ=$(PSPSDK)/lib/prxexports.o
endif
else
LDFLAGS  := $(addprefix -L,$(LIBDIR)) $(LDFLAGS)
endif

ifeq ($(USE_KERNEL_LIBC),1)
FAKE_NP_EBOOT		= 0
SIGN_HOMEBREW		= 0
PSPSDK_LIBC_LIB 	= 
CFLAGS := -I$(PSPSDK)/include/libc $(CFLAGS)
else
ifeq ($(USE_PSPSDK_LIBC),1)
PSPSDK_LIBC_LIB = -lpsplibc
CFLAGS := -I$(PSPSDK)/include/libc $(CFLAGS)
else
PSPSDK_LIBC_LIB = -lc
endif
endif

ifeq ($(USE_KERNEL_LIBS),1)
FAKE_NP_EBOOT		= 0
SIGN_HOMEBREW		= 0
PSPSDK_LIBS = -lpspdebug -lpspdisplay_driver -lpspctrl_driver -lpspsdk
LIBS     := $(LIBS) $(PSPSDK_LIBS) $(PSPSDK_LIBC_LIB) -lpspkernel
else
ifeq ($(USE_USER_LIBS),1)
PSPSDK_LIBS = -lpspdebug -lpspdisplay -lpspge -lpspctrl -lpspsdk
LIBS     := $(LIBS) $(PSPSDK_LIBS) $(PSPSDK_LIBC_LIB) -lpspnet \
			-lpspnet_inet -lpspnet_apctl -lpspnet_resolver -lpsputility \
			-lpspuser
else
PSPSDK_LIBS = -lpspdebug -lpspdisplay -lpspge -lpspctrl -lpspsdk
LIBS     := $(LIBS) $(PSPSDK_LIBS) $(PSPSDK_LIBC_LIB) -lpspnet \
			-lpspnet_inet -lpspnet_apctl -lpspnet_resolver -lpsputility \
			-lpspuser -lpspkernel
endif
endif

EBOOT_BIN 			= EBOOT.BIN
FAKE_NP_ISO 		= NP.ISO

ifndef GAME_CAT
GAME_CAT 			= MG
endif

ifndef GAME_ID
GAME_ID 			= PSP0-12345
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
	$(MKDIR) -p "$(TARGET)"
	$(STRIP) $(TARGET).elf -o $(TARGET)/$(EBOOT_PBP)
	$(MKDIR) -p "$(TARGET)%"
	$(PACK_PBP) "$(TARGET)%/$(EBOOT_PBP)" $(PSP_EBOOT_SFO) $(PSP_EBOOT_ICON)  \
		$(PSP_EBOOT_ICON1) $(PSP_EBOOT_UNKPNG) $(PSP_EBOOT_PIC1)  \
		$(PSP_EBOOT_SND0) NULL $(PSP_EBOOT_PSAR)

SCEkxploit: $(TARGET).elf $(PSP_EBOOT_SFO)
	$(MKDIR) -p "__SCE__$(TARGET)"
	$(STRIP) $(TARGET).elf -o __SCE__$(TARGET)/$(EBOOT_PBP)
	$(MKDIR) -p "%__SCE__$(TARGET)"
	$(PACK_PBP) "%__SCE__$(TARGET)/$(EBOOT_PBP)" $(PSP_EBOOT_SFO) $(PSP_EBOOT_ICON)  \
		$(PSP_EBOOT_ICON1) $(PSP_EBOOT_UNKPNG) $(PSP_EBOOT_PIC1)  \
		$(PSP_EBOOT_SND0) NULL $(PSP_EBOOT_PSAR)

$(TARGET).elf: $(OBJS) $(EXPORT_OBJ)
	$(ECHO) "[LINK] $(TARGET).elf"
	$(LINK.c) $^ $(LIBS) -o $@
	$(FIXUP) $@

$(TARGET_LIB): $(OBJS)
	$(ECHO) "[AR] $(TARGET_LIB).a"
	$(AR) $@ $(OBJS)
	$(RANLIB) $@

$(PSP_EBOOT_SFO):
	$(ECHO) "[SFO_GEN] PARAM.SFO"
	$(SFO_GEN) $(GAME_CAT) $(GAME_ID) $(GAME_VER) $(FIRMWARE_VER) "$(PSP_EBOOT_TITLE)"
ifeq ($(FAKE_NP_EBOOT),1)
	$(CP) $(PSP_EBOOT_SFO) $(GAME_ID)/PSP_GAME/$(PSP_EBOOT_SFO)
endif

ifeq ($(FAKE_NP_EBOOT),1)
	$(ECHO) "[FAKE_NP_EBOOT] $(EBOOT_PBP)"

$(EBOOT_BIN): $(TARGET).prx 
	$(CP) $(TARGET).prx $(EBOOT_BIN)
	$(NP_UG) $(EBOOT_BIN)
	$(MV) $(EBOOT_BIN) $(GAME_ID)/PSP_GAME/SYSDIR/$(EBOOT_BIN)

$(UMD_DATA_BIN):
	$(UMD_DATA) $(GAME_ID)
	$(MV) $(UMD_DATA_BIN) $(GAME_ID)/$(UMD_DATA_BIN)

COPY_ISO_ASSETS:
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

BUILD_ISO_TREE:
	$(RM) $(GAME_ID)/
	$(MKDIR) $(GAME_ID)/
	$(MKDIR) $(GAME_ID)/PSP_GAME
	$(MKDIR) $(GAME_ID)/PSP_GAME/SYSDIR
	$(MKDIR) $(GAME_ID)/PSP_GAME/USRDIR

$(EBOOT_PBP): BUILD_ISO_TREE COPY_ISO_ASSETS $(UMD_DATA_BIN) $(EBOOT_BIN) $(PSP_EBOOT_SFO)
	$(MKISOFS) -iso-level 4 -xa -A "$(GAME_ID)" -V NA -sysid "$(GAME_ID)" -volset SSX_PSP -p SSX -o $(FAKE_NP_ISO) $(GAME_ID)/
	$(NP_ISO)
	#$(RM) $(FAKE_NP_ISO) $(GAME_ID) $(UMD_DATA_BIN) $(EBOOT_BIN) $(FAKE_NP_ISO)
	$(UNPACK_PBP) $(EBOOT_PBP)
	$(PACK_PBP) $(EBOOT_PBP) $(PSP_EBOOT_SFO) $(PSP_EBOOT_ICON)  \
		$(PSP_EBOOT_ICON1) $(PSP_EBOOT_UNKPNG) $(PSP_EBOOT_PIC1)  \
		$(PSP_EBOOT_SND0) data.psp data.psar
	$(RM) data.psp data.psar

else
	$(ECHO) "[EBOOT] $(EBOOT_PBP)"
ifeq ($(BUILD_PRX),1)
$(EBOOT_PBP): $(TARGET).prx $(PSP_EBOOT_SFO)
ifeq ($(SIGN_HOMEBREW), 1)
	$(NP_MG) $(TARGET).prx
	$(PACK_PBP) $(EBOOT_PBP) $(PSP_EBOOT_SFO) $(PSP_EBOOT_ICON)  \
		$(PSP_EBOOT_ICON1) $(PSP_EBOOT_UNKPNG) $(PSP_EBOOT_PIC1)  \
		$(PSP_EBOOT_SND0) data.psp $(PSP_EBOOT_PSAR)
	$(RM) data.psp
else
	$(PACK_PBP) $(EBOOT_PBP) $(PSP_EBOOT_SFO) $(PSP_EBOOT_ICON)  \
		$(PSP_EBOOT_ICON1) $(PSP_EBOOT_UNKPNG) $(PSP_EBOOT_PIC1)  \
		$(PSP_EBOOT_SND0)  $(TARGET).prx $(PSP_EBOOT_PSAR)
ifeq ($(COMPRESS_PBP), 1)
	$(COMPRESS) $(EBOOT_PBP)
endif
endif
else
$(EBOOT_PBP): $(TARGET).elf $(PSP_EBOOT_SFO)
	$(STRIP) $(TARGET).elf -o $(TARGET)_strip.elf
ifeq ($(SIGN_HOMEBREW), 1)
	$(NP_MG) $(TARGET)_strip.elf
	$(PACK_PBP) $(EBOOT_PBP) $(PSP_EBOOT_SFO) $(PSP_EBOOT_ICON)  \
		$(PSP_EBOOT_ICON1) $(PSP_EBOOT_UNKPNG) $(PSP_EBOOT_PIC1)  \
		$(PSP_EBOOT_SND0) data.psp $(PSP_EBOOT_PSAR)
	$(RM) data.psp
else
	$(PACK_PBP) $(EBOOT_PBP) $(PSP_EBOOT_SFO) $(PSP_EBOOT_ICON)  \
		$(PSP_EBOOT_ICON1) $(PSP_EBOOT_UNKPNG) $(PSP_EBOOT_PIC1)  \
		$(PSP_EBOOT_SND0) $(TARGET)_strip.elf $(PSP_EBOOT_PSAR)
ifeq ($(COMPRESS_PBP), 1)
	$(COMPRESS) $(EBOOT_PBP)
endif
endif
	$(RM) $(TARGET)_strip.elf
endif
endif

%.o: %.c
	$(ECHO) "[CC] $(notdir $(basename $<)).o"
	$(CC) $(DEPSOPTIONS) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.cpp
	$(ECHO) "[CXX] $(notdir $(basename $<)).o"
	$(CXX) $(DEPSOPTIONS) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.S
	$(ECHO) "[CC] $(notdir $(basename $<)).o"
	$(AS) $(DEPSOPTIONS) -x assembler-with-cpp $(ASFLAGS) $(INCLUDES) -c $< -o $@

%.a:
	$(ECHO) "[AR] $(notdir $(basename $<)).a"
	$(AR) $@ $^
	$(STRIP) --strip-debug $@

%.h: %.png
	$(ECHO) "[PNG2HGU] $(notdir $(basename $<)).h"
	$(PNG2HGU) $< $(notdir $(basename $<))
	$(MV) $(notdir $(basename $<)).h $(basename $<).h

%_hmap.h: %.png
	$(ECHO) "[PNG2HMAP] $(notdir $(basename $<))_hmap.h"
	$(PNG2HMAP) $< $(notdir $(basename $<))
	$(MV) $(notdir $(basename $<)).h $(basename $<).h

%.h: %.obj
	$(ECHO) "[OBJ2HGU] $(notdir $(basename $<)).h"
	$(CP) $(basename $<).obj $(notdir $(basename $<)).obj
	$(CP) $(basename $<).mtl $(notdir $(basename $<)).mtl
	$(OBJ2HGU) $< $(notdir $(basename $<))
	$(MV) $(notdir $(basename $<)).h $(basename $<).h
	$(RM) $(notdir $(basename $<)).obj
	$(RM) $(notdir $(basename $<)).mtl

%.elf:
	$(ECHO) "[LD] $(notdir $(basename $<)).elf"
	$(LD) $^ $(LIBPATHS) $(LIBS) $(LDFLAGS) -o $@

%.prx: %.elf
	$(ECHO) "[PRX_GEN] $(notdir $(basename $<)).prx"
	#$(STRIP) $<
	$(PRX_GEN) $< $@

%.c: %.exp
	$(ECHO) "[EXPORTS] $(notdir $(basename $<)).c"
	$(BUILD_EXPORTS) -b $< > $@

test:
	cp -Rp EBOOT.PBP $(PWD)/tmp/EBOOT.PBP
	ppsspp $(PWD)/tmp/EBOOT.PBP
	rm -rf $(PWD)/tmp/EBOOT.PBP

clean:
	$(ECHO) "[CLEANING]"
	$(RM) $(PSP_EBOOT_SFO) $(TARGET).prx $(FINAL_TARGET) $(EXTRA_CLEAN) $(OBJS) $(EXTRA_TARGETS) $(EBOOT_PBP)

rebuild: clean all
