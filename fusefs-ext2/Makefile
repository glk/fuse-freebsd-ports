# New ports collection makefile for:	fusefs-ext2
# Date created: 			26 July 2011
# Whom:					Ilya Putsikau
# $FreeBSD$
#

PORTNAME=	ext2
PORTVERSION=	0.0.7
CATEGORIES=	sysutils
MASTER_SITES=	SOURCEFORGE
MASTER_SITE_SUBDIR=	fuse-ext2/fuse-ext2/${DISTNAME}
PKGNAMEPREFIX=	fusefs-
DISTNAME=	fuse-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FUSE ext2/ext3 file system

BUILD_DEPENDS=	fusefs-libs>=2.7.2:${PORTSDIR}/sysutils/fusefs-libs
LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf libtool automake

CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	"LDFLAGS=-L${LOCALBASE}/lib"

pre-configure:
	cd ${WRKSRC} && ${AUTORECONF} --verbose --install --force

MAN1=		fuse-ext2.1

.include <bsd.port.mk>
