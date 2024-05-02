// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/PredefinedIdentKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(PredefinedIdentKind e) {
  switch (e) {
    case PredefinedIdentKind::FUNC: return "FUNC";
    case PredefinedIdentKind::FUNCTION: return "FUNCTION";
    case PredefinedIdentKind::L_FUNCTION: return "L_FUNCTION";
    case PredefinedIdentKind::FUNC_D_NAME: return "FUNC_D_NAME";
    case PredefinedIdentKind::FUNC_SIG: return "FUNC_SIG";
    case PredefinedIdentKind::L_FUNC_SIG: return "L_FUNC_SIG";
    case PredefinedIdentKind::PRETTY_FUNCTION: return "PRETTY_FUNCTION";
    case PredefinedIdentKind::PRETTY_FUNCTION_NO_VIRTUAL: return "PRETTY_FUNCTION_NO_VIRTUAL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
