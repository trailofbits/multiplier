// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXX11NoReturnAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CXX11NoReturnAttrSpelling e) {
  switch (e) {
    case CXX11NoReturnAttrSpelling::CXX11_NORETURN: return "CXX11_NORETURN";
    case CXX11NoReturnAttrSpelling::C23_NORETURN: return "C23_NORETURN";
    case CXX11NoReturnAttrSpelling::C23___NORETURN: return "C23___NORETURN";
    case CXX11NoReturnAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
