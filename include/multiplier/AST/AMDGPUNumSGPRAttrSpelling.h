// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class AMDGPUNumSGPRAttrSpelling : unsigned char {
  GNU_AMDGPU_NUM_SGPR,
  CXX11_CLANG_AMDGPU_NUM_SGPR,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AMDGPUNumSGPRAttrSpelling) {
  return "AMDGPUNumSGPRAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AMDGPUNumSGPRAttrSpelling) {
  return 3;
}

const char *EnumeratorName(AMDGPUNumSGPRAttrSpelling);

} // namespace mx
