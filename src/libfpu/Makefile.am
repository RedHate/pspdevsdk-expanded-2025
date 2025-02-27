
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS =  sceFpu_0000.o \
sceFpu_0001.o \
sceFpu_0002.o \
sceFpu_0003.o \
sceFpu_0004.o \
sceFpu_0005.o \
sceFpu_0006.o \
sceFpu_0007.o \
sceFpu_0008.o \
sceFpu_0009.o \
sceFpu_0010.o \
sceFpu_0011.o \
sceFpu_0012.o \
sceFpu_0013.o \
sceFpu_0014.o \
sceFpu_0015.o \
sceFpu_0016.o \
sceFpu_0017.o \
sceFpu_0018.o \
sceFpu_0019.o \
sceFpu_0020.o \
sceFpu_0021.o \
sceFpu_0022.o \
sceFpu_0023.o \
sceFpu_0024.o \
sceFpu_0025.o \
sceFpu_0026.o \
sceFpu_0027.o \
sceFpu_0028.o \
sceFpu_0029.o \
sceFpu_0030.o \
sceFpu_0031.o \
sceFpu_0032.o \
sceFpu_0033.o \
sceFpu_0034.o \
sceFpu_0035.o \
sceFpu_0036.o \
sceFpu_0037.o \
sceFpu_0038.o \
sceFpu_0039.o \
sceFpu_0040.o \
sceFpu_0041.o \
sceFpu_0042.o \
sceFpu_0043.o \
sceFpu_0044.o \
sceFpu_0045.o

libpspfpu_realincludedir = @PSPSDK_INCLUDEDIR@
libpspfpu_realinclude_HEADERS = pspfpu_real.h

lib_LIBRARIES = libpspfpu_real.a

libpspfpu_real_a_SOURCES = sceFpu.S
libpspfpu_real_a_LIBADD = $(OBJS)

$(OBJS): sceFpu.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@


