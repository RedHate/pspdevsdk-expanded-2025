
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS =  sceFont_0000.o sceFont_0001.o sceFont_0002.o sceFont_0003.o sceFont_0004.o sceFont_0005.o sceFont_0006.o sceFont_0007.o sceFont_0008.o sceFont_0009.o sceFont_0010.o sceFont_0011.o sceFont_0012.o sceFont_0013.o sceFont_0014.o sceFont_0015.o sceFont_0016.o sceFont_0017.o sceFont_0018.o sceFont_0019.o sceFont_0020.o sceFont_0021.o sceFont_0022.o sceFont_0023.o sceFont_0024.o sceFont_0025.o 

libpspfontincludedir = @PSPSDK_INCLUDEDIR@
libpspfontinclude_HEADERS = pspfont.h

lib_LIBRARIES = libpspfont.a

libpspfont_a_SOURCES = sceFont.S
libpspfont_a_LIBADD = $(OBJS)

$(OBJS): sceFont.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@

