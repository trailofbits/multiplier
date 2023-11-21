// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/NoReturnAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NoReturnAttrSpelling e) {
  switch (e) {
    case NoReturnAttrSpelling::GNU_NORETURN: return "GNU_NORETURN";
    case NoReturnAttrSpelling::CXX11_GNU_NORETURN: return "CXX11_GNU_NORETURN";
    case NoReturnAttrSpelling::C2X_GNU_NORETURN: return "C2X_GNU_NORETURN";
    case NoReturnAttrSpelling::DECLSPEC_NORETURN: return "DECLSPEC_NORETURN";
    case NoReturnAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
