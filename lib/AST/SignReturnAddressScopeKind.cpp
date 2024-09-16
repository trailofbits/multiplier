// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SignReturnAddressScopeKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SignReturnAddressScopeKind e) {
  switch (e) {
    case SignReturnAddressScopeKind::NONE: return "NONE";
    case SignReturnAddressScopeKind::NON_LEAF: return "NON_LEAF";
    case SignReturnAddressScopeKind::ALL: return "ALL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
