// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OpenMPAtomicDefaultMemOrderClauseKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenMPAtomicDefaultMemOrderClauseKind e) {
  switch (e) {
    case OpenMPAtomicDefaultMemOrderClauseKind::SEQ_CST: return "SEQ_CST";
    case OpenMPAtomicDefaultMemOrderClauseKind::ACQ_REL: return "ACQ_REL";
    case OpenMPAtomicDefaultMemOrderClauseKind::RELAXED: return "RELAXED";
    case OpenMPAtomicDefaultMemOrderClauseKind::UNKNOWN: return "UNKNOWN";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
