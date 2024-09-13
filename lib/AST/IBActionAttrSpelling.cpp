// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/IBActionAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(IBActionAttrSpelling e) {
  switch (e) {
    case IBActionAttrSpelling::GNU_IBACTION: return "GNU_IBACTION";
    case IBActionAttrSpelling::CXX11_CLANG_IBACTION: return "CXX11_CLANG_IBACTION";
    case IBActionAttrSpelling::C23_CLANG_IBACTION: return "C23_CLANG_IBACTION";
    case IBActionAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
