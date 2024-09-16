// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class AMDGPUWavesPerEUAttrSpelling : unsigned char {
  GNU_AMDGPU_WAVES_PER_EU,
  CXX11_CLANG_AMDGPU_WAVES_PER_EU,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AMDGPUWavesPerEUAttrSpelling) {
  return "AMDGPUWavesPerEUAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AMDGPUWavesPerEUAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(AMDGPUWavesPerEUAttrSpelling);

} // namespace mx
