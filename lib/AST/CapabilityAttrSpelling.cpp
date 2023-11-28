// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CapabilityAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CapabilityAttrSpelling e) {
  switch (e) {
    case CapabilityAttrSpelling::GNU_CAPABILITY: return "GNU_CAPABILITY";
    case CapabilityAttrSpelling::CXX11_CLANG_CAPABILITY: return "CXX11_CLANG_CAPABILITY";
    case CapabilityAttrSpelling::GNU_SHARED_CAPABILITY: return "GNU_SHARED_CAPABILITY";
    case CapabilityAttrSpelling::CXX11_CLANG_SHARED_CAPABILITY: return "CXX11_CLANG_SHARED_CAPABILITY";
    case CapabilityAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
