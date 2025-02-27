
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

OBJS =  sceHttp_0000.o sceHttp_0001.o sceHttp_0002.o sceHttp_0003.o sceHttp_0004.o sceHttp_0005.o sceHttp_0006.o sceHttp_0007.o sceHttp_0008.o sceHttp_0009.o sceHttp_0010.o sceHttp_0011.o sceHttp_0012.o sceHttp_0013.o sceHttp_0014.o sceHttp_0015.o sceHttp_0016.o sceHttp_0017.o sceHttp_0018.o sceHttp_0019.o sceHttp_0020.o sceHttp_0021.o sceHttp_0022.o sceHttp_0023.o sceHttp_0024.o sceHttp_0025.o sceHttp_0026.o sceHttp_0027.o sceHttp_0028.o sceHttp_0029.o sceHttp_0030.o sceHttp_0031.o sceHttp_0032.o sceHttp_0033.o sceHttp_0034.o sceHttp_0035.o sceHttp_0036.o sceHttp_0037.o sceHttp_0038.o sceHttp_0039.o sceHttp_0040.o sceHttp_0041.o sceHttp_0042.o sceHttp_0043.o sceHttp_0044.o sceHttp_0045.o sceHttp_0046.o sceHttp_0047.o sceHttp_0048.o sceHttp_0049.o sceHttp_0050.o sceHttp_0051.o sceHttp_0052.o sceHttp_0053.o sceHttp_0054.o sceHttp_0055.o sceHttp_0056.o sceHttp_0057.o sceHttp_0058.o sceHttp_0059.o sceHttp_0060.o sceHttp_0061.o sceHttp_0062.o sceHttp_0063.o sceHttp_0064.o sceHttp_0065.o sceHttp_0066.o sceHttp_0067.o sceHttp_0068.o sceHttp_0069.o sceHttp_0070.o sceHttp_0071.o sceHttp_0072.o sceHttp_0073.o sceHttp_0074.o sceHttp_0075.o sceHttp_0076.o sceHttp_0077.o sceHttp_0078.o sceHttp_0079.o sceHttp_0080.o sceHttp_0081.o sceHttp_0082.o sceHttp_0083.o

libpsphttpincludedir = @PSPSDK_INCLUDEDIR@
libpsphttpinclude_HEADERS = psphttp.h

lib_LIBRARIES = libpsphttp.a

libpsphttp_a_SOURCES = sceHttp.S
libpsphttp_a_LIBADD = $(OBJS)

$(OBJS): sceHttp.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@

