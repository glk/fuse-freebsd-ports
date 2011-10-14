diff -ur fuse-ext2/fuse-ext2.c.orig fuse-ext2/fuse-ext2.c
--- fuse-ext2/fuse-ext2.c.orig	2009-11-09 17:28:02.000000000 +0200
+++ fuse-ext2/fuse-ext2.c	2011-07-31 19:30:47.000000000 +0300
@@ -321,7 +321,7 @@
 	struct fuse_args fargs = FUSE_ARGS_INIT(0, NULL);
 	struct extfs_data opts;
 
-	debugf("version:'%s', fuse_version:'%d'", VERSION, fuse_version());
+	debugf_main("version:'%s', fuse_version:'%d'", VERSION, fuse_version());
 
 	memset(&opts, 0, sizeof(opts));
 
