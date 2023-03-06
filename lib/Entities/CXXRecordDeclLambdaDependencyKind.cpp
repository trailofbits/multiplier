// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXRecordDeclLambdaDependencyKind.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CXXRecordDeclLambdaDependencyKind e) {
  switch (e) {
    case CXXRecordDeclLambdaDependencyKind::UNKNOWN: return "UNKNOWN";
    case CXXRecordDeclLambdaDependencyKind::ALWAYS_DEPENDENT: return "ALWAYS_DEPENDENT";
    case CXXRecordDeclLambdaDependencyKind::NEVER_DEPENDENT: return "NEVER_DEPENDENT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
