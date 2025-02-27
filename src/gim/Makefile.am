
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

GIM_OBJS = sceGim_0000.o sceGim_0001.o sceGim_0002.o sceGim_0003.o sceGim_0004.o sceGim_0005.o sceGim_0006.o sceGim_0007.o sceGim_0008.o sceGim_0009.o sceGim_0010.o sceGim_0011.o sceGim_0012.o sceGim_0013.o sceGim_0014.o sceGim_0015.o sceGim_0016.o sceGim_0017.o sceGim_0018.o sceGim_0019.o sceGim_0020.o sceGim_0021.o sceGim_0022.o sceGim_0023.o sceGim_0024.o sceGim_0025.o sceGim_0026.o sceGim_0027.o sceGim_0028.o sceGim_0029.o sceGim_0030.o sceGim_0031.o sceGim_0032.o sceGim_0033.o sceGim_0034.o sceGim_0035.o sceGim_0036.o sceGim_0037.o sceGim_0038.o sceGim_0039.o sceGim_0040.o sceGim_0041.o sceGim_0042.o sceGim_0043.o sceGim_0044.o sceGim_0045.o sceGim_0046.o sceGim_0047.o sceGim_0048.o sceGim_0049.o sceGim_0050.o sceGim_0051.o sceGim_0052.o sceGim_0053.o sceGim_0054.o sceGim_0055.o sceGim_0056.o sceGim_0057.o sceGim_0058.o sceGim_0059.o sceGim_0060.o sceGim_0061.o sceGim_0062.o sceGim_0063.o sceGim_0064.o sceGim_0065.o sceGim_0066.o sceGim_0067.o sceGim_0068.o sceGim_0069.o sceGim_0070.o sceGim_0071.o sceGim_0072.o sceGim_0073.o sceGim_0074.o sceGim_0075.o sceGim_extras.o

libpspgimincludedir = @PSPSDK_INCLUDEDIR@
libpspgiminclude_HEADERS = pspgim_format.h  pspgim_picture.h  pspgim_protected.h pspgim_private.h

lib_LIBRARIES = libpspgim.a

libpspgim_a_SOURCES = sceGim.S
libpspgim_a_LIBADD = $(GIM_OBJS)

$(GIM_OBJS): sceGim.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@
