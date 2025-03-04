# $NetBSD: buildlink3.mk,v 1.70 2021/12/08 16:02:46 adam Exp $

BUILDLINK_TREE+=	compiz

.if !defined(COMPIZ_BUILDLINK3_MK)
COMPIZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compiz+=	compiz>=0.6.2
BUILDLINK_ABI_DEPENDS.compiz+=	compiz>=0.8.8nb67
BUILDLINK_PKGSRCDIR.compiz?=	../../wm/compiz

pkgbase := compiz
.include "../../mk/pkg-build-options.mk"

#.if !empty(PKG_BUILD_OPTIONS.compiz:Mfuse)
#.include "../../filesystems/fuse/buildlink3.mk"
#.endif

# XXX NLS is supposed to be optional, but it doens't appear to be.
#.if !empty(PKG_BUILD_OPTIONS.compiz:Mnls)
#.include "../../devel/gettext-lib/buildlink3.mk"
#.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif # COMPIZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-compiz
