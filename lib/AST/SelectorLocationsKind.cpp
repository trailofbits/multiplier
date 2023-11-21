// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SelectorLocationsKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SelectorLocationsKind e) {
  switch (e) {
    case SelectorLocationsKind::NON_STANDARD: return "NON_STANDARD";
    case SelectorLocationsKind::STANDARD_NO_SPACE: return "STANDARD_NO_SPACE";
    case SelectorLocationsKind::STANDARD_WITH_SPACE: return "STANDARD_WITH_SPACE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
