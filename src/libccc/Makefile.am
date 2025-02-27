
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS =  sceCcc_0000.o \
sceCcc_0001.o \
sceCcc_0002.o \
sceCcc_0003.o \
sceCcc_0004.o \
sceCcc_0005.o \
sceCcc_0006.o \
sceCcc_0007.o \
sceCcc_0008.o \
sceCcc_0009.o \
sceCcc_0010.o \
sceCcc_0011.o \
sceCcc_0012.o \
sceCcc_0013.o \
sceCcc_0014.o \
sceCcc_0015.o \
sceCcc_0016.o \
sceCcc_0017.o \
sceCcc_0018.o \
sceCcc_0019.o \
sceCcc_0020.o \
sceCcc_0021.o \
sceCcc_0022.o \
sceCcc_0023.o \
sceCcc_0024.o \
sceCcc_0025.o \
sceCcc_0026.o \
sceCcc_0027.o

libpspcccincludedir = @PSPSDK_INCLUDEDIR@
libpspcccinclude_HEADERS = pspccc.h

lib_LIBRARIES = libpspccc.a

libpspccc_a_SOURCES = sceCcc.S
libpspccc_a_LIBADD = $(OBJS)

$(OBJS): sceCcc.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@

