--- libglusterfs/src/logging.h.orig	2011-08-06 17:28:47.512874221 +0300
+++ libglusterfs/src/logging.h	2011-08-06 17:31:20.368861668 +0300
@@ -34,6 +34,11 @@
 #define GF_PRI_DEV         PRId32
 #define GF_PRI_NLINK       PRIu16
 #define GF_PRI_SUSECONDS   PRId32
+#elif defined(__FreeBSD__)
+#define GF_PRI_FSBLK       PRIu64
+#define GF_PRI_DEV         PRId32
+#define GF_PRI_NLINK       PRIu16
+#define GF_PRI_SUSECONDS   "l"
 #else
 #define GF_PRI_FSBLK       PRIu64
 #define GF_PRI_DEV         PRIu64
