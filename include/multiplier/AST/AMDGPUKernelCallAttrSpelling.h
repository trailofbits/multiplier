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
enum class AMDGPUKernelCallAttrSpelling : unsigned char {
  GNU_AMDGPU_KERNEL,
  CXX11_CLANG_AMDGPU_KERNEL,
  C2X_CLANG_AMDGPU_KERNEL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AMDGPUKernelCallAttrSpelling) {
  return "AMDGPUKernelCallAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AMDGPUKernelCallAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(AMDGPUKernelCallAttrSpelling);

} // namespace mx
