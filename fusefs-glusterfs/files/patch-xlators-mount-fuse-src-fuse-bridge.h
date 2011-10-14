--- xlators/mount/fuse/src/fuse-bridge.h.orig	2011-07-14 15:21:10.000000000 +0300
+++ xlators/mount/fuse/src/fuse-bridge.h	2011-08-06 17:56:52.850862639 +0300
@@ -58,7 +58,7 @@
 #ifdef GF_LINUX_HOST_OS
 #define FUSE_OP_HIGH (FUSE_POLL + 1)
 #endif
-#ifdef GF_DARWIN_HOST_OS
+#if defined(GF_DARWIN_HOST_OS) || defined(__FreeBSD__)
 #define FUSE_OP_HIGH (FUSE_DESTROY + 1)
 #endif
 #define GLUSTERFS_XATTR_LEN_MAX  65536
