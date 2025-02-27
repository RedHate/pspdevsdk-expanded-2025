
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS =  sceDeflt_0000.o\
sceDeflt_0001.o\
sceDeflt_0002.o\
sceDeflt_0003.o\
sceDeflt_0004.o\
sceDeflt_0005.o\
sceDeflt_0006.o\
sceDeflt_0007.o\
sceDeflt_0008.o\
sceDeflt_0009.o\
sceDeflt_0010.o\
sceDeflt_0011.o\
sceDeflt_0012.o\
sceDeflt_0013.o\
sceDeflt_0014.o

libpspdefltincludedir = @PSPSDK_INCLUDEDIR@
libpspdefltinclude_HEADERS = pspdeflt.h

lib_LIBRARIES = libpspdeflt.a

libpspdeflt_a_SOURCES = sceDeflt.S
libpspdeflt_a_LIBADD = $(OBJS)

$(OBJS): sceDeflt.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@

