// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/PreferredTypeAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(PreferredTypeAttrSpelling e) {
  switch (e) {
    case PreferredTypeAttrSpelling::GNU_PREFERRED_TYPE: return "GNU_PREFERRED_TYPE";
    case PreferredTypeAttrSpelling::CXX11_CLANG_PREFERRED_TYPE: return "CXX11_CLANG_PREFERRED_TYPE";
    case PreferredTypeAttrSpelling::C23_CLANG_PREFERRED_TYPE: return "C23_CLANG_PREFERRED_TYPE";
    case PreferredTypeAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
