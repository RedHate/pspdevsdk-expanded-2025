
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS =  sceAdler_0000.o sceAdler_0001.o

libpspadlerincludedir = @PSPSDK_INCLUDEDIR@
libpspadlerinclude_HEADERS = pspadler.h

lib_LIBRARIES = libpspadler.a

libpspadler_a_SOURCES = sceAdler.S
libpspadler_a_LIBADD = $(OBJS)

$(OBJS): sceAdler.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@

	

