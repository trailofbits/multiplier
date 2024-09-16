// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/PassObjectSizeAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(PassObjectSizeAttrSpelling e) {
  switch (e) {
    case PassObjectSizeAttrSpelling::GNU_PASS_OBJECT_SIZE: return "GNU_PASS_OBJECT_SIZE";
    case PassObjectSizeAttrSpelling::CXX11_CLANG_PASS_OBJECT_SIZE: return "CXX11_CLANG_PASS_OBJECT_SIZE";
    case PassObjectSizeAttrSpelling::C23_CLANG_PASS_OBJECT_SIZE: return "C23_CLANG_PASS_OBJECT_SIZE";
    case PassObjectSizeAttrSpelling::GNU_PASS_DYNAMIC_OBJECT_SIZE: return "GNU_PASS_DYNAMIC_OBJECT_SIZE";
    case PassObjectSizeAttrSpelling::CXX11_CLANG_PASS_DYNAMIC_OBJECT_SIZE: return "CXX11_CLANG_PASS_DYNAMIC_OBJECT_SIZE";
    case PassObjectSizeAttrSpelling::C23_CLANG_PASS_DYNAMIC_OBJECT_SIZE: return "C23_CLANG_PASS_DYNAMIC_OBJECT_SIZE";
    case PassObjectSizeAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
