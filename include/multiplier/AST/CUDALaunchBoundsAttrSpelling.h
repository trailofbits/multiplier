// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class CUDALaunchBoundsAttrSpelling : unsigned char {
  GNU_LAUNCH_BOUNDS,
  DECLSPEC_LAUNCH_BOUNDS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CUDALaunchBoundsAttrSpelling) {
  return "CUDALaunchBoundsAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CUDALaunchBoundsAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(CUDALaunchBoundsAttrSpelling);

} // namespace mx
