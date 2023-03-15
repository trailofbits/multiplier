// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/GVALinkage.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(GVALinkage e) {
  switch (e) {
    case GVALinkage::INTERNAL: return "INTERNAL";
    case GVALinkage::AVAILABLE_EXTERNALLY: return "AVAILABLE_EXTERNALLY";
    case GVALinkage::DISCARDABLE_ODR: return "DISCARDABLE_ODR";
    case GVALinkage::STRONG_EXTERNAL: return "STRONG_EXTERNAL";
    case GVALinkage::STRONG_ODR: return "STRONG_ODR";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
