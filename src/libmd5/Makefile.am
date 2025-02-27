
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS 			= sceMd5_0000.o sceMd5_0001.o sceMd5_0002.o sceMd5_0003.o sceMd5_0004.o

libpspmd5includedir = @PSPSDK_INCLUDEDIR@
libpspmd5include_HEADERS = pspmd5.h

lib_LIBRARIES = libpspmd5.a

libpspmd5_a_SOURCES = sceMd5.S
libpspmd5_a_LIBADD = $(OBJS)

$(OBJS): sceMd5.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@
