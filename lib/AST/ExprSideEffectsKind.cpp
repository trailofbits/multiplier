// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ExprSideEffectsKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ExprSideEffectsKind e) {
  switch (e) {
    case ExprSideEffectsKind::NO_SIDE_EFFECTS: return "NO_SIDE_EFFECTS";
    case ExprSideEffectsKind::ALLOW_UNDEFINED_BEHAVIOR: return "ALLOW_UNDEFINED_BEHAVIOR";
    case ExprSideEffectsKind::ALLOW_SIDE_EFFECTS: return "ALLOW_SIDE_EFFECTS";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
