
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS = sceSha224_0000.o sceSha224_0001.o sceSha224_0002.o sceSha224_0003.o sceSha224_0004.o 

libpspsha224includedir = @PSPSDK_INCLUDEDIR@
libpspsha224include_HEADERS = pspsha224.h

lib_LIBRARIES = libpspsha224.a

libpspsha224_a_SOURCES = sceSha224.S
libpspsha224_a_LIBADD = $(OBJS)

$(OBJS): sceSha224.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@
