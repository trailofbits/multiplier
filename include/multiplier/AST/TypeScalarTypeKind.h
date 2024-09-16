// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class TypeScalarTypeKind : unsigned char {
  C_POINTER,
  BLOCK_POINTER,
  OBJ_C_OBJECT_POINTER,
  MEMBER_POINTER,
  BOOLEAN,
  INTEGRAL,
  FLOATING,
  INTEGRAL_COMPLEX,
  FLOATING_COMPLEX,
  FIXED_POINT,
};

inline static const char *EnumerationName(TypeScalarTypeKind) {
  return "TypeScalarTypeKind";
}

inline static constexpr unsigned NumEnumerators(TypeScalarTypeKind) {
  return 10;
}

MX_EXPORT const char *EnumeratorName(TypeScalarTypeKind);

} // namespace mx
