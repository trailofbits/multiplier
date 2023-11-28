// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/PragmaMSPointersToMembersKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(PragmaMSPointersToMembersKind e) {
  switch (e) {
    case PragmaMSPointersToMembersKind::BEST_CASE: return "BEST_CASE";
    case PragmaMSPointersToMembersKind::FULL_GENERALITY_SINGLE_INHERITANCE: return "FULL_GENERALITY_SINGLE_INHERITANCE";
    case PragmaMSPointersToMembersKind::FULL_GENERALITY_MULTIPLE_INHERITANCE: return "FULL_GENERALITY_MULTIPLE_INHERITANCE";
    case PragmaMSPointersToMembersKind::FULL_GENERALITY_VIRTUAL_INHERITANCE: return "FULL_GENERALITY_VIRTUAL_INHERITANCE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
