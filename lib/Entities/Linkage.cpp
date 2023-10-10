// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/Linkage.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(Linkage e) {
  switch (e) {
    case Linkage::NO_LINKAGE: return "NO_LINKAGE";
    case Linkage::INTERNAL_LINKAGE: return "INTERNAL_LINKAGE";
    case Linkage::UNIQUE_EXTERNAL_LINKAGE: return "UNIQUE_EXTERNAL_LINKAGE";
    case Linkage::VISIBLE_NO_LINKAGE: return "VISIBLE_NO_LINKAGE";
    case Linkage::MODULE_LINKAGE: return "MODULE_LINKAGE";
    case Linkage::EXTERNAL_LINKAGE: return "EXTERNAL_LINKAGE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
