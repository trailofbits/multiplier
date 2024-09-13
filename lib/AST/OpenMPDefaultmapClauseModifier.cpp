// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OpenMPDefaultmapClauseModifier.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenMPDefaultmapClauseModifier e) {
  switch (e) {
    case OpenMPDefaultmapClauseModifier::UNKNOWN: return "UNKNOWN";
    case OpenMPDefaultmapClauseModifier::ALLOC: return "ALLOC";
    case OpenMPDefaultmapClauseModifier::TO: return "TO";
    case OpenMPDefaultmapClauseModifier::FROM: return "FROM";
    case OpenMPDefaultmapClauseModifier::TOFROM: return "TOFROM";
    case OpenMPDefaultmapClauseModifier::NONE: return "NONE";
    case OpenMPDefaultmapClauseModifier::DEFAULT: return "DEFAULT";
    case OpenMPDefaultmapClauseModifier::PRESENT: return "PRESENT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
