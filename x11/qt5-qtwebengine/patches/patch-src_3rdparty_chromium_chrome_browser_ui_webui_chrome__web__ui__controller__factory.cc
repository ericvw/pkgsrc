$NetBSD: patch-src_3rdparty_chromium_chrome_browser_ui_webui_chrome__web__ui__controller__factory.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc
@@ -235,11 +235,11 @@
 #include "chrome/browser/ui/webui/conflicts/conflicts_ui.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/ui/webui/discards/discards_ui.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "chrome/browser/ui/webui/sandbox/sandbox_internals_ui.h"
 #endif
 
@@ -361,7 +361,7 @@ bool IsAboutUI(const GURL& url) {
 #if !defined(OS_ANDROID)
           || url.host_piece() == chrome::kChromeUITermsHost
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
           || url.host_piece() == chrome::kChromeUILinuxProxyConfigHost
 #endif
 #if defined(OS_CHROMEOS)
@@ -705,7 +705,7 @@ WebUIFactoryFunction GetWebUIFactoryFunc
   if (url.host_piece() == chrome::kChromeUINaClHost)
     return &NewWebUI<NaClUI>;
 #endif
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_LINUX) || defined(OS_BSD)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
   if (url.host_piece() == chrome::kChromeUITabModalConfirmDialogHost)
     return &NewWebUI<ConstrainedWebDialogUI>;
 #endif
@@ -755,17 +755,17 @@ WebUIFactoryFunction GetWebUIFactoryFunc
     return &NewWebUI<CastUI>;
   }
 #endif
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   if (url.host_piece() == chrome::kChromeUISandboxHost) {
     return &NewWebUI<SandboxInternalsUI>;
   }
 #endif
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   if (url.host_piece() == chrome::kChromeUIDiscardsHost)
     return &NewWebUI<DiscardsUI>;
 #endif
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
   if (url.host_piece() == chrome::kChromeUIBrowserSwitchHost)
     return &NewWebUI<BrowserSwitchUI>;
 #endif
