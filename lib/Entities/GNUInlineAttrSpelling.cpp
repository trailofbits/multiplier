// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/GNUInlineAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(GNUInlineAttrSpelling e) {
  switch (e) {
    case GNUInlineAttrSpelling::GNU_GNU_INLINE: return "GNU_GNU_INLINE";
    case GNUInlineAttrSpelling::CXX11_GNU_GNU_INLINE: return "CXX11_GNU_GNU_INLINE";
    case GNUInlineAttrSpelling::C2X_GNU_GNU_INLINE: return "C2X_GNU_GNU_INLINE";
    case GNUInlineAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
