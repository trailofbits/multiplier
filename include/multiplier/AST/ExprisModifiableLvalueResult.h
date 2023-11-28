// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ExprisModifiableLvalueResult : unsigned char {
  VALID,
  NOT_OBJECT_TYPE,
  INCOMPLETE_VOID_TYPE,
  DUPLICATE_VECTOR_COMPONENTS,
  INVALID_EXPRESSION,
  L_VALUE_CAST,
  INCOMPLETE_TYPE,
  CONST_QUALIFIED,
  CONST_QUALIFIED_FIELD,
  CONST_ADDRESS_SPACE,
  ARRAY_TYPE,
  NO_SETTER_PROPERTY,
  MEMBER_FUNCTION,
  SUB_OBJ_C_PROPERTY_SETTING,
  INVALID_MESSAGE_EXPRESSION,
  CLASS_TEMPORARY,
  ARRAY_TEMPORARY,
};

inline static const char *EnumerationName(ExprisModifiableLvalueResult) {
  return "ExprisModifiableLvalueResult";
}

inline static constexpr unsigned NumEnumerators(ExprisModifiableLvalueResult) {
  return 17;
}

const char *EnumeratorName(ExprisModifiableLvalueResult);

} // namespace mx
