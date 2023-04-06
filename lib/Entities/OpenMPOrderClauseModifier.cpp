// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OpenMPOrderClauseModifier.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenMPOrderClauseModifier e) {
  switch (e) {
    case OpenMPOrderClauseModifier::MODIFIER_UNKNOWN: return "MODIFIER_UNKNOWN";
    case OpenMPOrderClauseModifier::MODIFIER_REPRODUCIBLE: return "MODIFIER_REPRODUCIBLE";
    case OpenMPOrderClauseModifier::MODIFIER_UNCONSTRAINED: return "MODIFIER_UNCONSTRAINED";
    case OpenMPOrderClauseModifier::MODIFIER_LAST: return "MODIFIER_LAST";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
