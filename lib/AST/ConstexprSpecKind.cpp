// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ConstexprSpecKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ConstexprSpecKind e) {
  switch (e) {
    case ConstexprSpecKind::UNSPECIFIED: return "UNSPECIFIED";
    case ConstexprSpecKind::CONSTEXPR: return "CONSTEXPR";
    case ConstexprSpecKind::CONSTEVAL: return "CONSTEVAL";
    case ConstexprSpecKind::CONSTINIT: return "CONSTINIT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
