# New ports collection makefile for:	fusefs-kmod
# Date created:				08 October 2005
# Whom:					Anish Mistry <amistry@am-productions.biz>
#
# $FreeBSD: ports/sysutils/fusefs-kmod/Makefile,v 1.31 2010/10/14 11:44:10 beat Exp $
#

PORTNAME=	fusefs-kmod
DISTVERSION=	0.4.4
CATEGORIES=	sysutils kld
MASTER_SITES=	http://cloud.github.com/downloads/glk/fuse-freebsd/
DISTNAME=	fuse-freebsd-${PORTVERSION}

COMMENT=	Kernel module for FUSE

FETCH_ARGS=	-Fpr		# work around 302 redirect at guthub

BUILD_DEPENDS=	fusefs-libs>2.4.1:${PORTSDIR}/sysutils/fusefs-libs

USE_RC_SUBR=	fusefs
KMODDIR?=	${PREFIX}/modules
PLIST_SUB=	KMODDIR=${KMODDIR}
MAKE_ENV=	BINDIR="${PREFIX}/sbin" MANDIR="${MANPREFIX}/man/man" \
		KMODDIR="${KMODDIR}" SYSDIR="${SRC_BASE}/sys" \
		MOUNT="${SRC_BASE}/sbin/mount"
DISABLE_SIZE=	yes

SRC_BASE?=	/usr/src
SETUP=		setup.sh

MAN8=		mount_fusefs.8

OPTIONS=	AUTOSETUP "Automatic global config file setup" off

.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires the Kernel source to be installed. Set SRC_BASE if it is not in /usr/src
.endif
.if !exists(${SRC_BASE}/sbin/mount)
IGNORE=		requires the userland sources to be installed. Set SRC_BASE if it is not in /usr/src
.endif

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
BROKEN=		Does not compile on other than i386/amd64
.endif

.if defined(WITH_AUTOSETUP)
SUB_FILES+=	${SETUP}
.else
SUB_FILES+=	pkg-message
.endif

pre-su-install:
	@${MKDIR} ${KMODDIR}

post-install:
	@${LN} -fs ${PREFIX}/sbin/mount_fusefs /usr/sbin
.if defined(WITH_AUTOSETUP) && !defined(PACKAGE_BUILDING)
	@${ECHO} "Modifying global startup config files and loading module..."
	@${SH} ${WRKDIR}/${SETUP}
.else
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}
.endif

.include <bsd.port.post.mk>
