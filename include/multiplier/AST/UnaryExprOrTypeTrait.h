// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class UnaryExprOrTypeTrait : unsigned char {
  SIZE_OF,
  DATA_SIZE_OF,
  ALIGN_OF,
  PREFERRED_ALIGN_OF,
  POINTER_AUTH_TYPE_DISCRIMINATOR,
  XNU_TYPE_SIGNATURE,
  XNU_TYPE_SUMMARY,
  TMO_TYPE_GET_METADATA,
  VEC_STEP,
  OPEN_MP_REQUIRED_SIMD_ALIGN,
  VECTOR_ELEMENTS,
};

inline static const char *EnumerationName(UnaryExprOrTypeTrait) {
  return "UnaryExprOrTypeTrait";
}

inline static constexpr unsigned NumEnumerators(UnaryExprOrTypeTrait) {
  return 11;
}

MX_EXPORT const char *EnumeratorName(UnaryExprOrTypeTrait);

} // namespace mx
