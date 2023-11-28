// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCNonLazyClassAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCNonLazyClassAttrSpelling e) {
  switch (e) {
    case ObjCNonLazyClassAttrSpelling::GNU_OBJC_NONLAZY_CLASS: return "GNU_OBJC_NONLAZY_CLASS";
    case ObjCNonLazyClassAttrSpelling::CXX11_CLANG_OBJC_NONLAZY_CLASS: return "CXX11_CLANG_OBJC_NONLAZY_CLASS";
    case ObjCNonLazyClassAttrSpelling::C2X_CLANG_OBJC_NONLAZY_CLASS: return "C2X_CLANG_OBJC_NONLAZY_CLASS";
    case ObjCNonLazyClassAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
