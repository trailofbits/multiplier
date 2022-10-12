// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class OverloadedOperatorKind : unsigned char {
  NONE,
  NEW,
  DELETE,
  ARRAY_NEW,
  ARRAY_DELETE,
  PLUS,
  MINUS,
  STAR,
  SLASH,
  PERCENT,
  CARET,
  AMP,
  PIPE,
  TILDE,
  EXCLAIM,
  EQUAL,
  LESS,
  GREATER,
  PLUS_EQUAL,
  MINUS_EQUAL,
  STAR_EQUAL,
  SLASH_EQUAL,
  PERCENT_EQUAL,
  CARET_EQUAL,
  AMP_EQUAL,
  PIPE_EQUAL,
  LESS_LESS,
  GREATER_GREATER,
  LESS_LESS_EQUAL,
  GREATER_GREATER_EQUAL,
  EQUAL_EQUAL,
  EXCLAIM_EQUAL,
  LESS_EQUAL,
  GREATER_EQUAL,
  SPACESHIP,
  AMP_AMP,
  PIPE_PIPE,
  PLUS_PLUS,
  MINUS_MINUS,
  COMMA,
  ARROW_STAR,
  ARROW,
  CALL,
  SUBSCRIPT,
  CONDITIONAL,
  COAWAIT,
};

inline static const char *EnumerationName(OverloadedOperatorKind) {
  return "OverloadedOperatorKind";
}

inline static constexpr unsigned NumEnumerators(OverloadedOperatorKind) {
  return 46;
}

const char *EnumeratorName(OverloadedOperatorKind);

} // namespace mx
