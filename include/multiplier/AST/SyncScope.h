// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class SyncScope : unsigned char {
  SYSTEM_SCOPE,
  DEVICE_SCOPE,
  WORKGROUP_SCOPE,
  WAVEFRONT_SCOPE,
  SINGLE_SCOPE,
  HIP_SINGLE_THREAD,
  HIP_WAVEFRONT,
  HIP_WORKGROUP,
  HIP_AGENT,
  HIP_SYSTEM,
  OPEN_CL_WORK_GROUP,
  OPEN_CL_DEVICE,
  OPEN_CL_ALL_SVM_DEVICES,
  OPEN_CL_SUB_GROUP,
};

inline static const char *EnumerationName(SyncScope) {
  return "SyncScope";
}

inline static constexpr unsigned NumEnumerators(SyncScope) {
  return 14;
}

MX_EXPORT const char *EnumeratorName(SyncScope);

} // namespace mx
