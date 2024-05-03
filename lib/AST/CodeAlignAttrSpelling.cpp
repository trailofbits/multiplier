// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CodeAlignAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CodeAlignAttrSpelling e) {
  switch (e) {
    case CodeAlignAttrSpelling::GNU_CODE_ALIGN: return "GNU_CODE_ALIGN";
    case CodeAlignAttrSpelling::CXX11_CLANG_CODE_ALIGN: return "CXX11_CLANG_CODE_ALIGN";
    case CodeAlignAttrSpelling::C23_CLANG_CODE_ALIGN: return "C23_CLANG_CODE_ALIGN";
    case CodeAlignAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
