diff -ur fuse-ext2/fuse-ext2.h.orig fuse-ext2/fuse-ext2.h
--- fuse-ext2/fuse-ext2.h.orig	2011-07-31 01:02:09.000000000 +0300
+++ fuse-ext2/fuse-ext2.h	2011-07-31 01:02:32.000000000 +0300
@@ -30,6 +30,7 @@
 #include <assert.h>
 #include <dirent.h>
 #include <errno.h>
+#include <unistd.h>
 
 #include <fuse.h>
 #include <ext2fs/ext2fs.h>
