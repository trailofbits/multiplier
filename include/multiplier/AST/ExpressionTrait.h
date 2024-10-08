// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ExpressionTrait : unsigned char {
  IS_L_VALUE_EXPRESSION,
  IS_R_VALUE_EXPRESSION,
};

inline static const char *EnumerationName(ExpressionTrait) {
  return "ExpressionTrait";
}

inline static constexpr unsigned NumEnumerators(ExpressionTrait) {
  return 2;
}

MX_EXPORT const char *EnumeratorName(ExpressionTrait);

} // namespace mx
