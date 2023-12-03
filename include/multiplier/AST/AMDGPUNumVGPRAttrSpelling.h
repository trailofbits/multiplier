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
enum class AMDGPUNumVGPRAttrSpelling : unsigned char {
  GNU_AMDGPU_NUM_VGPR,
  CXX11_CLANG_AMDGPU_NUM_VGPR,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AMDGPUNumVGPRAttrSpelling) {
  return "AMDGPUNumVGPRAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AMDGPUNumVGPRAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(AMDGPUNumVGPRAttrSpelling);

} // namespace mx
