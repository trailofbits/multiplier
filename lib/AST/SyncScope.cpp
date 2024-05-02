// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SyncScope.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SyncScope e) {
  switch (e) {
    case SyncScope::SYSTEM_SCOPE: return "SYSTEM_SCOPE";
    case SyncScope::DEVICE_SCOPE: return "DEVICE_SCOPE";
    case SyncScope::WORKGROUP_SCOPE: return "WORKGROUP_SCOPE";
    case SyncScope::WAVEFRONT_SCOPE: return "WAVEFRONT_SCOPE";
    case SyncScope::SINGLE_SCOPE: return "SINGLE_SCOPE";
    case SyncScope::HIP_SINGLE_THREAD: return "HIP_SINGLE_THREAD";
    case SyncScope::HIP_WAVEFRONT: return "HIP_WAVEFRONT";
    case SyncScope::HIP_WORKGROUP: return "HIP_WORKGROUP";
    case SyncScope::HIP_AGENT: return "HIP_AGENT";
    case SyncScope::HIP_SYSTEM: return "HIP_SYSTEM";
    case SyncScope::OPEN_CL_WORK_GROUP: return "OPEN_CL_WORK_GROUP";
    case SyncScope::OPEN_CL_DEVICE: return "OPEN_CL_DEVICE";
    case SyncScope::OPEN_CL_ALL_SVM_DEVICES: return "OPEN_CL_ALL_SVM_DEVICES";
    case SyncScope::OPEN_CL_SUB_GROUP: return "OPEN_CL_SUB_GROUP";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
