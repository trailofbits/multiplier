// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ExpressionTrait.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ExpressionTrait e) {
  switch (e) {
    case ExpressionTrait::IS_L_VALUE_EXPRESSION: return "IS_L_VALUE_EXPRESSION";
    case ExpressionTrait::IS_R_VALUE_EXPRESSION: return "IS_R_VALUE_EXPRESSION";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
