
pspsdkincludedir = @PSPSDK_INCLUDEDIR@

pspsdkinclude_HEADERS =		\
	as_reg_compat.h		\
	psptypes.h		\
	pspstub.s		\
	pspimport.s

## Install the build.mak fragment to $PSPSDK/lib.
buildmakdir = @PSPSDK_LIBDIR@
buildmak_DATA = build.mak prxspecs

buildmakprxdir = @PSPSDK_LIBDIR@
buildmakprx_DATA = build_prx.mak linkfile.prx

buildmakisodir = @PSPSDK_LIBDIR@
buildmakiso_DATA = build_iso.mak linkfile.prx

## Install the cmake toolchain config to $PSPDEV/share
buildmakcmakedir = @PSPDEV_SHAREDIR@
buildmakcmake_DATA = pspdev.cmake CreatePBP.cmake AddPrxModule.cmake

EXTRA_DIST = build.mak build_prx.mak build_iso.mak prxspecs linkfile.prx pspdev.cmake
