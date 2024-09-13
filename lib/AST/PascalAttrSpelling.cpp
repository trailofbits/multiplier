// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/PascalAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(PascalAttrSpelling e) {
  switch (e) {
    case PascalAttrSpelling::GNU_PASCAL: return "GNU_PASCAL";
    case PascalAttrSpelling::CXX11_CLANG_PASCAL: return "CXX11_CLANG_PASCAL";
    case PascalAttrSpelling::C23_CLANG_PASCAL: return "C23_CLANG_PASCAL";
    case PascalAttrSpelling::KEYWORD_PASCAL: return "KEYWORD_PASCAL";
    case PascalAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
