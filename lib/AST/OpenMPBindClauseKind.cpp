// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OpenMPBindClauseKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenMPBindClauseKind e) {
  switch (e) {
    case OpenMPBindClauseKind::BIND_TEAMS: return "BIND_TEAMS";
    case OpenMPBindClauseKind::BIND_PARALLEL: return "BIND_PARALLEL";
    case OpenMPBindClauseKind::BIND_THREAD: return "BIND_THREAD";
    case OpenMPBindClauseKind::BIND_UNKNOWN: return "BIND_UNKNOWN";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
