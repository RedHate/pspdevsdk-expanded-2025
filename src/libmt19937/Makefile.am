
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS 			= sceMt19937_0000.o sceMt19937_0001.o sceMt19937_0002.o

libpspmt19937includedir = @PSPSDK_INCLUDEDIR@
libpspmt19937include_HEADERS = pspmt19937.h

lib_LIBRARIES = libpspmt19937.a

libpspmt19937_a_SOURCES = sceMt19937.S
libpspmt19937_a_LIBADD = $(OBJS)

$(OBJS): sceMt19937.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@
