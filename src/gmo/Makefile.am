
libdir = @PSPSDK_LIBDIR@

CC = @PSP_CC@
CCAS = $(CC)
AR = @PSP_AR@
RANLIB = @PSP_RANLIB@

CPPFLAGS = -I$(top_srcdir)/src/base -I$(top_srcdir)/src/kernel
CFLAGS = @PSPSDK_CFLAGS@
CCASFLAGS = $(CFLAGS)

GMO_OBJS = sceGmo_0000.o sceGmo_0001.o sceGmo_0002.o sceGmo_0003.o sceGmo_0004.o sceGmo_0005.o sceGmo_0006.o sceGmo_0007.o sceGmo_0008.o sceGmo_0009.o sceGmo_0010.o sceGmo_0011.o sceGmo_0012.o sceGmo_0013.o sceGmo_0014.o sceGmo_0015.o sceGmo_0016.o sceGmo_0017.o sceGmo_0018.o sceGmo_0019.o sceGmo_0020.o sceGmo_0021.o sceGmo_0022.o sceGmo_0023.o sceGmo_0024.o sceGmo_0025.o sceGmo_0026.o sceGmo_0027.o sceGmo_0028.o sceGmo_0029.o sceGmo_0030.o sceGmo_0031.o sceGmo_0032.o sceGmo_0033.o sceGmo_0034.o sceGmo_0035.o sceGmo_0036.o sceGmo_0037.o sceGmo_0038.o sceGmo_0039.o sceGmo_0040.o sceGmo_0041.o sceGmo_0042.o sceGmo_0043.o sceGmo_0044.o sceGmo_0045.o sceGmo_0046.o sceGmo_0047.o sceGmo_0048.o sceGmo_0049.o sceGmo_0050.o sceGmo_0051.o sceGmo_0052.o sceGmo_0053.o sceGmo_0054.o sceGmo_0055.o sceGmo_0056.o sceGmo_0057.o sceGmo_0058.o sceGmo_0059.o sceGmo_0060.o sceGmo_0061.o sceGmo_0062.o sceGmo_0063.o sceGmo_0064.o sceGmo_0065.o sceGmo_0066.o sceGmo_0067.o sceGmo_0068.o sceGmo_0069.o sceGmo_0070.o sceGmo_0071.o sceGmo_0072.o sceGmo_0073.o sceGmo_0074.o sceGmo_0075.o sceGmo_0076.o sceGmo_0077.o sceGmo_0078.o sceGmo_0079.o sceGmo_0080.o sceGmo_0081.o sceGmo_0082.o sceGmo_0083.o sceGmo_0084.o sceGmo_0085.o sceGmo_0086.o sceGmo_0087.o sceGmo_0088.o sceGmo_0089.o sceGmo_0090.o sceGmo_0091.o sceGmo_0092.o sceGmo_0093.o sceGmo_0094.o sceGmo_0095.o sceGmo_0096.o sceGmo_0097.o sceGmo_0098.o sceGmo_0099.o sceGmo_0100.o sceGmo_0101.o sceGmo_0102.o sceGmo_0103.o sceGmo_0104.o sceGmo_0105.o sceGmo_0106.o sceGmo_0107.o sceGmo_0108.o sceGmo_0109.o sceGmo_0110.o sceGmo_0111.o sceGmo_0112.o sceGmo_0113.o sceGmo_0114.o sceGmo_0115.o sceGmo_0116.o sceGmo_0117.o sceGmo_0118.o sceGmo_0119.o sceGmo_0120.o sceGmo_0121.o sceGmo_0122.o sceGmo_0123.o sceGmo_0124.o sceGmo_0125.o sceGmo_0126.o sceGmo_0127.o sceGmo_0128.o sceGmo_0129.o sceGmo_0130.o sceGmo_0131.o sceGmo_0132.o sceGmo_0133.o sceGmo_0134.o sceGmo_0135.o sceGmo_0136.o sceGmo_0137.o sceGmo_0138.o sceGmo_0139.o sceGmo_0140.o sceGmo_0141.o sceGmo_0142.o sceGmo_0143.o sceGmo_0144.o sceGmo_0145.o sceGmo_0146.o sceGmo_0147.o sceGmo_0148.o sceGmo_0149.o sceGmo_0150.o sceGmo_0151.o sceGmo_0152.o sceGmo_0153.o sceGmo_0154.o sceGmo_0155.o sceGmo_0156.o sceGmo_0157.o sceGmo_0158.o sceGmo_0159.o sceGmo_0160.o sceGmo_0161.o sceGmo_0162.o sceGmo_0163.o sceGmo_0164.o sceGmo_0165.o sceGmo_0166.o sceGmo_0167.o sceGmo_0168.o sceGmo_0169.o sceGmo_0170.o sceGmo_extras.o 

libpspgmoincludedir = @PSPSDK_INCLUDEDIR@
libpspgmoinclude_HEADERS = pspgmo_format.h pspgmo_model.h pspgmo_types.h pspgmo_metrics.h pspgmo_protected.h

lib_LIBRARIES = libpspgmo.a


libpspgmo_a_SOURCES = sceGmo.S
libpspgmo_a_LIBADD = $(GMO_OBJS)

$(GMO_OBJS): sceGmo.S
	$(AM_V_CPPAS)$(CPPASCOMPILE) -DF_$* $< -c -o $@
