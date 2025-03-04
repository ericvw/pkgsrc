$NetBSD: patch-src_3rdparty_chromium_services_resource__coordinator_public_cpp_memory__instrumentation_os__metrics.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h
@@ -28,7 +28,7 @@ class COMPONENT_EXPORT(
                                     mojom::RawOSMemDump*);
   static std::vector<mojom::VmRegionPtr> GetProcessMemoryMaps(base::ProcessId);
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   static void SetProcSmapsForTesting(FILE*);
 #endif  // defined(OS_LINUX) || defined(OS_ANDROID)
 
@@ -44,7 +44,7 @@ class COMPONENT_EXPORT(
   static std::vector<mojom::VmRegionPtr> GetProcessModules(base::ProcessId);
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   // Provides information on the dump state of resident pages.
   enum class MappedAndResidentPagesDumpState {
     // Access to /proc/<pid>/pagemap can be denied for android devices running
