// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/WeakRefAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(WeakRefAttrSpelling e) {
  switch (e) {
    case WeakRefAttrSpelling::GNU_WEAKREF: return "GNU_WEAKREF";
    case WeakRefAttrSpelling::CXX11_GNU_WEAKREF: return "CXX11_GNU_WEAKREF";
    case WeakRefAttrSpelling::C23_GNU_WEAKREF: return "C23_GNU_WEAKREF";
    case WeakRefAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
