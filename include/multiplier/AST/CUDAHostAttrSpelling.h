// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class CUDAHostAttrSpelling : unsigned char {
  GNU_HOST,
  DECLSPEC_HOST,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CUDAHostAttrSpelling) {
  return "CUDAHostAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CUDAHostAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(CUDAHostAttrSpelling);

} // namespace mx
