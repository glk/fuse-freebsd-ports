--- src/main.c.orig	2011-08-08 14:55:39.000000000 +0300
+++ src/main.c	2011-08-08 14:01:39.000000000 +0300
@@ -203,6 +203,7 @@
     reconfigure_read_config(CONFIG_OPT_STARTUP);
     samba_allocate_ctxs();
 
+    fuse_opt_insert_arg(&args, 1, "-obrokenio");
     fuse_main(args.argc, args.argv, &smb_oper, NULL);
     samba_destroy_unused_ctxs();
     smbitem_delete_obsolete(time(NULL) + 10, SMBITEM_SAMBA_TREE);
