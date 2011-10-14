diff -ur e2fsprogs-1.41.9/ext2fs/tdb.c.orig e2fsprogs-1.41.9/ext2fs/tdb.c
--- e2fsprogs-1.41.9/ext2fs/tdb.c.orig	2011-07-31 01:02:09.000000000 +0300
+++ e2fsprogs-1.41.9/ext2fs/tdb.c	2011-07-31 01:02:21.000000000 +0300
@@ -55,7 +55,6 @@
 #include <utime.h>
 #endif
 #include <sys/stat.h>
-#include <sys/file.h>
 #include <fcntl.h>
 
 #ifdef HAVE_SYS_MMAN_H
