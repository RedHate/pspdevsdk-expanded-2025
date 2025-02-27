
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

JPEG_OBJS =  sceJpeg_0000.o sceJpeg_0001.o sceJpeg_0002.o sceJpeg_0003.o sceJpeg_0004.o sceJpeg_0005.o sceJpeg_0006.o sceJpeg_0007.o sceJpeg_0008.o sceJpeg_0009.o sceJpeg_0010.o sceJpeg_0011.o sceJpeg_0012.o sceJpeg_0013.o

libpspjpegincludedir = @PSPSDK_INCLUDEDIR@
libpspjpeginclude_HEADERS = pspjpeg.h

lib_LIBRARIES = libpspjpeg.a

libpspjpeg_a_SOURCES = sceJpeg.S
libpspjpeg_a_LIBADD = $(JPEG_OBJS)

$(JPEG_OBJS): sceJpeg.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@

