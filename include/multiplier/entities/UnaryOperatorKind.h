// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class UnaryOperatorKind : unsigned char {
  POST_INCREMENT,
  POST_DEC,
  PRE_INCREMENT,
  PRE_DEC,
  ADDRESS_OF,
  DEREF,
  PLUS,
  MINUS,
  NOT,
  L_NOT,
  REAL,
  IMAG,
  EXTENSION,
  COAWAIT,
};

inline static const char *EnumerationName(UnaryOperatorKind) {
  return "UnaryOperatorKind";
}

inline static constexpr unsigned NumEnumerators(UnaryOperatorKind) {
  return 14;
}

const char *EnumeratorName(UnaryOperatorKind);

} // namespace mx
