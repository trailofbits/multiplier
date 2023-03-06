// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/StructReturnConventionKind.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(StructReturnConventionKind e) {
  switch (e) {
    case StructReturnConventionKind::DEFAULT: return "DEFAULT";
    case StructReturnConventionKind::ON_STACK: return "ON_STACK";
    case StructReturnConventionKind::IN_REGS: return "IN_REGS";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
