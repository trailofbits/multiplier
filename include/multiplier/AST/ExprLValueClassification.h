// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ExprLValueClassification : unsigned char {
  VALID,
  NOT_OBJECT_TYPE,
  INCOMPLETE_VOID_TYPE,
  DUPLICATE_VECTOR_COMPONENTS,
  INVALID_EXPRESSION,
  INVALID_MESSAGE_EXPRESSION,
  MEMBER_FUNCTION,
  SUB_OBJ_C_PROPERTY_SETTING,
  CLASS_TEMPORARY,
  ARRAY_TEMPORARY,
};

inline static const char *EnumerationName(ExprLValueClassification) {
  return "ExprLValueClassification";
}

inline static constexpr unsigned NumEnumerators(ExprLValueClassification) {
  return 10;
}

MX_EXPORT const char *EnumeratorName(ExprLValueClassification);

} // namespace mx
