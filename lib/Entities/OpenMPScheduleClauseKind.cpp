// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OpenMPScheduleClauseKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenMPScheduleClauseKind e) {
  switch (e) {
    case OpenMPScheduleClauseKind::STATIC: return "STATIC";
    case OpenMPScheduleClauseKind::DYNAMIC: return "DYNAMIC";
    case OpenMPScheduleClauseKind::GUIDED: return "GUIDED";
    case OpenMPScheduleClauseKind::AUTO: return "AUTO";
    case OpenMPScheduleClauseKind::RUNTIME: return "RUNTIME";
    case OpenMPScheduleClauseKind::UNKNOWN: return "UNKNOWN";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
