// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TargetClonesAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TargetClonesAttrSpelling e) {
  switch (e) {
    case TargetClonesAttrSpelling::GNU_TARGET_CLONES: return "GNU_TARGET_CLONES";
    case TargetClonesAttrSpelling::CXX11_GNU_TARGET_CLONES: return "CXX11_GNU_TARGET_CLONES";
    case TargetClonesAttrSpelling::C2X_GNU_TARGET_CLONES: return "C2X_GNU_TARGET_CLONES";
    case TargetClonesAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
