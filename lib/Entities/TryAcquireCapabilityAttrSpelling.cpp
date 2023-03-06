// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TryAcquireCapabilityAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TryAcquireCapabilityAttrSpelling e) {
  switch (e) {
    case TryAcquireCapabilityAttrSpelling::GNU_TRY_ACQUIRE_CAPABILITY: return "GNU_TRY_ACQUIRE_CAPABILITY";
    case TryAcquireCapabilityAttrSpelling::CXX11_CLANG_TRY_ACQUIRE_CAPABILITY: return "CXX11_CLANG_TRY_ACQUIRE_CAPABILITY";
    case TryAcquireCapabilityAttrSpelling::GNU_TRY_ACQUIRE_SHARED_CAPABILITY: return "GNU_TRY_ACQUIRE_SHARED_CAPABILITY";
    case TryAcquireCapabilityAttrSpelling::CXX11_CLANG_TRY_ACQUIRE_SHARED_CAPABILITY: return "CXX11_CLANG_TRY_ACQUIRE_SHARED_CAPABILITY";
    case TryAcquireCapabilityAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
