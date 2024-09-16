// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/GuardedVarAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(GuardedVarAttrSpelling e) {
  switch (e) {
    case GuardedVarAttrSpelling::GNU_GUARDED_VARIABLE: return "GNU_GUARDED_VARIABLE";
    case GuardedVarAttrSpelling::CXX11_CLANG_GUARDED_VARIABLE: return "CXX11_CLANG_GUARDED_VARIABLE";
    case GuardedVarAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
