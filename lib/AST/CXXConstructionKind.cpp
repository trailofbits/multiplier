// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXXConstructionKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CXXConstructionKind e) {
  switch (e) {
    case CXXConstructionKind::COMPLETE: return "COMPLETE";
    case CXXConstructionKind::NON_VIRTUAL_BASE: return "NON_VIRTUAL_BASE";
    case CXXConstructionKind::VIRTUAL_BASE: return "VIRTUAL_BASE";
    case CXXConstructionKind::DELEGATING: return "DELEGATING";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
