// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OpenMPLinearClauseKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenMPLinearClauseKind e) {
  switch (e) {
    case OpenMPLinearClauseKind::VALUE: return "VALUE";
    case OpenMPLinearClauseKind::REFERENCE: return "REFERENCE";
    case OpenMPLinearClauseKind::UVAL: return "UVAL";
    case OpenMPLinearClauseKind::STEP: return "STEP";
    case OpenMPLinearClauseKind::UNKNOWN: return "UNKNOWN";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
