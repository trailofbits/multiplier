// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TypeTagForDatatypeAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TypeTagForDatatypeAttrSpelling e) {
  switch (e) {
    case TypeTagForDatatypeAttrSpelling::GNU_TYPE_TAG_FOR_DATATYPE: return "GNU_TYPE_TAG_FOR_DATATYPE";
    case TypeTagForDatatypeAttrSpelling::CXX11_CLANG_TYPE_TAG_FOR_DATATYPE: return "CXX11_CLANG_TYPE_TAG_FOR_DATATYPE";
    case TypeTagForDatatypeAttrSpelling::C2X_CLANG_TYPE_TAG_FOR_DATATYPE: return "C2X_CLANG_TYPE_TAG_FOR_DATATYPE";
    case TypeTagForDatatypeAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
