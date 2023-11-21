// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SwiftAsyncErrorAttrConventionKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SwiftAsyncErrorAttrConventionKind e) {
  switch (e) {
    case SwiftAsyncErrorAttrConventionKind::NONE: return "NONE";
    case SwiftAsyncErrorAttrConventionKind::NON_NULL_ERROR: return "NON_NULL_ERROR";
    case SwiftAsyncErrorAttrConventionKind::ZERO_ARGUMENT: return "ZERO_ARGUMENT";
    case SwiftAsyncErrorAttrConventionKind::NON_ZERO_ARGUMENT: return "NON_ZERO_ARGUMENT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
