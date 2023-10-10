// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/NSReturnsRetainedAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NSReturnsRetainedAttrSpelling e) {
  switch (e) {
    case NSReturnsRetainedAttrSpelling::GNU_NS_RETURNS_RETAINED: return "GNU_NS_RETURNS_RETAINED";
    case NSReturnsRetainedAttrSpelling::CXX11_CLANG_NS_RETURNS_RETAINED: return "CXX11_CLANG_NS_RETURNS_RETAINED";
    case NSReturnsRetainedAttrSpelling::C23_CLANG_NS_RETURNS_RETAINED: return "C23_CLANG_NS_RETURNS_RETAINED";
    case NSReturnsRetainedAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
