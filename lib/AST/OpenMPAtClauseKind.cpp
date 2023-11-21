// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OpenMPAtClauseKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenMPAtClauseKind e) {
  switch (e) {
    case OpenMPAtClauseKind::AT_COMPILATION: return "AT_COMPILATION";
    case OpenMPAtClauseKind::AT_EXECUTION: return "AT_EXECUTION";
    case OpenMPAtClauseKind::AT_UNKNOWN: return "AT_UNKNOWN";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
