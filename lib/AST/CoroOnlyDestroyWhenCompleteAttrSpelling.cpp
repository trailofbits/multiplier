// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CoroOnlyDestroyWhenCompleteAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CoroOnlyDestroyWhenCompleteAttrSpelling e) {
  switch (e) {
    case CoroOnlyDestroyWhenCompleteAttrSpelling::GNU_CORO_ONLY_DESTROY_WHEN_COMPLETE: return "GNU_CORO_ONLY_DESTROY_WHEN_COMPLETE";
    case CoroOnlyDestroyWhenCompleteAttrSpelling::CXX11_CLANG_CORO_ONLY_DESTROY_WHEN_COMPLETE: return "CXX11_CLANG_CORO_ONLY_DESTROY_WHEN_COMPLETE";
    case CoroOnlyDestroyWhenCompleteAttrSpelling::C23_CLANG_CORO_ONLY_DESTROY_WHEN_COMPLETE: return "C23_CLANG_CORO_ONLY_DESTROY_WHEN_COMPLETE";
    case CoroOnlyDestroyWhenCompleteAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
