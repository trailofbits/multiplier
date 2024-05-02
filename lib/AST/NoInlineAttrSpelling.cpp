// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/NoInlineAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NoInlineAttrSpelling e) {
  switch (e) {
    case NoInlineAttrSpelling::KEYWORD_NOINLINE: return "KEYWORD_NOINLINE";
    case NoInlineAttrSpelling::GNU_NOINLINE: return "GNU_NOINLINE";
    case NoInlineAttrSpelling::CXX11_GNU_NOINLINE: return "CXX11_GNU_NOINLINE";
    case NoInlineAttrSpelling::C23_GNU_NOINLINE: return "C23_GNU_NOINLINE";
    case NoInlineAttrSpelling::CXX11_CLANG_NOINLINE: return "CXX11_CLANG_NOINLINE";
    case NoInlineAttrSpelling::C23_CLANG_NOINLINE: return "C23_CLANG_NOINLINE";
    case NoInlineAttrSpelling::DECLSPEC_NOINLINE: return "DECLSPEC_NOINLINE";
    case NoInlineAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
