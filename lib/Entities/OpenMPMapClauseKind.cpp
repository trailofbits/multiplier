// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OpenMPMapClauseKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenMPMapClauseKind e) {
  switch (e) {
    case OpenMPMapClauseKind::ALLOC: return "ALLOC";
    case OpenMPMapClauseKind::TO: return "TO";
    case OpenMPMapClauseKind::FROM: return "FROM";
    case OpenMPMapClauseKind::TOFROM: return "TOFROM";
    case OpenMPMapClauseKind::DELETE: return "DELETE";
    case OpenMPMapClauseKind::RELEASE: return "RELEASE";
    case OpenMPMapClauseKind::UNKNOWN: return "UNKNOWN";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
