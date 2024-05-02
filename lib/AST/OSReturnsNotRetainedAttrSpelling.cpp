// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OSReturnsNotRetainedAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OSReturnsNotRetainedAttrSpelling e) {
  switch (e) {
    case OSReturnsNotRetainedAttrSpelling::GNU_OS_RETURNS_NOT_RETAINED: return "GNU_OS_RETURNS_NOT_RETAINED";
    case OSReturnsNotRetainedAttrSpelling::CXX11_CLANG_OS_RETURNS_NOT_RETAINED: return "CXX11_CLANG_OS_RETURNS_NOT_RETAINED";
    case OSReturnsNotRetainedAttrSpelling::C23_CLANG_OS_RETURNS_NOT_RETAINED: return "C23_CLANG_OS_RETURNS_NOT_RETAINED";
    case OSReturnsNotRetainedAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
