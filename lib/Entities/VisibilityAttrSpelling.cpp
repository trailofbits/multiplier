// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/VisibilityAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(VisibilityAttrSpelling e) {
  switch (e) {
    case VisibilityAttrSpelling::GNU_VISIBILITY: return "GNU_VISIBILITY";
    case VisibilityAttrSpelling::CXX11_GNU_VISIBILITY: return "CXX11_GNU_VISIBILITY";
    case VisibilityAttrSpelling::C2X_GNU_VISIBILITY: return "C2X_GNU_VISIBILITY";
    case VisibilityAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
