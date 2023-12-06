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
enum class ExprNullPointerConstantKind : unsigned char {
  NOT_NULL,
  ZERO_EXPRESSION,
  ZERO_LITERAL,
  CXX11_NULLPTR,
  GNU_NULL,
};

inline static const char *EnumerationName(ExprNullPointerConstantKind) {
  return "ExprNullPointerConstantKind";
}

inline static constexpr unsigned NumEnumerators(ExprNullPointerConstantKind) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(ExprNullPointerConstantKind);

} // namespace mx
