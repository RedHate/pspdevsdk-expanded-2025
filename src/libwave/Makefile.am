
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS = sceWave_0000.o sceWave_0001.o sceWave_0002.o sceWave_0003.o sceWave_0004.o sceWave_0005.o sceWave_0006.o sceWave_0007.o sceWave_0008.o sceWave_0009.o sceWave_0010.o sceWave_0011.o sceWave_0012.o sceWave_0013.o sceWave_0014.o sceWave_0015.o sceWave_0016.o sceWave_0017.o sceWave_0018.o sceWave_0019.o sceWave_0020.o sceWave_0021.o sceWave_0022.o sceWave_0023.o sceWave_0024.o 

libpspwaveincludedir = @PSPSDK_INCLUDEDIR@
libpspwaveinclude_HEADERS = pspwave.h

lib_LIBRARIES = libpspwave.a

libpspwave_a_SOURCES = sceWave.S
libpspwave_a_LIBADD = $(OBJS)

$(OBJS): sceWave.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@

