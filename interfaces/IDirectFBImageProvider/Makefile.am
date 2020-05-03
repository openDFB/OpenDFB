## Makefile.am for DirectFB/interfaces/IDirectFBImageProvider
idirectfbimageproviderdir = $(MODULEDIR)/interfaces/IDirectFBImageProvider


if GIF_PROVIDER
GIF_PROVIDER_LTLIB = libidirectfbimageprovider_gif.la
else
GIF_PROVIDER_LTLIB =
endif

if JPEG_PROVIDER
JPEG_PROVIDER_LTLIB = libidirectfbimageprovider_jpeg.la
else
JPEG_PROVIDER_LTLIB =
endif

if PNG_PROVIDER
PNG_PROVIDER_LTLIB = libidirectfbimageprovider_png.la
else
PNG_PROVIDER_LTLIB =
endif

if PNM
PNM_PROVIDER = libidirectfbimageprovider_pnm.la
else
PNM_PROVIDER =
endif

if BMP
BMP_PROVIDER = libidirectfbimageprovider_bmp.la
else
BMP_PROVIDER =
endif


INCLUDES = \
	-I$(top_builddir)/include	\
	-I$(top_builddir)/lib	\
	-I$(top_builddir)/src	\
	-I$(top_srcdir)/include	\
	-I$(top_srcdir)/lib	\
	-I$(top_srcdir)/src

AM_CPPFLAGS = -DDATADIR=\"${RUNTIME_SYSROOT}@DATADIR@\" $(LIBJPEG_CFLAGS) $(LIBPNG_CFLAGS)

idirectfbimageprovider_LTLIBRARIES = \
	libidirectfbimageprovider_dfiff.la	\
	$(GIF_PROVIDER_LTLIB)			\
	$(JPEG_PROVIDER_LTLIB)			\
	$(PNG_PROVIDER_LTLIB)			\
	$(PNM_PROVIDER)				\
	$(BMP_PROVIDER)
	
if BUILD_STATIC
idirectfbimageprovider_DATA = $(idirectfbimageprovider_LTLIBRARIES:.la=.o)
endif


libdirect = $(top_builddir)/lib/direct/libdirect.la
libdirectfb = $(top_builddir)/src/libdirectfb.la


libidirectfbimageprovider_png_la_SOURCES = idirectfbimageprovider_png.c
libidirectfbimageprovider_png_la_LIBADD = $(libdirect) $(libdirectfb) $(LIBPNG_LIBS)
libidirectfbimageprovider_png_la_LDFLAGS = -avoid-version -module

libidirectfbimageprovider_dfiff_la_SOURCES = idirectfbimageprovider_dfiff.c
libidirectfbimageprovider_dfiff_la_LIBADD = $(libdirect) $(libdirectfb)
libidirectfbimageprovider_dfiff_la_LDFLAGS = -avoid-version -module

libidirectfbimageprovider_gif_la_SOURCES = idirectfbimageprovider_gif.c
libidirectfbimageprovider_gif_la_LIBADD = $(libdirect) $(libdirectfb)
libidirectfbimageprovider_gif_la_LDFLAGS = -avoid-version -module

libidirectfbimageprovider_jpeg_la_SOURCES = idirectfbimageprovider_jpeg.c
libidirectfbimageprovider_jpeg_la_LIBADD = $(libdirect) $(libdirectfb) $(LIBJPEG)
libidirectfbimageprovider_jpeg_la_LDFLAGS = -avoid-version -module

libidirectfbimageprovider_pnm_la_SOURCES = idirectfbimageprovider_pnm.c
libidirectfbimageprovider_pnm_la_LIBADD = $(libdirect) $(libdirectfb)
libidirectfbimageprovider_pnm_la_LDFLAGS = -avoid-version -module

libidirectfbimageprovider_bmp_la_SOURCES = idirectfbimageprovider_bmp.c
libidirectfbimageprovider_bmp_la_LIBADD = $(libdirect) $(libdirectfb)
libidirectfbimageprovider_bmp_la_LDFLAGS = -avoid-version -module

include $(top_srcdir)/rules/libobject.make
