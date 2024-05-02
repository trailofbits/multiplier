// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CFReturnsRetainedAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CFReturnsRetainedAttrSpelling e) {
  switch (e) {
    case CFReturnsRetainedAttrSpelling::GNU_CF_RETURNS_RETAINED: return "GNU_CF_RETURNS_RETAINED";
    case CFReturnsRetainedAttrSpelling::CXX11_CLANG_CF_RETURNS_RETAINED: return "CXX11_CLANG_CF_RETURNS_RETAINED";
    case CFReturnsRetainedAttrSpelling::C23_CLANG_CF_RETURNS_RETAINED: return "C23_CLANG_CF_RETURNS_RETAINED";
    case CFReturnsRetainedAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
