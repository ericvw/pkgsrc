$NetBSD: patch-src_3rdparty_chromium_chrome_browser_net_system__network__context__manager.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/chrome/browser/net/system_network_context_manager.cc.orig	2020-07-08 21:40:34.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/net/system_network_context_manager.cc
@@ -77,7 +77,7 @@
 #include "chrome/browser/chromeos/policy/browser_policy_connector_chromeos.h"
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "chrome/common/chrome_paths_internal.h"
 #include "chrome/grit/chromium_strings.h"
 #include "ui/base/l10n/l10n_util.h"
@@ -140,7 +140,7 @@ network::mojom::HttpAuthDynamicParamsPtr
   auth_dynamic_params->enable_negotiate_port =
       local_state->GetBoolean(prefs::kEnableAuthNegotiatePort);
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   auth_dynamic_params->delegate_by_kdc_policy =
       local_state->GetBoolean(prefs::kAuthNegotiateDelegateByKdcPolicy);
 #endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
@@ -355,7 +355,7 @@ SystemNetworkContextManager::SystemNetwo
   pref_change_registrar_.Add(prefs::kEnableAuthNegotiatePort,
                              auth_pref_callback);
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   pref_change_registrar_.Add(prefs::kAuthNegotiateDelegateByKdcPolicy,
                              auth_pref_callback);
 #endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
@@ -405,7 +405,7 @@ void SystemNetworkContextManager::Regist
   registry->RegisterStringPref(prefs::kAuthServerWhitelist, std::string());
   registry->RegisterStringPref(prefs::kAuthNegotiateDelegateWhitelist,
                                std::string());
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   registry->RegisterBooleanPref(prefs::kAuthNegotiateDelegateByKdcPolicy,
                                 false);
 #endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
@@ -491,7 +491,7 @@ void SystemNetworkContextManager::OnNetw
   // NetworkContext is created, but before anything has the chance to use it.
   stub_resolver_config_reader_.UpdateNetworkService(true /* record_metrics */);
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   const base::CommandLine& command_line =
       *base::CommandLine::ForCurrentProcess();
 
