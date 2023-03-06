// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/AvailabilityResult.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AvailabilityResult e) {
  switch (e) {
    case AvailabilityResult::AVAILABLE: return "AVAILABLE";
    case AvailabilityResult::NOT_YET_INTRODUCED: return "NOT_YET_INTRODUCED";
    case AvailabilityResult::DEPRECATED: return "DEPRECATED";
    case AvailabilityResult::UNAVAILABLE: return "UNAVAILABLE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
