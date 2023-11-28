// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CFReturnsNotRetainedAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CFReturnsNotRetainedAttrSpelling e) {
  switch (e) {
    case CFReturnsNotRetainedAttrSpelling::GNU_CF_RETURNS_NOT_RETAINED: return "GNU_CF_RETURNS_NOT_RETAINED";
    case CFReturnsNotRetainedAttrSpelling::CXX11_CLANG_CF_RETURNS_NOT_RETAINED: return "CXX11_CLANG_CF_RETURNS_NOT_RETAINED";
    case CFReturnsNotRetainedAttrSpelling::C2X_CLANG_CF_RETURNS_NOT_RETAINED: return "C2X_CLANG_CF_RETURNS_NOT_RETAINED";
    case CFReturnsNotRetainedAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
