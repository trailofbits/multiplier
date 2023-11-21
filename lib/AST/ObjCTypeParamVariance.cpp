// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCTypeParamVariance.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCTypeParamVariance e) {
  switch (e) {
    case ObjCTypeParamVariance::INVARIANT: return "INVARIANT";
    case ObjCTypeParamVariance::COVARIANT: return "COVARIANT";
    case ObjCTypeParamVariance::CONTRAVARIANT: return "CONTRAVARIANT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
