// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class TokenCategory : unsigned char {
  UNKNOWN,
  IDENTIFIER,
  MACRO_NAME,
  MACRO_PARAMETER_NAME,
  MACRO_DIRECTIVE_NAME,
  KEYWORD,
  OBJECTIVE_C_KEYWORD,
  BUILTIN_TYPE_NAME,
  PUNCTUATION,
  LITERAL,
  COMMENT,
  LOCAL_VARIABLE,
  GLOBAL_VARIABLE,
  PARAMETER_VARIABLE,
  FUNCTION,
  INSTANCE_METHOD,
  INSTANCE_MEMBER,
  CLASS_METHOD,
  CLASS_MEMBER,
  THIS,
  CLASS,
  STRUCT,
  UNION,
  CONCEPT,
  INTERFACE,
  ENUM,
  ENUMERATOR,
  NAMESPACE,
  TYPE_ALIAS,
  TEMPLATE_PARAMETER_TYPE,
  TEMPLATE_PARAMETER_VALUE,
  LABEL,
  WHITESPACE,
  FILE_NAME,
  LINE_NUMBER,
  COLUMN_NUMBER,
  INFORMATION,
  WARNING,
  ERROR,
};

inline static const char *EnumerationName(TokenCategory) {
  return "TokenCategory";
}

inline static constexpr unsigned NumEnumerators(TokenCategory) {
  return 39;
}

MX_EXPORT const char *EnumeratorName(TokenCategory);

} // namespace mx
