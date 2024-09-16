// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ExternalSourceSymbolAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ExternalSourceSymbolAttrSpelling e) {
  switch (e) {
    case ExternalSourceSymbolAttrSpelling::GNU_EXTERNAL_SOURCE_SYMBOL: return "GNU_EXTERNAL_SOURCE_SYMBOL";
    case ExternalSourceSymbolAttrSpelling::CXX11_CLANG_EXTERNAL_SOURCE_SYMBOL: return "CXX11_CLANG_EXTERNAL_SOURCE_SYMBOL";
    case ExternalSourceSymbolAttrSpelling::C23_CLANG_EXTERNAL_SOURCE_SYMBOL: return "C23_CLANG_EXTERNAL_SOURCE_SYMBOL";
    case ExternalSourceSymbolAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
