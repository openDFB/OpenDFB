## Makefile.am for DirectFB/tests

AM_CPPFLAGS = \
	-DDATADIR=\"${RUNTIME_SYSROOT}@DATADIR@\"

if ENABLE_SAWMAN
SAWMAN_PROGS = \
	testrun	\
	testman
endif

if ENABLE_DIVINE
DIVINE_PROGS = \
	divine_test
endif

INCLUDES = \
	-I$(top_builddir)/include \
	-I$(top_builddir)/lib \
	-I$(top_builddir)/lib/One \
	-I$(top_builddir)/lib/divine \
	-I$(top_builddir)/lib/fusiondale \
	-I$(top_builddir)/lib/sawman \
	-I$(top_builddir)/src	\
	-I$(top_srcdir)/include	\
	-I$(top_srcdir)/lib	\
	-I$(top_srcdir)/lib/divine	\
	-I$(top_srcdir)/lib/sawman	\
	-I$(top_srcdir)/src	\
	-DLINUX_2_6

GL_PROGS_ = \
	dfbtest_gl1	\
	dfbtest_gl2	\
	dfbtest_gl3

if GFX_GL
GL_PROGS = $(GL_PROGS_)
endif

if GFX_GLES2
GL_PROGS = $(GL_PROGS_)
endif

if DIRECTFB_BUILD_PURE_VOODOO
NON_PURE_VOODOO_PROGS = 
else
NON_PURE_VOODOO_PROGS = \
	coretest_blit2	\
	fusion_call	\
	fusion_call_bench	\
	fusion_fork	\
	fusion_reactor	\
	fusion_skirmish	\
	fusion_stream
endif

bin_PROGRAMS = \
	$(GL_PROGS)	\
	$(NON_PURE_VOODOO_PROGS)	\
	dfbtest_blit	\
	dfbtest_blit_multi	\
	dfbtest_blit_threads	\
	dfbtest_blit2	\
	dfbtest_clipboard	\
	dfbtest_fillrect	\
	dfbtest_flip	\
	dfbtest_font	\
	dfbtest_init	\
	dfbtest_input	\
	dfbtest_mirror	\
	dfbtest_prealloc	\
	dfbtest_reinit	\
	dfbtest_resize	\
	dfbtest_scale	\
	dfbtest_scale_nv21	\
	dfbtest_stereo_window	\
	dfbtest_surface_compositor	\
	dfbtest_surface_compositor_threads	\
	dfbtest_surface_updates	\
	dfbtest_sync	\
	dfbtest_video	\
	dfbtest_waitserial	\
	dfbtest_window	\
	dfbtest_window_cursor	\
	dfbtest_window_flip	\
	dfbtest_window_flip_once	\
	dfbtest_window_surface	\
	dfbtest_windows_watcher	\
	direct_stream	\
	direct_test	\
	$(SAWMAN_PROGS) \
	$(DIVINE_PROGS)


# for DFB_BASE_LIBS etc...
include $(top_srcdir)/rules/libs_deps.make


coretest_blit2_SOURCES = coretest_blit2.c
coretest_blit2_LDADD   = $(DFB_BASE_LIBS)

dfbtest_blit_SOURCES = dfbtest_blit.c
dfbtest_blit_LDADD   = $(DFB_BASE_LIBS)

dfbtest_blit_multi_SOURCES = dfbtest_blit_multi.c
dfbtest_blit_multi_LDADD   = $(DFB_BASE_LIBS)

dfbtest_blit_threads_SOURCES = dfbtest_blit_threads.c
dfbtest_blit_threads_LDADD   = $(DFB_BASE_LIBS)

dfbtest_blit2_SOURCES = dfbtest_blit2.c
dfbtest_blit2_LDADD   = $(DFB_BASE_LIBS)

dfbtest_clipboard_SOURCES = dfbtest_clipboard.c
dfbtest_clipboard_LDADD   = $(DFB_BASE_LIBS)

dfbtest_fillrect_SOURCES = dfbtest_fillrect.c
dfbtest_fillrect_LDADD   = $(DFB_BASE_LIBS)

dfbtest_flip_SOURCES = dfbtest_flip.c
dfbtest_flip_LDADD   = $(DFB_BASE_LIBS)

dfbtest_font_SOURCES = dfbtest_font.c
dfbtest_font_LDADD   = $(DFB_BASE_LIBS)

dfbtest_init_SOURCES = dfbtest_init.c
dfbtest_init_LDADD   = $(DFB_BASE_LIBS)

dfbtest_input_SOURCES = dfbtest_input.c
dfbtest_input_LDADD   = $(DFB_BASE_LIBS)

dfbtest_gl1_SOURCES = dfbtest_gl1.c
dfbtest_gl1_CFLAGS  = $(GLES2_CFLAGS)
dfbtest_gl1_LDADD   = $(DFB_BASE_LIBS) $(GL_DFB_BASE_LIBS) $(GLES2_DFB_BASE_LIBS)

dfbtest_gl2_SOURCES = dfbtest_gl2.c
dfbtest_gl2_CFLAGS  = $(GLES2_CFLAGS)
dfbtest_gl2_LDADD   = $(DFB_BASE_LIBS) $(GL_DFB_BASE_LIBS) $(GLES2_DFB_BASE_LIBS) $(LIBM)

dfbtest_gl3_SOURCES = dfbtest_gl3.c
dfbtest_gl3_CFLAGS  = $(GLES2_CFLAGS)
dfbtest_gl3_LDADD   = $(DFB_BASE_LIBS) $(GL_DFB_BASE_LIBS) $(GLES2_DFB_BASE_LIBS) $(LIBM)

dfbtest_mirror_SOURCES = dfbtest_mirror.c
dfbtest_mirror_LDADD   = $(DFB_BASE_LIBS)

dfbtest_prealloc_SOURCES = dfbtest_prealloc.c
dfbtest_prealloc_LDADD   = $(DFB_BASE_LIBS)

dfbtest_reinit_SOURCES = dfbtest_reinit.c
dfbtest_reinit_LDADD   = $(DFB_BASE_LIBS)

dfbtest_resize_SOURCES = dfbtest_resize.c
dfbtest_resize_LDADD   = $(DFB_BASE_LIBS)

dfbtest_scale_SOURCES = dfbtest_scale.c
dfbtest_scale_LDADD   = $(DFB_BASE_LIBS)

dfbtest_scale_nv21_SOURCES = dfbtest_scale_nv21.c
dfbtest_scale_nv21_LDADD   = $(DFB_BASE_LIBS)

dfbtest_stereo_window_SOURCES = dfbtest_stereo_window.c
dfbtest_stereo_window_LDADD   = $(DFB_BASE_LIBS)

dfbtest_surface_compositor_SOURCES = dfbtest_surface_compositor.c
dfbtest_surface_compositor_LDADD   = $(DFB_BASE_LIBS)

dfbtest_surface_compositor_threads_SOURCES = dfbtest_surface_compositor_threads.c
dfbtest_surface_compositor_threads_LDADD   = $(DFB_BASE_LIBS)

dfbtest_surface_updates_SOURCES = dfbtest_surface_updates.c
dfbtest_surface_updates_LDADD   = $(DFB_BASE_LIBS)

dfbtest_sync_SOURCES = dfbtest_sync.c
dfbtest_sync_LDADD   = $(DFB_BASE_LIBS)

dfbtest_video_SOURCES = dfbtest_video.c
dfbtest_video_LDADD   = $(DFB_BASE_LIBS)

dfbtest_waitserial_SOURCES = dfbtest_waitserial.c
dfbtest_waitserial_LDADD   = $(DFB_BASE_LIBS)

dfbtest_window_SOURCES = dfbtest_window.c
dfbtest_window_LDADD   = $(DFB_BASE_LIBS)

dfbtest_window_cursor_SOURCES = dfbtest_window_cursor.c
dfbtest_window_cursor_LDADD   = $(DFB_BASE_LIBS)

dfbtest_window_flip_SOURCES = dfbtest_window_flip.c
dfbtest_window_flip_LDADD   = $(DFB_BASE_LIBS)

dfbtest_window_flip_once_SOURCES = dfbtest_window_flip_once.c
dfbtest_window_flip_once_LDADD   = $(DFB_BASE_LIBS)

dfbtest_window_surface_SOURCES = dfbtest_window_surface.c
dfbtest_window_surface_LDADD   = $(DFB_BASE_LIBS)

dfbtest_windows_watcher_SOURCES = dfbtest_windows_watcher.c
dfbtest_windows_watcher_LDADD   = $(DFB_BASE_LIBS)


direct_stream_SOURCES = direct_stream.c
direct_stream_LDADD   = $(libdirect)

direct_test_SOURCES = direct_test.c
direct_test_LDADD   = $(libdirect)


fusion_call_SOURCES = fusion_call.c
fusion_call_LDADD   = $(DFB_BASE_LIBS)

fusion_call_bench_SOURCES = fusion_call_bench.c
fusion_call_bench_LDADD   = $(DFB_BASE_LIBS)

fusion_fork_SOURCES = fusion_fork.c
fusion_fork_LDADD   = $(DFB_BASE_LIBS)

fusion_reactor_SOURCES = fusion_reactor.c
fusion_reactor_LDADD   = $(DFB_BASE_LIBS)

fusion_skirmish_SOURCES = fusion_skirmish.c
fusion_skirmish_LDADD   = $(DFB_BASE_LIBS)

fusion_stream_SOURCES = fusion_stream.c
fusion_stream_LDADD   = $(DFB_BASE_LIBS)

testman_SOURCES = testman.c
testman_LDADD   = $(DFB_BASE_LIBS) $(libsawman)

testrun_SOURCES = testrun.c
testrun_LDADD   = $(DFB_BASE_LIBS) $(libsawman)
divine_test_SOURCES = divine_test.c
divine_test_LDADD   = $(DFB_BASE_LIBS) $(libdivine)
