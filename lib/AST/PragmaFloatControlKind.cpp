// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/PragmaFloatControlKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(PragmaFloatControlKind e) {
  switch (e) {
    case PragmaFloatControlKind::UNKNOWN: return "UNKNOWN";
    case PragmaFloatControlKind::PRECISE: return "PRECISE";
    case PragmaFloatControlKind::NO_PRECISE: return "NO_PRECISE";
    case PragmaFloatControlKind::EXCEPT: return "EXCEPT";
    case PragmaFloatControlKind::NO_EXCEPT: return "NO_EXCEPT";
    case PragmaFloatControlKind::PUSH: return "PUSH";
    case PragmaFloatControlKind::POP: return "POP";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
