// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AcquireCapabilityAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AcquireCapabilityAttrSpelling e) {
  switch (e) {
    case AcquireCapabilityAttrSpelling::GNU_ACQUIRE_CAPABILITY: return "GNU_ACQUIRE_CAPABILITY";
    case AcquireCapabilityAttrSpelling::CXX11_CLANG_ACQUIRE_CAPABILITY: return "CXX11_CLANG_ACQUIRE_CAPABILITY";
    case AcquireCapabilityAttrSpelling::GNU_ACQUIRE_SHARED_CAPABILITY: return "GNU_ACQUIRE_SHARED_CAPABILITY";
    case AcquireCapabilityAttrSpelling::CXX11_CLANG_ACQUIRE_SHARED_CAPABILITY: return "CXX11_CLANG_ACQUIRE_SHARED_CAPABILITY";
    case AcquireCapabilityAttrSpelling::GNU_EXCLUSIVE_LOCK_FUNCTION: return "GNU_EXCLUSIVE_LOCK_FUNCTION";
    case AcquireCapabilityAttrSpelling::GNU_SHARED_LOCK_FUNCTION: return "GNU_SHARED_LOCK_FUNCTION";
    case AcquireCapabilityAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
