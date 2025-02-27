
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS = sceSha512_0000.o sceSha512_0001.o sceSha512_0002.o sceSha512_0003.o sceSha512_0004.o 

libpspsha512includedir = @PSPSDK_INCLUDEDIR@
libpspsha512include_HEADERS = pspsha512.h

lib_LIBRARIES = libpspsha512.a

libpspsha512_a_SOURCES = sceSha512.S
libpspsha512_a_LIBADD = $(OBJS)

$(OBJS): sceSha512.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@
