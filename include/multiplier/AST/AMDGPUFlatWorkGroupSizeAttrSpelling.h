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
enum class AMDGPUFlatWorkGroupSizeAttrSpelling : unsigned char {
  GNU_AMDGPU_FLAT_WORK_GROUP_SIZE,
  CXX11_CLANG_AMDGPU_FLAT_WORK_GROUP_SIZE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AMDGPUFlatWorkGroupSizeAttrSpelling) {
  return "AMDGPUFlatWorkGroupSizeAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AMDGPUFlatWorkGroupSizeAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(AMDGPUFlatWorkGroupSizeAttrSpelling);

} // namespace mx
