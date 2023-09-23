// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/SwiftAsyncCallAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SwiftAsyncCallAttrSpelling e) {
  switch (e) {
    case SwiftAsyncCallAttrSpelling::GNU_SWIFTASYNCCALL: return "GNU_SWIFTASYNCCALL";
    case SwiftAsyncCallAttrSpelling::CXX11_CLANG_SWIFTASYNCCALL: return "CXX11_CLANG_SWIFTASYNCCALL";
    case SwiftAsyncCallAttrSpelling::C23_CLANG_SWIFTASYNCCALL: return "C23_CLANG_SWIFTASYNCCALL";
    case SwiftAsyncCallAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
