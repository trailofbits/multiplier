// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ExprObjectKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ExprObjectKind e) {
  switch (e) {
    case ExprObjectKind::ORDINARY: return "ORDINARY";
    case ExprObjectKind::BIT_FIELD: return "BIT_FIELD";
    case ExprObjectKind::VECTOR_COMPONENT: return "VECTOR_COMPONENT";
    case ExprObjectKind::OBJ_C_PROPERTY: return "OBJ_C_PROPERTY";
    case ExprObjectKind::OBJ_C_SUBSCRIPT: return "OBJ_C_SUBSCRIPT";
    case ExprObjectKind::MATRIX_COMPONENT: return "MATRIX_COMPONENT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
