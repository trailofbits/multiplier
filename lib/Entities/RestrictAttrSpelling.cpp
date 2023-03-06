// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/RestrictAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(RestrictAttrSpelling e) {
  switch (e) {
    case RestrictAttrSpelling::DECLSPEC_RESTRICT: return "DECLSPEC_RESTRICT";
    case RestrictAttrSpelling::GNU_MALLOC: return "GNU_MALLOC";
    case RestrictAttrSpelling::CXX11_GNU_MALLOC: return "CXX11_GNU_MALLOC";
    case RestrictAttrSpelling::C2X_GNU_MALLOC: return "C2X_GNU_MALLOC";
    case RestrictAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
