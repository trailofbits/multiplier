// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DesignatorKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(DesignatorKind e) {
  switch (e) {
    case DesignatorKind::FIELD_DESIGNATOR: return "FIELD_DESIGNATOR";
    case DesignatorKind::ARRAY_DESIGNATOR: return "ARRAY_DESIGNATOR";
    case DesignatorKind::ARRAY_RANGE_DESIGNATOR: return "ARRAY_RANGE_DESIGNATOR";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
