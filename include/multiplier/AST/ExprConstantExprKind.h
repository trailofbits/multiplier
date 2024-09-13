// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ExprConstantExprKind : unsigned char {
  NORMAL,
  NON_CLASS_TEMPLATE_ARGUMENT,
  CLASS_TEMPLATE_ARGUMENT,
  IMMEDIATE_INVOCATION,
};

inline static const char *EnumerationName(ExprConstantExprKind) {
  return "ExprConstantExprKind";
}

inline static constexpr unsigned NumEnumerators(ExprConstantExprKind) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ExprConstantExprKind);

} // namespace mx
