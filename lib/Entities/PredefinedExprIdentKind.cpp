// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/PredefinedExprIdentKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(PredefinedExprIdentKind e) {
  switch (e) {
    case PredefinedExprIdentKind::FUNC: return "FUNC";
    case PredefinedExprIdentKind::FUNCTION: return "FUNCTION";
    case PredefinedExprIdentKind::L_FUNCTION: return "L_FUNCTION";
    case PredefinedExprIdentKind::FUNC_D_NAME: return "FUNC_D_NAME";
    case PredefinedExprIdentKind::FUNC_SIG: return "FUNC_SIG";
    case PredefinedExprIdentKind::L_FUNC_SIG: return "L_FUNC_SIG";
    case PredefinedExprIdentKind::PRETTY_FUNCTION: return "PRETTY_FUNCTION";
    case PredefinedExprIdentKind::PRETTY_FUNCTION_NO_VIRTUAL: return "PRETTY_FUNCTION_NO_VIRTUAL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
