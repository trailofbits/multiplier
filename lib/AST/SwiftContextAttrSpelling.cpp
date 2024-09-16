// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SwiftContextAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SwiftContextAttrSpelling e) {
  switch (e) {
    case SwiftContextAttrSpelling::GNU_SWIFT_CONTEXT: return "GNU_SWIFT_CONTEXT";
    case SwiftContextAttrSpelling::CXX11_CLANG_SWIFT_CONTEXT: return "CXX11_CLANG_SWIFT_CONTEXT";
    case SwiftContextAttrSpelling::C23_CLANG_SWIFT_CONTEXT: return "C23_CLANG_SWIFT_CONTEXT";
    case SwiftContextAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
