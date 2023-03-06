// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TailPaddingUseRules.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TailPaddingUseRules e) {
  switch (e) {
    case TailPaddingUseRules::ALWAYS_USE_TAIL_PADDING: return "ALWAYS_USE_TAIL_PADDING";
    case TailPaddingUseRules::USE_TAIL_PADDING_UNLESS_POD03: return "USE_TAIL_PADDING_UNLESS_POD03";
    case TailPaddingUseRules::USE_TAIL_PADDING_UNLESS_POD11: return "USE_TAIL_PADDING_UNLESS_POD11";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
