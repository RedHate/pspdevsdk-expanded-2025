
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS = sceSha384_0000.o sceSha384_0001.o sceSha384_0002.o sceSha384_0003.o sceSha384_0004.o 

libpspsha384includedir = @PSPSDK_INCLUDEDIR@
libpspsha384include_HEADERS = pspsha384.h

lib_LIBRARIES = libpspsha384.a

libpspsha384_a_SOURCES = sceSha384.S
libpspsha384_a_LIBADD = $(OBJS)

$(OBJS): sceSha384.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@
