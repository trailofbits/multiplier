// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ExplicitSpecKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ExplicitSpecKind e) {
  switch (e) {
    case ExplicitSpecKind::RESOLVED_FALSE: return "RESOLVED_FALSE";
    case ExplicitSpecKind::RESOLVED_TRUE: return "RESOLVED_TRUE";
    case ExplicitSpecKind::UNRESOLVED: return "UNRESOLVED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
