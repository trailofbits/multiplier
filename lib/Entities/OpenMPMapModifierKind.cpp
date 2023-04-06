// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OpenMPMapModifierKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenMPMapModifierKind e) {
  switch (e) {
    case OpenMPMapModifierKind::UNKNOWN: return "UNKNOWN";
    case OpenMPMapModifierKind::ALWAYS: return "ALWAYS";
    case OpenMPMapModifierKind::CLOSE: return "CLOSE";
    case OpenMPMapModifierKind::MAPPER: return "MAPPER";
    case OpenMPMapModifierKind::ITERATOR: return "ITERATOR";
    case OpenMPMapModifierKind::PRESENT: return "PRESENT";
    case OpenMPMapModifierKind::OMPX_HOLD: return "OMPX_HOLD";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
