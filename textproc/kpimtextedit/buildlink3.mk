# $NetBSD: buildlink3.mk,v 1.16 2022/03/28 10:59:29 tnn Exp $

BUILDLINK_TREE+=	kpimtextedit

.if !defined(KPIMTEXTEDIT_BUILDLINK3_MK)
KPIMTEXTEDIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kpimtextedit+=	kpimtextedit>=17.12.1
BUILDLINK_ABI_DEPENDS.kpimtextedit?=	kpimtextedit>=20.12.3nb5
BUILDLINK_PKGSRCDIR.kpimtextedit?=	../../textproc/kpimtextedit

.include "../../devel/grantlee-qt5/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../misc/kemoticons/buildlink3.mk"
.include "../../textproc/syntax-highlighting/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtspeech/buildlink3.mk"
.endif	# KPIMTEXTEDIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-kpimtextedit
