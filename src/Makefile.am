
EXTRA_DIST = secaudit.h ntfs-3g_common.h

MAINTAINERCLEANFILES = $(srcdir)/Makefile.in

if FUSE_INTERNAL
FUSE_CFLAGS = -I$(top_srcdir)/include/fuse-lite
FUSE_LIBS   = $(top_builddir)/libfuse-lite/libfuse-lite.la
else
FUSE_CFLAGS = $(FUSE_MODULE_CFLAGS)
FUSE_LIBS   = $(FUSE_MODULE_LIBS)
endif

if ENABLE_NTFS_3G

bin_PROGRAMS	 = ntfs-3g.probe \
		ntfs-3g.usermap \
		ntfs-3g.secaudit
rootbin_PROGRAMS = ntfs-3g lowntfs-3g
rootsbin_DATA 	 = #Create directory
man_MANS	 = ntfs-3g.8 ntfs-3g.probe.8 \
		ntfs-3g.usermap.8 \
		ntfs-3g.secaudit.8

ntfs_3g_LDADD    = $(FUSE_LIBS) $(top_builddir)/libntfs-3g/libntfs-3g.la
if REALLYSTATIC
ntfs_3g_LDFLAGS  = $(AM_LDFLAGS) -all-static
endif
ntfs_3g_CFLAGS   =			\
	$(AM_CFLAGS) 			\
	-DFUSE_USE_VERSION=26 		\
	$(FUSE_CFLAGS) 			\
	-I$(top_srcdir)/include/ntfs-3g
ntfs_3g_SOURCES  = ntfs-3g.c ntfs-3g_common.c

lowntfs_3g_LDADD    = $(FUSE_LIBS) $(top_builddir)/libntfs-3g/libntfs-3g.la
if REALLYSTATIC
lowntfs_3g_LDFLAGS  = $(AM_LDFLAGS) -all-static
endif
lowntfs_3g_CFLAGS   =			\
	$(AM_CFLAGS) 			\
	-DFUSE_USE_VERSION=26 		\
	$(FUSE_CFLAGS) 			\
	-I$(top_srcdir)/include/ntfs-3g
lowntfs_3g_SOURCES  = lowntfs-3g.c ntfs-3g_common.c

ntfs_3g_probe_LDADD 	= $(top_builddir)/libntfs-3g/libntfs-3g.la
ntfs_3g_usermap_LDADD 	= $(top_builddir)/libntfs-3g/libntfs-3g.la
ntfs_3g_secaudit_LDADD 	= $(top_builddir)/libntfs-3g/libntfs-3g.la
if REALLYSTATIC
ntfs_3g_probe_LDFLAGS	= $(AM_LDFLAGS) -all-static
ntfs_3g_usermap_LDFLAGS	= $(AM_LDFLAGS) -all-static
ntfs_3g_secaudit_LDFLAGS	= $(AM_LDFLAGS) -all-static
endif
ntfs_3g_probe_CFLAGS  	= $(AM_CFLAGS) -I$(top_srcdir)/include/ntfs-3g
ntfs_3g_usermap_CFLAGS  	= $(AM_CFLAGS) -I$(top_srcdir)/include/ntfs-3g
ntfs_3g_secaudit_CFLAGS  	= $(AM_CFLAGS) -I$(top_srcdir)/include/ntfs-3g
ntfs_3g_probe_SOURCES 	= ntfs-3g.probe.c
ntfs_3g_usermap_SOURCES 	= usermap.c
ntfs_3g_secaudit_SOURCES 	= secaudit.c

drivers : $(FUSE_LIBS) ntfs-3g lowntfs-3g

if RUN_LDCONFIG
install-exec-hook:
	$(LDCONFIG)
endif

if ENABLE_MOUNT_HELPER
install-exec-local:	install-rootbinPROGRAMS
	$(MKDIR_P) "$(DESTDIR)/sbin"
	$(LN_S) -f "$(rootbindir)/ntfs-3g" "$(DESTDIR)/sbin/mount.ntfs-3g"
	$(LN_S) -f "$(rootbindir)/lowntfs-3g" "$(DESTDIR)/sbin/mount.lowntfs-3g"
<<<<<<< HEAD
=======
endif
>>>>>>> 2111ad7... Initial import of ntfs-3g_ntfsprogs-2013.1.13

install-data-local:	install-man8
	$(LN_S) -f ntfs-3g.8 "$(DESTDIR)$(man8dir)/mount.ntfs-3g.8"
	$(LN_S) -f ntfs-3g.8 "$(DESTDIR)$(man8dir)/mount.lowntfs-3g.8"

uninstall-local:
	$(RM) -f "$(DESTDIR)$(man8dir)/mount.ntfs-3g.8"
<<<<<<< HEAD
=======
if ENABLE_MOUNT_HELPER
>>>>>>> 2111ad7... Initial import of ntfs-3g_ntfsprogs-2013.1.13
	$(RM) -f "$(DESTDIR)/sbin/mount.ntfs-3g" "$(DESTDIR)/sbin/mount.lowntfs-3g"
endif

endif # ENABLE_NTFS_3G
