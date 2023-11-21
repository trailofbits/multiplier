// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class VectorTypeVectorKind : unsigned char {
  GENERIC_VECTOR,
  ALTI_VEC_VECTOR,
  ALTI_VEC_PIXEL,
  ALTI_VEC_BOOLEAN,
  NEON_VECTOR,
  NEON_POLY_VECTOR,
  SVE_FIXED_LENGTH_DATA_VECTOR,
  SVE_FIXED_LENGTH_PREDICATE_VECTOR,
  RVV_FIXED_LENGTH_DATA_VECTOR,
};

inline static const char *EnumerationName(VectorTypeVectorKind) {
  return "VectorTypeVectorKind";
}

inline static constexpr unsigned NumEnumerators(VectorTypeVectorKind) {
  return 9;
}

const char *EnumeratorName(VectorTypeVectorKind);

} // namespace mx
