// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OpenMPReductionClauseModifier.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenMPReductionClauseModifier e) {
  switch (e) {
    case OpenMPReductionClauseModifier::DEFAULT: return "DEFAULT";
    case OpenMPReductionClauseModifier::INSCAN: return "INSCAN";
    case OpenMPReductionClauseModifier::TASK: return "TASK";
    case OpenMPReductionClauseModifier::UNKNOWN: return "UNKNOWN";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
