// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CoroDisableLifetimeBoundAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CoroDisableLifetimeBoundAttrSpelling e) {
  switch (e) {
    case CoroDisableLifetimeBoundAttrSpelling::GNU_CORO_DISABLE_LIFETIMEBOUND: return "GNU_CORO_DISABLE_LIFETIMEBOUND";
    case CoroDisableLifetimeBoundAttrSpelling::CXX11_CLANG_CORO_DISABLE_LIFETIMEBOUND: return "CXX11_CLANG_CORO_DISABLE_LIFETIMEBOUND";
    case CoroDisableLifetimeBoundAttrSpelling::C23_CLANG_CORO_DISABLE_LIFETIMEBOUND: return "C23_CLANG_CORO_DISABLE_LIFETIMEBOUND";
    case CoroDisableLifetimeBoundAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
