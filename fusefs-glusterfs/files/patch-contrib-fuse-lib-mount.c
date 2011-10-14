--- contrib/fuse-lib/mount.c.orig	2011-07-14 15:21:10.000000000 +0300
+++ contrib/fuse-lib/mount.c	2011-08-07 20:12:39.166935600 +0300
@@ -20,7 +20,7 @@
 #include <fcntl.h>
 #include <errno.h>
 #include <dirent.h>
-#include <mntent.h>
+#include <signal.h>
 #include <sys/stat.h>
 #include <sys/poll.h>
 #include <sys/socket.h>
@@ -58,6 +58,7 @@
  * - there are some other minor things
  */
 
+#if !defined(__NetBSD__) && !defined(__FreeBSD__)
 static int
 mtab_needs_update (const char *mnt)
 {
@@ -91,6 +92,9 @@
 
         return 1;
 }
+#else /* __NetBSD__ */
+#define mtab_needs_update(x) 1
+#endif /* __NetBSD__ */
 
 #ifndef FUSE_UTIL
 static
@@ -365,6 +369,7 @@
         sigset_t blockmask;
         sigset_t oldmask;
 
+#if !defined(__FreeBSD__)
         if (!mtab_needs_update (abs_mnt)) {
                 res = umount2 (rel_mnt, lazy ? 2 : 0);
                 if (res == -1)
@@ -372,6 +377,7 @@
                                        progname, abs_mnt, strerror (errno));
                 return res;
         }
+#endif
 
         sigemptyset (&blockmask);
         sigaddset (&blockmask, SIGCHLD);
@@ -494,9 +500,11 @@
                 return;
         }
 
+#if !defined(__FreeBSD__)
         res = umount2 (mountpoint, 2);
         if (res == 0)
                 return;
+#endif
 
         pid = fork ();
         if (pid == -1)
@@ -518,6 +526,7 @@
  */
 
 #ifndef FUSE_UTIL
+#if !defined(__FreeBSD__)
 static int
 fuse_mount_sys (const char *mountpoint, char *fsname, char *mnt_param)
 {
@@ -594,6 +603,7 @@
                 FREE (source);
         return fd;
 }
+#endif
 
 static char *
 escape (char *s)
@@ -631,12 +641,14 @@
         char *fm_mnt_params = NULL, *p = NULL;
         char *efsname = NULL;
 
+#if !defined(__FreeBSD__)
         fd = fuse_mount_sys (mountpoint, fsname, mnt_param);
         if (fd == -1) {
                 gf_log ("glusterfs-fuse", GF_LOG_INFO,
                         "direct mount failed (%s), "
                         "retry to mount via fusermount",
                         strerror (errno));
+#endif
 
                 efsname = escape (fsname);
                 if (!efsname) {
@@ -667,7 +679,9 @@
 
                 if (fd == -1)
                        GFFUSE_LOGERR ("mount failed");
+#if !defined(__FreeBSD__)
         }
+#endif
 
         return fd;
 }
