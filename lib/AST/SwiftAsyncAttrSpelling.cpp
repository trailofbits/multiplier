// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SwiftAsyncAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SwiftAsyncAttrSpelling e) {
  switch (e) {
    case SwiftAsyncAttrSpelling::GNU_SWIFT_ASYNC: return "GNU_SWIFT_ASYNC";
    case SwiftAsyncAttrSpelling::CXX11_CLANG_SWIFT_ASYNC: return "CXX11_CLANG_SWIFT_ASYNC";
    case SwiftAsyncAttrSpelling::C23_CLANG_SWIFT_ASYNC: return "C23_CLANG_SWIFT_ASYNC";
    case SwiftAsyncAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
