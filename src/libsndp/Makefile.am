
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS = sceSs_0000.o sceSs_0001.o sceSs_0002.o sceSs_0003.o sceSs_0004.o sceSs_0005.o sceSs_0006.o sceSs_0007.o sceSs_0008.o sceSs_0009.o sceSs_0010.o sceSs_0011.o sceSs_0012.o sceSs_0013.o sceSs_0014.o sceSs_0015.o sceSs_0016.o sceSs_0017.o sceSs_0018.o sceSs_0019.o sceSs_0020.o sceSs_0021.o sceSs_0022.o sceSs_0023.o sceSs_0024.o sceSs_0025.o sceSs_0026.o sceSs_0027.o sceSs_0028.o sceSs_0029.o sceSs_0030.o sceSs_0031.o sceSs_0032.o sceSs_0033.o sceSs_0034.o sceSs_0035.o sceSs_0036.o sceSs_0037.o sceSs_0038.o sceSs_0039.o sceSs_0040.o sceSs_0041.o sceSs_0042.o sceSs_0043.o sceSs_0044.o sceSs_0045.o sceSs_0046.o sceSs_0047.o sceSs_0048.o sceSs_0049.o sceSs_0050.o sceSs_0051.o 


libpspsndpincludedir = @PSPSDK_INCLUDEDIR@
libpspsndpinclude_HEADERS = pspsndp.h

lib_LIBRARIES = libpspsndp.a

libpspsndp_a_SOURCES = sceSs.S
libpspsndp_a_LIBADD = $(OBJS)

$(OBJS): sceSs.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@
