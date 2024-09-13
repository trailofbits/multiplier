// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCRequiresSuperAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCRequiresSuperAttrSpelling e) {
  switch (e) {
    case ObjCRequiresSuperAttrSpelling::GNU_OBJC_REQUIRES_SUPER: return "GNU_OBJC_REQUIRES_SUPER";
    case ObjCRequiresSuperAttrSpelling::CXX11_CLANG_OBJC_REQUIRES_SUPER: return "CXX11_CLANG_OBJC_REQUIRES_SUPER";
    case ObjCRequiresSuperAttrSpelling::C23_CLANG_OBJC_REQUIRES_SUPER: return "C23_CLANG_OBJC_REQUIRES_SUPER";
    case ObjCRequiresSuperAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
