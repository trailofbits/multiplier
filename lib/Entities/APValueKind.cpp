// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/APValueKind.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(APValueKind e) {
  switch (e) {
    case APValueKind::NONE: return "NONE";
    case APValueKind::INDETERMINATE: return "INDETERMINATE";
    case APValueKind::INT: return "INT";
    case APValueKind::FLOAT: return "FLOAT";
    case APValueKind::FIXED_POINT: return "FIXED_POINT";
    case APValueKind::COMPLEX_INT: return "COMPLEX_INT";
    case APValueKind::COMPLEX_FLOAT: return "COMPLEX_FLOAT";
    case APValueKind::L_VALUE: return "L_VALUE";
    case APValueKind::VECTOR: return "VECTOR";
    case APValueKind::ARRAY: return "ARRAY";
    case APValueKind::STRUCT: return "STRUCT";
    case APValueKind::UNION: return "UNION";
    case APValueKind::MEMBER_POINTER: return "MEMBER_POINTER";
    case APValueKind::ADDRESS_LABEL_DIFF: return "ADDRESS_LABEL_DIFF";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
