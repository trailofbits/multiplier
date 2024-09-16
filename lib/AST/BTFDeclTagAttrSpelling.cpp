// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/BTFDeclTagAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(BTFDeclTagAttrSpelling e) {
  switch (e) {
    case BTFDeclTagAttrSpelling::GNU_BTF_DECLARATION_TAG: return "GNU_BTF_DECLARATION_TAG";
    case BTFDeclTagAttrSpelling::CXX11_CLANG_BTF_DECLARATION_TAG: return "CXX11_CLANG_BTF_DECLARATION_TAG";
    case BTFDeclTagAttrSpelling::C23_CLANG_BTF_DECLARATION_TAG: return "C23_CLANG_BTF_DECLARATION_TAG";
    case BTFDeclTagAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
