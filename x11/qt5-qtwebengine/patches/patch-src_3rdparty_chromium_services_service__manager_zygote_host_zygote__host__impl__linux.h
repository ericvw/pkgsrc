$NetBSD: patch-src_3rdparty_chromium_services_service__manager_zygote_host_zygote__host__impl__linux.h,v 1.1 2021/08/03 21:04:35 markd Exp $

Index: src/3rdparty/chromium/services/service_manager/zygote/host/zygote_host_impl_linux.h
--- src/3rdparty/chromium/services/service_manager/zygote/host/zygote_host_impl_linux.h.orig
+++ src/3rdparty/chromium/services/service_manager/zygote/host/zygote_host_impl_linux.h
@@ -44,8 +44,10 @@ class COMPONENT_EXPORT(SERVICE_MANAGER_ZYGOTE) ZygoteH
                      base::ScopedFD* control_fd,
                      base::FileHandleMappingVector additional_remapped_fds);
 
+#if !defined(OS_BSD)
   void AdjustRendererOOMScore(base::ProcessHandle process_handle,
                               int score) override;
+#endif
   bool HasZygote() { return !zygote_pids_.empty(); }
 
  private:
@@ -59,9 +61,11 @@ class COMPONENT_EXPORT(SERVICE_MANAGER_ZYGOTE) ZygoteH
 
   int renderer_sandbox_status_;
 
+#if !defined(OS_BSD)
   bool use_namespace_sandbox_;
   bool use_suid_sandbox_;
   bool use_suid_sandbox_for_adj_oom_score_;
+#endif
   std::string sandbox_binary_;
 
   // This lock protects the |zygote_pids_| set.
