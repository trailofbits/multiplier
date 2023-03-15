// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/AssertCapabilityAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AssertCapabilityAttrSpelling e) {
  switch (e) {
    case AssertCapabilityAttrSpelling::GNU_ASSERT_CAPABILITY: return "GNU_ASSERT_CAPABILITY";
    case AssertCapabilityAttrSpelling::CXX11_CLANG_ASSERT_CAPABILITY: return "CXX11_CLANG_ASSERT_CAPABILITY";
    case AssertCapabilityAttrSpelling::GNU_ASSERT_SHARED_CAPABILITY: return "GNU_ASSERT_SHARED_CAPABILITY";
    case AssertCapabilityAttrSpelling::CXX11_CLANG_ASSERT_SHARED_CAPABILITY: return "CXX11_CLANG_ASSERT_SHARED_CAPABILITY";
    case AssertCapabilityAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
