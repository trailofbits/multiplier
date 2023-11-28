// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCBoxableAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCBoxableAttrSpelling e) {
  switch (e) {
    case ObjCBoxableAttrSpelling::GNU_OBJC_BOXABLE: return "GNU_OBJC_BOXABLE";
    case ObjCBoxableAttrSpelling::CXX11_CLANG_OBJC_BOXABLE: return "CXX11_CLANG_OBJC_BOXABLE";
    case ObjCBoxableAttrSpelling::C2X_CLANG_OBJC_BOXABLE: return "C2X_CLANG_OBJC_BOXABLE";
    case ObjCBoxableAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
