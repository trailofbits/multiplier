// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SwiftIndirectResultAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SwiftIndirectResultAttrSpelling e) {
  switch (e) {
    case SwiftIndirectResultAttrSpelling::GNU_SWIFT_INDIRECT_RESULT: return "GNU_SWIFT_INDIRECT_RESULT";
    case SwiftIndirectResultAttrSpelling::CXX11_CLANG_SWIFT_INDIRECT_RESULT: return "CXX11_CLANG_SWIFT_INDIRECT_RESULT";
    case SwiftIndirectResultAttrSpelling::C2X_CLANG_SWIFT_INDIRECT_RESULT: return "C2X_CLANG_SWIFT_INDIRECT_RESULT";
    case SwiftIndirectResultAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
