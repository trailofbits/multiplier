// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/QualTypePrimitiveDefaultInitializeKind.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(QualTypePrimitiveDefaultInitializeKind e) {
  switch (e) {
    case QualTypePrimitiveDefaultInitializeKind::TRIVIAL: return "TRIVIAL";
    case QualTypePrimitiveDefaultInitializeKind::ARC_STRONG: return "ARC_STRONG";
    case QualTypePrimitiveDefaultInitializeKind::ARC_WEAK: return "ARC_WEAK";
    case QualTypePrimitiveDefaultInitializeKind::STRUCT: return "STRUCT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
