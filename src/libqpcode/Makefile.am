
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS 			= sceQPrintable_0000.o sceQPrintable_0001.o sceQPrintable_0002.o sceQPrintable_0003.o sceQPrintable_0004.o

libpspqpcodeincludedir = @PSPSDK_INCLUDEDIR@
libpspqpcodeinclude_HEADERS = pspqpcode.h

lib_LIBRARIES = libpspqpcode.a

libpspqpcode_a_SOURCES = sceQPrintable.S
libpspqpcode_a_LIBADD = $(OBJS)

$(OBJS): sceQPrintable.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@
