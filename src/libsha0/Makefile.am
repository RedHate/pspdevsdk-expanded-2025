
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS = sceSha0_0000.o sceSha0_0001.o sceSha0_0002.o sceSha0_0003.o sceSha0_0004.o 

libpspsha0includedir = @PSPSDK_INCLUDEDIR@
libpspsha0include_HEADERS = pspsha0.h

lib_LIBRARIES = libpspsha0.a

libpspsha0_a_SOURCES = sceSha0.S
libpspsha0_a_LIBADD = $(OBJS)

$(OBJS): sceSha0.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@
