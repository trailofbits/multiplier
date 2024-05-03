// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CoroReturnTypeAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CoroReturnTypeAttrSpelling e) {
  switch (e) {
    case CoroReturnTypeAttrSpelling::GNU_CORO_RETURN_TYPE: return "GNU_CORO_RETURN_TYPE";
    case CoroReturnTypeAttrSpelling::CXX11_CLANG_CORO_RETURN_TYPE: return "CXX11_CLANG_CORO_RETURN_TYPE";
    case CoroReturnTypeAttrSpelling::C23_CLANG_CORO_RETURN_TYPE: return "C23_CLANG_CORO_RETURN_TYPE";
    case CoroReturnTypeAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
