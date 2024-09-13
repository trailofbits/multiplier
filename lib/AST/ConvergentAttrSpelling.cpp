// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ConvergentAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ConvergentAttrSpelling e) {
  switch (e) {
    case ConvergentAttrSpelling::GNU_CONVERGENT: return "GNU_CONVERGENT";
    case ConvergentAttrSpelling::CXX11_CLANG_CONVERGENT: return "CXX11_CLANG_CONVERGENT";
    case ConvergentAttrSpelling::C23_CLANG_CONVERGENT: return "C23_CLANG_CONVERGENT";
    case ConvergentAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
