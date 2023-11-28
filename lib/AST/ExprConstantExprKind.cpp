// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ExprConstantExprKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ExprConstantExprKind e) {
  switch (e) {
    case ExprConstantExprKind::NORMAL: return "NORMAL";
    case ExprConstantExprKind::NON_CLASS_TEMPLATE_ARGUMENT: return "NON_CLASS_TEMPLATE_ARGUMENT";
    case ExprConstantExprKind::CLASS_TEMPLATE_ARGUMENT: return "CLASS_TEMPLATE_ARGUMENT";
    case ExprConstantExprKind::IMMEDIATE_INVOCATION: return "IMMEDIATE_INVOCATION";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
