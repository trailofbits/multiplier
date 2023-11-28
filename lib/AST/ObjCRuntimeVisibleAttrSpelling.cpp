// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCRuntimeVisibleAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCRuntimeVisibleAttrSpelling e) {
  switch (e) {
    case ObjCRuntimeVisibleAttrSpelling::GNU_OBJC_RUNTIME_VISIBLE: return "GNU_OBJC_RUNTIME_VISIBLE";
    case ObjCRuntimeVisibleAttrSpelling::CXX11_CLANG_OBJC_RUNTIME_VISIBLE: return "CXX11_CLANG_OBJC_RUNTIME_VISIBLE";
    case ObjCRuntimeVisibleAttrSpelling::C2X_CLANG_OBJC_RUNTIME_VISIBLE: return "C2X_CLANG_OBJC_RUNTIME_VISIBLE";
    case ObjCRuntimeVisibleAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
