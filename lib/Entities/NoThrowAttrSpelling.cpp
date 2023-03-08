// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/NoThrowAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NoThrowAttrSpelling e) {
  switch (e) {
    case NoThrowAttrSpelling::GNU_NOTHROW: return "GNU_NOTHROW";
    case NoThrowAttrSpelling::CXX11_GNU_NOTHROW: return "CXX11_GNU_NOTHROW";
    case NoThrowAttrSpelling::C2X_GNU_NOTHROW: return "C2X_GNU_NOTHROW";
    case NoThrowAttrSpelling::DECLSPEC_NOTHROW: return "DECLSPEC_NOTHROW";
    case NoThrowAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
