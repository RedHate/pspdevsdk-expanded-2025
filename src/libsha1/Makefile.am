
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS = sceSha1_0000.o sceSha1_0001.o sceSha1_0002.o sceSha1_0003.o sceSha1_0004.o 

libpspsha1includedir = @PSPSDK_INCLUDEDIR@
libpspsha1include_HEADERS = pspsha1.h

lib_LIBRARIES = libpspsha1.a

libpspsha1_a_SOURCES = sceSha1.S
libpspsha1_a_LIBADD = $(OBJS)

$(OBJS): sceSha1.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@
