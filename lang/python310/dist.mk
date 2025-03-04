# $NetBSD: dist.mk,v 1.5 2022/03/25 17:55:19 adam Exp $

PY_DISTVERSION=	3.10.4
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python310/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python310/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
