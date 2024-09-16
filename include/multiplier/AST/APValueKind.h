// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class APValueKind : unsigned char {
  NONE,
  INDETERMINATE,
  INT,
  FLOAT,
  FIXED_POINT,
  COMPLEX_INT,
  COMPLEX_FLOAT,
  L_VALUE,
  VECTOR,
  ARRAY,
  STRUCT,
  UNION,
  MEMBER_POINTER,
  ADDRESS_LABEL_DIFF,
};

inline static const char *EnumerationName(APValueKind) {
  return "APValueKind";
}

inline static constexpr unsigned NumEnumerators(APValueKind) {
  return 14;
}

MX_EXPORT const char *EnumeratorName(APValueKind);

} // namespace mx
