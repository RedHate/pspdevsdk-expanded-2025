
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS 			= sceSas_0000.o sceSas_0001.o sceSas_0002.o sceSas_0003.o sceSas_0004.o sceSas_0005.o sceSas_0006.o sceSas_0007.o sceSas_0008.o sceSas_0009.o sceSas_0010.o sceSas_0011.o sceSas_0012.o sceSas_0013.o sceSas_0014.o sceSas_0015.o sceSas_0016.o sceSas_0017.o sceSas_0018.o sceSas_0019.o 

libpspsasincludedir = @PSPSDK_INCLUDEDIR@
libpspsasinclude_HEADERS = pspsas.h

lib_LIBRARIES = libpspsas.a

libpspsas_a_SOURCES = sceSas.S
libpspsas_a_LIBADD = $(OBJS)

$(OBJS): sceSas.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@

	

