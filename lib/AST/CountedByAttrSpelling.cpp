// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CountedByAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CountedByAttrSpelling e) {
  switch (e) {
    case CountedByAttrSpelling::GNU_COUNTED_BY: return "GNU_COUNTED_BY";
    case CountedByAttrSpelling::CXX11_CLANG_COUNTED_BY: return "CXX11_CLANG_COUNTED_BY";
    case CountedByAttrSpelling::C23_CLANG_COUNTED_BY: return "C23_CLANG_COUNTED_BY";
    case CountedByAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
