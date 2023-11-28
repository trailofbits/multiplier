// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AMDGPUFlatWorkGroupSizeAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AMDGPUFlatWorkGroupSizeAttrSpelling e) {
  switch (e) {
    case AMDGPUFlatWorkGroupSizeAttrSpelling::GNU_AMDGPU_FLAT_WORK_GROUP_SIZE: return "GNU_AMDGPU_FLAT_WORK_GROUP_SIZE";
    case AMDGPUFlatWorkGroupSizeAttrSpelling::CXX11_CLANG_AMDGPU_FLAT_WORK_GROUP_SIZE: return "CXX11_CLANG_AMDGPU_FLAT_WORK_GROUP_SIZE";
    case AMDGPUFlatWorkGroupSizeAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
