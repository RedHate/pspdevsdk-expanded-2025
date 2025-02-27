
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS = scePsmf_0000.o scePsmf_0001.o scePsmf_0002.o scePsmf_0003.o scePsmf_0004.o scePsmf_0005.o scePsmf_0006.o scePsmf_0007.o scePsmf_0008.o scePsmf_0009.o scePsmf_0010.o scePsmf_0011.o scePsmf_0012.o scePsmf_0013.o scePsmf_0014.o scePsmf_0015.o scePsmf_0016.o scePsmf_0017.o scePsmf_0018.o scePsmf_0019.o

libpsppsmfincludedir = @PSPSDK_INCLUDEDIR@
libpsppsmfinclude_HEADERS = psppsmf.h

lib_LIBRARIES = libpsppsmf.a

libpsppsmf_a_SOURCES = scePsmf.S
libpsppsmf_a_LIBADD = $(OBJS)

$(OBJS): scePsmf.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@
