// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ExprNullPointerConstantKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ExprNullPointerConstantKind e) {
  switch (e) {
    case ExprNullPointerConstantKind::NOT_NULL: return "NOT_NULL";
    case ExprNullPointerConstantKind::ZERO_EXPRESSION: return "ZERO_EXPRESSION";
    case ExprNullPointerConstantKind::ZERO_LITERAL: return "ZERO_LITERAL";
    case ExprNullPointerConstantKind::CXX11_NULLPTR: return "CXX11_NULLPTR";
    case ExprNullPointerConstantKind::GNU_NULL: return "GNU_NULL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
