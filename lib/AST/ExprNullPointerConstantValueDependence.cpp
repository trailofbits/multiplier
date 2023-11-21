// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ExprNullPointerConstantValueDependence.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ExprNullPointerConstantValueDependence e) {
  switch (e) {
    case ExprNullPointerConstantValueDependence::NEVER_VALUE_DEPENDENT: return "NEVER_VALUE_DEPENDENT";
    case ExprNullPointerConstantValueDependence::VALUE_DEPENDENT_IS_NULL: return "VALUE_DEPENDENT_IS_NULL";
    case ExprNullPointerConstantValueDependence::VALUE_DEPENDENT_IS_NOT_NULL: return "VALUE_DEPENDENT_IS_NOT_NULL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
