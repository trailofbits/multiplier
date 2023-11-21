// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TypeScalarTypeKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TypeScalarTypeKind e) {
  switch (e) {
    case TypeScalarTypeKind::C_POINTER: return "C_POINTER";
    case TypeScalarTypeKind::BLOCK_POINTER: return "BLOCK_POINTER";
    case TypeScalarTypeKind::OBJ_C_OBJECT_POINTER: return "OBJ_C_OBJECT_POINTER";
    case TypeScalarTypeKind::MEMBER_POINTER: return "MEMBER_POINTER";
    case TypeScalarTypeKind::BOOLEAN: return "BOOLEAN";
    case TypeScalarTypeKind::INTEGRAL: return "INTEGRAL";
    case TypeScalarTypeKind::FLOATING: return "FLOATING";
    case TypeScalarTypeKind::INTEGRAL_COMPLEX: return "INTEGRAL_COMPLEX";
    case TypeScalarTypeKind::FLOATING_COMPLEX: return "FLOATING_COMPLEX";
    case TypeScalarTypeKind::FIXED_POINT: return "FIXED_POINT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
