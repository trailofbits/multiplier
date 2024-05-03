// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AMDGPUKernelCallAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AMDGPUKernelCallAttrSpelling e) {
  switch (e) {
    case AMDGPUKernelCallAttrSpelling::GNU_AMDGPU_KERNEL: return "GNU_AMDGPU_KERNEL";
    case AMDGPUKernelCallAttrSpelling::CXX11_CLANG_AMDGPU_KERNEL: return "CXX11_CLANG_AMDGPU_KERNEL";
    case AMDGPUKernelCallAttrSpelling::C23_CLANG_AMDGPU_KERNEL: return "C23_CLANG_AMDGPU_KERNEL";
    case AMDGPUKernelCallAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
