// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CoroLifetimeBoundAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CoroLifetimeBoundAttrSpelling e) {
  switch (e) {
    case CoroLifetimeBoundAttrSpelling::GNU_CORO_LIFETIMEBOUND: return "GNU_CORO_LIFETIMEBOUND";
    case CoroLifetimeBoundAttrSpelling::CXX11_CLANG_CORO_LIFETIMEBOUND: return "CXX11_CLANG_CORO_LIFETIMEBOUND";
    case CoroLifetimeBoundAttrSpelling::C23_CLANG_CORO_LIFETIMEBOUND: return "C23_CLANG_CORO_LIFETIMEBOUND";
    case CoroLifetimeBoundAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
