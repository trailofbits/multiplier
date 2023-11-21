// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ConstantExprResultStorageKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ConstantExprResultStorageKind e) {
  switch (e) {
    case ConstantExprResultStorageKind::NONE: return "NONE";
    case ConstantExprResultStorageKind::INT64: return "INT64";
    case ConstantExprResultStorageKind::AP_VALUE: return "AP_VALUE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
