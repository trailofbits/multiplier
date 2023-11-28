// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/NSReturnsNotRetainedAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NSReturnsNotRetainedAttrSpelling e) {
  switch (e) {
    case NSReturnsNotRetainedAttrSpelling::GNU_NS_RETURNS_NOT_RETAINED: return "GNU_NS_RETURNS_NOT_RETAINED";
    case NSReturnsNotRetainedAttrSpelling::CXX11_CLANG_NS_RETURNS_NOT_RETAINED: return "CXX11_CLANG_NS_RETURNS_NOT_RETAINED";
    case NSReturnsNotRetainedAttrSpelling::C2X_CLANG_NS_RETURNS_NOT_RETAINED: return "C2X_CLANG_NS_RETURNS_NOT_RETAINED";
    case NSReturnsNotRetainedAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
