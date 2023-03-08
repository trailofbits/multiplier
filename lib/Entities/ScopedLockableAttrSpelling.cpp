// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ScopedLockableAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ScopedLockableAttrSpelling e) {
  switch (e) {
    case ScopedLockableAttrSpelling::GNU_SCOPED_LOCKABLE: return "GNU_SCOPED_LOCKABLE";
    case ScopedLockableAttrSpelling::CXX11_CLANG_SCOPED_LOCKABLE: return "CXX11_CLANG_SCOPED_LOCKABLE";
    case ScopedLockableAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
