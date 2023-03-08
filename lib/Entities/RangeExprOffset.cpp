// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/RangeExprOffset.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(RangeExprOffset e) {
  switch (e) {
    case RangeExprOffset::BEGIN: return "BEGIN";
    case RangeExprOffset::END: return "END";
    case RangeExprOffset::STEP: return "STEP";
    case RangeExprOffset::TOTAL: return "TOTAL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
