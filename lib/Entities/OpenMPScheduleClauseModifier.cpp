// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OpenMPScheduleClauseModifier.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenMPScheduleClauseModifier e) {
  switch (e) {
    case OpenMPScheduleClauseModifier::UNKNOWN: return "UNKNOWN";
    case OpenMPScheduleClauseModifier::MONOTONIC: return "MONOTONIC";
    case OpenMPScheduleClauseModifier::NONMONOTONIC: return "NONMONOTONIC";
    case OpenMPScheduleClauseModifier::SIMD: return "SIMD";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
