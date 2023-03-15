// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/PtGuardedVarAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(PtGuardedVarAttrSpelling e) {
  switch (e) {
    case PtGuardedVarAttrSpelling::GNU_PT_GUARDED_VARIABLE: return "GNU_PT_GUARDED_VARIABLE";
    case PtGuardedVarAttrSpelling::CXX11_CLANG_PT_GUARDED_VARIABLE: return "CXX11_CLANG_PT_GUARDED_VARIABLE";
    case PtGuardedVarAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
