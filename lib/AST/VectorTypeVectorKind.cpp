// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/VectorTypeVectorKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(VectorTypeVectorKind e) {
  switch (e) {
    case VectorTypeVectorKind::GENERIC_VECTOR: return "GENERIC_VECTOR";
    case VectorTypeVectorKind::ALTI_VEC_VECTOR: return "ALTI_VEC_VECTOR";
    case VectorTypeVectorKind::ALTI_VEC_PIXEL: return "ALTI_VEC_PIXEL";
    case VectorTypeVectorKind::ALTI_VEC_BOOLEAN: return "ALTI_VEC_BOOLEAN";
    case VectorTypeVectorKind::NEON_VECTOR: return "NEON_VECTOR";
    case VectorTypeVectorKind::NEON_POLY_VECTOR: return "NEON_POLY_VECTOR";
    case VectorTypeVectorKind::SVE_FIXED_LENGTH_DATA_VECTOR: return "SVE_FIXED_LENGTH_DATA_VECTOR";
    case VectorTypeVectorKind::SVE_FIXED_LENGTH_PREDICATE_VECTOR: return "SVE_FIXED_LENGTH_PREDICATE_VECTOR";
    case VectorTypeVectorKind::RVV_FIXED_LENGTH_DATA_VECTOR: return "RVV_FIXED_LENGTH_DATA_VECTOR";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
