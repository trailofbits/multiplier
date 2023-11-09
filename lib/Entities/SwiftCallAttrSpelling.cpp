// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/SwiftCallAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SwiftCallAttrSpelling e) {
  switch (e) {
    case SwiftCallAttrSpelling::GNU_SWIFTCALL: return "GNU_SWIFTCALL";
    case SwiftCallAttrSpelling::CXX11_CLANG_SWIFTCALL: return "CXX11_CLANG_SWIFTCALL";
    case SwiftCallAttrSpelling::C2X_CLANG_SWIFTCALL: return "C2X_CLANG_SWIFTCALL";
    case SwiftCallAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
