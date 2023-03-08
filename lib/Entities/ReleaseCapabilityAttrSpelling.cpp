// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ReleaseCapabilityAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ReleaseCapabilityAttrSpelling e) {
  switch (e) {
    case ReleaseCapabilityAttrSpelling::GNU_RELEASE_CAPABILITY: return "GNU_RELEASE_CAPABILITY";
    case ReleaseCapabilityAttrSpelling::CXX11_CLANG_RELEASE_CAPABILITY: return "CXX11_CLANG_RELEASE_CAPABILITY";
    case ReleaseCapabilityAttrSpelling::GNU_RELEASE_SHARED_CAPABILITY: return "GNU_RELEASE_SHARED_CAPABILITY";
    case ReleaseCapabilityAttrSpelling::CXX11_CLANG_RELEASE_SHARED_CAPABILITY: return "CXX11_CLANG_RELEASE_SHARED_CAPABILITY";
    case ReleaseCapabilityAttrSpelling::GNU_RELEASE_GENERIC_CAPABILITY: return "GNU_RELEASE_GENERIC_CAPABILITY";
    case ReleaseCapabilityAttrSpelling::CXX11_CLANG_RELEASE_GENERIC_CAPABILITY: return "CXX11_CLANG_RELEASE_GENERIC_CAPABILITY";
    case ReleaseCapabilityAttrSpelling::GNU_UNLOCK_FUNCTION: return "GNU_UNLOCK_FUNCTION";
    case ReleaseCapabilityAttrSpelling::CXX11_CLANG_UNLOCK_FUNCTION: return "CXX11_CLANG_UNLOCK_FUNCTION";
    case ReleaseCapabilityAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
