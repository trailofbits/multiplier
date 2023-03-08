// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/InitPriorityAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(InitPriorityAttrSpelling e) {
  switch (e) {
    case InitPriorityAttrSpelling::GNU_INITIALIZER_PRIORITY: return "GNU_INITIALIZER_PRIORITY";
    case InitPriorityAttrSpelling::CXX11_GNU_INITIALIZER_PRIORITY: return "CXX11_GNU_INITIALIZER_PRIORITY";
    case InitPriorityAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
