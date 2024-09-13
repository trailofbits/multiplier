// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/MinVectorWidthAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(MinVectorWidthAttrSpelling e) {
  switch (e) {
    case MinVectorWidthAttrSpelling::GNU_MIN_VECTOR_WIDTH: return "GNU_MIN_VECTOR_WIDTH";
    case MinVectorWidthAttrSpelling::CXX11_CLANG_MIN_VECTOR_WIDTH: return "CXX11_CLANG_MIN_VECTOR_WIDTH";
    case MinVectorWidthAttrSpelling::C23_CLANG_MIN_VECTOR_WIDTH: return "C23_CLANG_MIN_VECTOR_WIDTH";
    case MinVectorWidthAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
