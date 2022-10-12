// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class UnaryExprOrTypeTrait : unsigned char {
  SIZE_OF,
  ALIGN_OF,
  PREFERRED_ALIGN_OF,
  VEC_STEP,
  OPEN_MP_REQUIRED_SIMD_ALIGN,
};

inline static const char *EnumerationName(UnaryExprOrTypeTrait) {
  return "UnaryExprOrTypeTrait";
}

inline static constexpr unsigned NumEnumerators(UnaryExprOrTypeTrait) {
  return 5;
}

const char *EnumeratorName(UnaryExprOrTypeTrait);

} // namespace mx
