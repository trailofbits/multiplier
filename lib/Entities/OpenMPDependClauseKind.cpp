// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OpenMPDependClauseKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenMPDependClauseKind e) {
  switch (e) {
    case OpenMPDependClauseKind::IN: return "IN";
    case OpenMPDependClauseKind::OUT: return "OUT";
    case OpenMPDependClauseKind::INOUT: return "INOUT";
    case OpenMPDependClauseKind::MUTEXINOUTSET: return "MUTEXINOUTSET";
    case OpenMPDependClauseKind::DEPOBJ: return "DEPOBJ";
    case OpenMPDependClauseKind::SOURCE: return "SOURCE";
    case OpenMPDependClauseKind::SINK: return "SINK";
    case OpenMPDependClauseKind::INOUTSET: return "INOUTSET";
    case OpenMPDependClauseKind::OUTALLMEMORY: return "OUTALLMEMORY";
    case OpenMPDependClauseKind::INOUTALLMEMORY: return "INOUTALLMEMORY";
    case OpenMPDependClauseKind::UNKNOWN: return "UNKNOWN";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
