# New ports collection makefile for:	fusefs-glusterfs
# Date created: 			30 July 2011
# Whom:					Ilya Putsikau <iputsikau@gmail.com>
# $NetBSD: Makefile,v 1.14 2011/07/23 01:14:43 manu Exp $
# $FreeBSD$
#

PORTNAME=	glusterfs
PORTVERSION=	3.2.2
CATEGORIES=	sysutils
MASTER_SITES=	http://download.gluster.com/pub/gluster/glusterfs/3.2/${PORTVERSION}/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FUSE Cluster file system

BUILD_DEPENDS=	fusefs-libs>=2.7.2:${PORTSDIR}/sysutils/fusefs-libs
LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

USE_AUTOTOOLS=	libtool
USE_BISON=	build
USE_PYTHON=	yes

post-build:
	 cp ${WRKSRC}/doc/glusterd.vol ${WRKSRC}/doc/glusterd.vol.sample

post-install:
	${INSTALL_SCRIPT} ${DESTDIR}/sbin/mount.glusterfs \
	    ${DESTDIR}/${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${FILESDIR}/xattr-init.sh \
	    ${DESTDIR}/${PREFIX}/etc/glusterfs/

MAN8=	gluster.8 glusterd.8 glusterfs.8 glusterfsd.8 \
	mount.glusterfs.8

# Debug
CFLAGS+=		-g
INSTALL_UNSTRIPPED=	yes

.include <bsd.port.mk>
