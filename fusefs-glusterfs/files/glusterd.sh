#!/bin/sh
#
# $NetBSD: glusterd.sh,v 1.6 2011/07/23 01:14:44 manu Exp $
#

# PROVIDE: glusterd
# REQUIRE: rpcbind
# BEFORE: glusterfsd

$_rc_subr_loaded . /etc/rc.subr

name="glusterd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
command_args="-p ${pidfile}"
required_files="@PREFIX@/etc/glusterfs/${name}.vol"

load_rc_config $name
run_rc_command "$1"
