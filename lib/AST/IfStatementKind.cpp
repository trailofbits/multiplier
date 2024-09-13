// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/IfStatementKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(IfStatementKind e) {
  switch (e) {
    case IfStatementKind::ORDINARY: return "ORDINARY";
    case IfStatementKind::CONSTEXPR: return "CONSTEXPR";
    case IfStatementKind::CONSTEVAL_NON_NEGATED: return "CONSTEVAL_NON_NEGATED";
    case IfStatementKind::CONSTEVAL_NEGATED: return "CONSTEVAL_NEGATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
