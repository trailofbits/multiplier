// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/NullabilityKind.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NullabilityKind e) {
  switch (e) {
    case NullabilityKind::NON_NULL: return "NON_NULL";
    case NullabilityKind::NULLABLE: return "NULLABLE";
    case NullabilityKind::UNSPECIFIED: return "UNSPECIFIED";
    case NullabilityKind::NULLABLE_RESULT: return "NULLABLE_RESULT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
