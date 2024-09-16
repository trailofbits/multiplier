// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/VectorCallAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(VectorCallAttrSpelling e) {
  switch (e) {
    case VectorCallAttrSpelling::GNU_VECTORCALL: return "GNU_VECTORCALL";
    case VectorCallAttrSpelling::CXX11_CLANG_VECTORCALL: return "CXX11_CLANG_VECTORCALL";
    case VectorCallAttrSpelling::C23_CLANG_VECTORCALL: return "C23_CLANG_VECTORCALL";
    case VectorCallAttrSpelling::KEYWORD_VECTORCALL: return "KEYWORD_VECTORCALL";
    case VectorCallAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
