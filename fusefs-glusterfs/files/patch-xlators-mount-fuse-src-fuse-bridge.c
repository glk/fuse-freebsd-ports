--- xlators/mount/fuse/src/fuse-bridge.c.orig	2011-08-06 18:01:57.324864171 +0300
+++ xlators/mount/fuse/src/fuse-bridge.c	2011-08-06 18:03:24.514861329 +0300
@@ -2474,7 +2474,7 @@
                                 send_fuse_xattr (this, finh, value, ret, state->size);
                                 /* if(ret >...)...else if...else */
                         } else {
-                                send_fuse_err (this, finh, ENODATA);
+                                send_fuse_err (this, finh, EPROTO);
                         } /* if(value_data)...else */
                 } else {
                         /* if callback for listxattr */
@@ -2498,7 +2498,7 @@
                 } /* if(state->name)...else */
         } else {
                 /* if failure - no need to check if listxattr or getxattr */
-                if (op_errno != ENODATA) {
+                if (op_errno != EPROTO) {
                         if (op_errno == ENOTSUP) {
                                 GF_LOG_OCCASIONALLY (gf_fuse_xattr_enotsup_log,
                                                      "glusterfs-fuse",
@@ -2519,7 +2519,7 @@
                                 frame->root->unique,
                                 gf_fop_list[frame->root->op], state->name,
                                 state->loc.path, strerror (op_errno));
-                } /* if(op_errno!= ENODATA)...else */
+                } /* if(op_errno!= EPROTO)...else */
 
                 send_fuse_err (this, finh, op_errno);
         } /* if(op_ret>=0)...else */
@@ -2588,7 +2588,7 @@
 
 #ifdef DISABLE_SELINUX
         if (!strncmp (name, "security.", 9)) {
-                send_fuse_err (this, finh, ENODATA);
+                send_fuse_err (this, finh, EPROTO);
                 GF_FREE (finh);
                 return;
         }
