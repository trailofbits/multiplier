// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/NoEscapeAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NoEscapeAttrSpelling e) {
  switch (e) {
    case NoEscapeAttrSpelling::GNU_NOESCAPE: return "GNU_NOESCAPE";
    case NoEscapeAttrSpelling::CXX11_CLANG_NOESCAPE: return "CXX11_CLANG_NOESCAPE";
    case NoEscapeAttrSpelling::C23_CLANG_NOESCAPE: return "C23_CLANG_NOESCAPE";
    case NoEscapeAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
