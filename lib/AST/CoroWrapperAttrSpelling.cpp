// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CoroWrapperAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CoroWrapperAttrSpelling e) {
  switch (e) {
    case CoroWrapperAttrSpelling::GNU_CORO_WRAPPER: return "GNU_CORO_WRAPPER";
    case CoroWrapperAttrSpelling::CXX11_CLANG_CORO_WRAPPER: return "CXX11_CLANG_CORO_WRAPPER";
    case CoroWrapperAttrSpelling::C23_CLANG_CORO_WRAPPER: return "C23_CLANG_CORO_WRAPPER";
    case CoroWrapperAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
