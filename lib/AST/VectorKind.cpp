// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/VectorKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(VectorKind e) {
  switch (e) {
    case VectorKind::GENERIC: return "GENERIC";
    case VectorKind::ALTI_VEC_VECTOR: return "ALTI_VEC_VECTOR";
    case VectorKind::ALTI_VEC_PIXEL: return "ALTI_VEC_PIXEL";
    case VectorKind::ALTI_VEC_BOOLEAN: return "ALTI_VEC_BOOLEAN";
    case VectorKind::NEON: return "NEON";
    case VectorKind::NEON_POLY: return "NEON_POLY";
    case VectorKind::SVE_FIXED_LENGTH_DATA: return "SVE_FIXED_LENGTH_DATA";
    case VectorKind::SVE_FIXED_LENGTH_PREDICATE: return "SVE_FIXED_LENGTH_PREDICATE";
    case VectorKind::RVV_FIXED_LENGTH_DATA: return "RVV_FIXED_LENGTH_DATA";
    case VectorKind::RVV_FIXED_LENGTH_MASK: return "RVV_FIXED_LENGTH_MASK";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
