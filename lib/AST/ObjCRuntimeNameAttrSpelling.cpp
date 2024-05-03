// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCRuntimeNameAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCRuntimeNameAttrSpelling e) {
  switch (e) {
    case ObjCRuntimeNameAttrSpelling::GNU_OBJC_RUNTIME_NAME: return "GNU_OBJC_RUNTIME_NAME";
    case ObjCRuntimeNameAttrSpelling::CXX11_CLANG_OBJC_RUNTIME_NAME: return "CXX11_CLANG_OBJC_RUNTIME_NAME";
    case ObjCRuntimeNameAttrSpelling::C23_CLANG_OBJC_RUNTIME_NAME: return "C23_CLANG_OBJC_RUNTIME_NAME";
    case ObjCRuntimeNameAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
