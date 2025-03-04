# $NetBSD: options.mk,v 1.3 2022/04/03 10:04:09 pin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.spotify-player
PKG_SUPPORTED_OPTIONS=	alsa gstreamer jack portaudio pulseaudio rodio sdl
PKG_SUGGESTED_OPTIONS=	portaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CARGO_FEATURES+=	alsa-backend
RUSTFLAGS+=		-C link-arg=-L${BUILDLINK_PREFIX.alsa-lib}/lib
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.alsa-lib}/lib
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgstreamer)
CARGO_FEATURES+=	gstreamer-backend
RUSTFLAGS+=		-C link-arg=-L${BUILDLINK_PREFIX.gstreamer1}/lib
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gstreamer1}/lib
DEPENDS+=		gstreamer1-default-backend-[0-9]*:../../meta-pkgs/gstreamer1-default-backend
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjack)
CARGO_FEATURES+=	jackaudio-backend
RUSTFLAGS+=		-C link-arg=-L${BUILDLINK_PREFIX.jack}/lib
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.jack}/lib
.include "../../audio/jack/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
CARGO_FEATURES+=	portaudio-backend
RUSTFLAGS+=		-C link-arg=-L${BUILDLINK_PREFIX.portaudio}/lib
RUSTFLAGS+=		-C link-arg=-L${BUILDLINK_PREFIX.portaudio}/${BUILDLINK_LIBDIRS.portaudio}
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.portaudio}/lib
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.portaudio}/${BUILDLINK_LIBDIRS.portaudio}
.include "../../audio/portaudio/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CARGO_FEATURES+=	pulseaudio-backend
RUSTFLAGS+=		-C link-arg=-L${BUILDLINK_PREFIX.pulseaudio}/lib
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.pulseaudio}/lib
.include "../../audio/pulseaudio/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mrodio)
CARGO_FEATURES+=	rodio-backend
.endif

.if !empty(PKG_OPTIONS:Msdl)
CARGO_FEATURES+=	sdl-backend
RUSTFLAGS+=		-C link-arg=-L${BUILDLINK_PREFIX.SDL2}/lib
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.SDL2}/lib
.include "../../devel/SDL2/buildlink3.mk"
.endif
