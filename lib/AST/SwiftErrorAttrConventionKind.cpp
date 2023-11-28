// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SwiftErrorAttrConventionKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SwiftErrorAttrConventionKind e) {
  switch (e) {
    case SwiftErrorAttrConventionKind::NONE: return "NONE";
    case SwiftErrorAttrConventionKind::NON_NULL_ERROR: return "NON_NULL_ERROR";
    case SwiftErrorAttrConventionKind::NULL_RESULT: return "NULL_RESULT";
    case SwiftErrorAttrConventionKind::ZERO_RESULT: return "ZERO_RESULT";
    case SwiftErrorAttrConventionKind::NON_ZERO_RESULT: return "NON_ZERO_RESULT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
