// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OSReturnsRetainedOnNonZeroAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OSReturnsRetainedOnNonZeroAttrSpelling e) {
  switch (e) {
    case OSReturnsRetainedOnNonZeroAttrSpelling::GNU_OS_RETURNS_RETAINED_ON_NON_ZERO: return "GNU_OS_RETURNS_RETAINED_ON_NON_ZERO";
    case OSReturnsRetainedOnNonZeroAttrSpelling::CXX11_CLANG_OS_RETURNS_RETAINED_ON_NON_ZERO: return "CXX11_CLANG_OS_RETURNS_RETAINED_ON_NON_ZERO";
    case OSReturnsRetainedOnNonZeroAttrSpelling::C2X_CLANG_OS_RETURNS_RETAINED_ON_NON_ZERO: return "C2X_CLANG_OS_RETURNS_RETAINED_ON_NON_ZERO";
    case OSReturnsRetainedOnNonZeroAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
