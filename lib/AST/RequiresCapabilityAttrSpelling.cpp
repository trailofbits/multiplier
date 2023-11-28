// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/RequiresCapabilityAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(RequiresCapabilityAttrSpelling e) {
  switch (e) {
    case RequiresCapabilityAttrSpelling::GNU_REQUIRES_CAPABILITY: return "GNU_REQUIRES_CAPABILITY";
    case RequiresCapabilityAttrSpelling::CXX11_CLANG_REQUIRES_CAPABILITY: return "CXX11_CLANG_REQUIRES_CAPABILITY";
    case RequiresCapabilityAttrSpelling::GNU_EXCLUSIVE_LOCKS_REQUIRED: return "GNU_EXCLUSIVE_LOCKS_REQUIRED";
    case RequiresCapabilityAttrSpelling::CXX11_CLANG_EXCLUSIVE_LOCKS_REQUIRED: return "CXX11_CLANG_EXCLUSIVE_LOCKS_REQUIRED";
    case RequiresCapabilityAttrSpelling::GNU_REQUIRES_SHARED_CAPABILITY: return "GNU_REQUIRES_SHARED_CAPABILITY";
    case RequiresCapabilityAttrSpelling::CXX11_CLANG_REQUIRES_SHARED_CAPABILITY: return "CXX11_CLANG_REQUIRES_SHARED_CAPABILITY";
    case RequiresCapabilityAttrSpelling::GNU_SHARED_LOCKS_REQUIRED: return "GNU_SHARED_LOCKS_REQUIRED";
    case RequiresCapabilityAttrSpelling::CXX11_CLANG_SHARED_LOCKS_REQUIRED: return "CXX11_CLANG_SHARED_LOCKS_REQUIRED";
    case RequiresCapabilityAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
