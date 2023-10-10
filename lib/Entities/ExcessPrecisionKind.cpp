// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ExcessPrecisionKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ExcessPrecisionKind e) {
  switch (e) {
    case ExcessPrecisionKind::FPP_STANDARD: return "FPP_STANDARD";
    case ExcessPrecisionKind::FPP_FAST: return "FPP_FAST";
    case ExcessPrecisionKind::FPP_NONE: return "FPP_NONE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
