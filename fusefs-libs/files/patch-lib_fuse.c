--- lib/fuse.c.orig	2008-07-25 21:17:21.000000000 +0300
+++ lib/fuse.c	2011-08-15 16:25:34.000000000 +0300
@@ -1718,8 +1718,18 @@
 				fprintf(stderr, "RENAME %s -> %s\n", oldpath,
 					newpath);
 			err = 0;
+			if (olddir != newdir) {
+				size_t oldlen = strlen(oldpath);
+				if (strlen(newpath) > oldlen &&
+					strncmp(newpath, oldpath, oldlen) == 0) {
+					if (f->conf.debug)
+						fprintf(stderr, "RENAME: from directory is parent of to: %s -> %s\n",
+							oldpath, newpath);
+					err = -EINVAL;
+				}
+			}
 			fuse_prepare_interrupt(f, req, &d);
-			if (!f->conf.hard_remove && is_open(f, newdir, newname))
+			if (!err && !f->conf.hard_remove && is_open(f, newdir, newname))
 				err = hide_node(f, newpath, newdir, newname);
 			if (!err) {
 				err = fuse_fs_rename(f->fs, oldpath, newpath);
