
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS = sceSha256_0000.o sceSha256_0001.o sceSha256_0002.o sceSha256_0003.o sceSha256_0004.o 

libpspsha256includedir = @PSPSDK_INCLUDEDIR@
libpspsha256include_HEADERS = pspsha256.h

lib_LIBRARIES = libpspsha256.a

libpspsha256_a_SOURCES = sceSha256.S
libpspsha256_a_LIBADD = $(OBJS)

$(OBJS): sceSha256.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@
