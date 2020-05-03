## Makefile.am for DirectFB/gfxdrivers
if GFX_DAVINCI
DAVINCI_DIR = davinci
else
DAVINCI_DIR =
endif

if GFX_GLES2
GLES2_DIR = gles2
else
GLES2_DIR =
endif

if GFX_I810
I810_DIR = i810
else
I810_DIR =
endif

if GFX_I830
I830_DIR = i830
else
I830_DIR =
endif

if GFX_OMAP
OMAP_DIR = omap
else
OMAP_DIR =
endif

if GFX_PVR2D
PVR2D_DIR = pvr2d
else
PVR2D_DIR =
endif

if GFX_VDPAU
VDPAU_DIR = vdpau
else
VDPAU_DIR =
endif

if GFX_VMWARE
VMWARE_DIR = vmware
else
VMWARE_DIR =
endif


SUBDIRS = \
	$(GLES2_DIR)	\
	$(I810_DIR)	\
	$(I830_DIR)	\
	$(OMAP_DIR)	\
	$(PVR2D_DIR)	\
	$(VDPAU_DIR)	\
	$(VMWARE_DIR)
