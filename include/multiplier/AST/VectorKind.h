// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class VectorKind : unsigned char {
  GENERIC,
  ALTI_VEC_VECTOR,
  ALTI_VEC_PIXEL,
  ALTI_VEC_BOOLEAN,
  NEON,
  NEON_POLY,
  SVE_FIXED_LENGTH_DATA,
  SVE_FIXED_LENGTH_PREDICATE,
  RVV_FIXED_LENGTH_DATA,
  RVV_FIXED_LENGTH_MASK,
};

inline static const char *EnumerationName(VectorKind) {
  return "VectorKind";
}

inline static constexpr unsigned NumEnumerators(VectorKind) {
  return 10;
}

MX_EXPORT const char *EnumeratorName(VectorKind);

} // namespace mx
