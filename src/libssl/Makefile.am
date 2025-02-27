
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS = sceSsl_0000.o sceSsl_0001.o sceSsl_0002.o sceSsl_0003.o sceSsl_0004.o sceSsl_0005.o sceSsl_0006.o sceSsl_0007.o sceSsl_0008.o sceSsl_0009.o sceSsl_0010.o sceSsl_0011.o

libpspsslincludedir = @PSPSDK_INCLUDEDIR@
libpspsslinclude_HEADERS = pspssl.h

lib_LIBRARIES = libpspssl.a

libpspssl_a_SOURCES = sceSsl.S
libpspssl_a_LIBADD = $(OBJS)

$(OBJS): sceSsl.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@

