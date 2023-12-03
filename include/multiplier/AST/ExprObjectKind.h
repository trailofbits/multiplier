// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ExprObjectKind : unsigned char {
  ORDINARY,
  BIT_FIELD,
  VECTOR_COMPONENT,
  OBJ_C_PROPERTY,
  OBJ_C_SUBSCRIPT,
  MATRIX_COMPONENT,
};

inline static const char *EnumerationName(ExprObjectKind) {
  return "ExprObjectKind";
}

inline static constexpr unsigned NumEnumerators(ExprObjectKind) {
  return 6;
}

MX_EXPORT const char *EnumeratorName(ExprObjectKind);

} // namespace mx
