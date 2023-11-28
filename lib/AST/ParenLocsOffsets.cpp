// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ParenLocsOffsets.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ParenLocsOffsets e) {
  switch (e) {
    case ParenLocsOffsets::L_PAREN_TOKEN: return "L_PAREN_TOKEN";
    case ParenLocsOffsets::R_PAREN_TOKEN: return "R_PAREN_TOKEN";
    case ParenLocsOffsets::TOTAL: return "TOTAL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
