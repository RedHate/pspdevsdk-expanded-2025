
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS =  sceBase64_0000.o sceBase64_0001.o sceBase64_0002.o

libpspbase64includedir = @PSPSDK_INCLUDEDIR@
libpspbase64include_HEADERS = pspbase64.h

lib_LIBRARIES = libpspbase64.a

libpspbase64_a_SOURCES = sceBase64.S
libpspbase64_a_LIBADD = $(OBJS)

$(OBJS): sceBase64.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@

