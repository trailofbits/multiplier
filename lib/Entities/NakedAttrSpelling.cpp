// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/NakedAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NakedAttrSpelling e) {
  switch (e) {
    case NakedAttrSpelling::GNU_NAKED: return "GNU_NAKED";
    case NakedAttrSpelling::CXX11_GNU_NAKED: return "CXX11_GNU_NAKED";
    case NakedAttrSpelling::C2X_GNU_NAKED: return "C2X_GNU_NAKED";
    case NakedAttrSpelling::DECLSPEC_NAKED: return "DECLSPEC_NAKED";
    case NakedAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
