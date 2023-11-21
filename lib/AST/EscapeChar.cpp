// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/EscapeChar.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(EscapeChar e) {
  switch (e) {
    case EscapeChar::SINGLE: return "SINGLE";
    case EscapeChar::DOUBLE: return "DOUBLE";
    case EscapeChar::SINGLE_AND_DOUBLE: return "SINGLE_AND_DOUBLE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
