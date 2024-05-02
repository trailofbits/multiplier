// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SwiftAsyncContextAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SwiftAsyncContextAttrSpelling e) {
  switch (e) {
    case SwiftAsyncContextAttrSpelling::GNU_SWIFT_ASYNC_CONTEXT: return "GNU_SWIFT_ASYNC_CONTEXT";
    case SwiftAsyncContextAttrSpelling::CXX11_CLANG_SWIFT_ASYNC_CONTEXT: return "CXX11_CLANG_SWIFT_ASYNC_CONTEXT";
    case SwiftAsyncContextAttrSpelling::C23_CLANG_SWIFT_ASYNC_CONTEXT: return "C23_CLANG_SWIFT_ASYNC_CONTEXT";
    case SwiftAsyncContextAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
