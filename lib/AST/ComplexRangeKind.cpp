// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ComplexRangeKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ComplexRangeKind e) {
  switch (e) {
    case ComplexRangeKind::CX_FULL: return "CX_FULL";
    case ComplexRangeKind::CX_LIMITED: return "CX_LIMITED";
    case ComplexRangeKind::CX_FORTRAN: return "CX_FORTRAN";
    case ComplexRangeKind::CX_NONE: return "CX_NONE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
