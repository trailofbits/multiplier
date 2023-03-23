// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/StrictFlexArraysLevelKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(StrictFlexArraysLevelKind e) {
  switch (e) {
    case StrictFlexArraysLevelKind::DEFAULT: return "DEFAULT";
    case StrictFlexArraysLevelKind::ONE_ZERO_OR_INCOMPLETE: return "ONE_ZERO_OR_INCOMPLETE";
    case StrictFlexArraysLevelKind::ZERO_OR_INCOMPLETE: return "ZERO_OR_INCOMPLETE";
    case StrictFlexArraysLevelKind::INCOMPLETE_ONLY: return "INCOMPLETE_ONLY";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
