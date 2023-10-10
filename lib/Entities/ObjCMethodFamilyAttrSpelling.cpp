// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCMethodFamilyAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCMethodFamilyAttrSpelling e) {
  switch (e) {
    case ObjCMethodFamilyAttrSpelling::GNU_OBJC_METHOD_FAMILY: return "GNU_OBJC_METHOD_FAMILY";
    case ObjCMethodFamilyAttrSpelling::CXX11_CLANG_OBJC_METHOD_FAMILY: return "CXX11_CLANG_OBJC_METHOD_FAMILY";
    case ObjCMethodFamilyAttrSpelling::C23_CLANG_OBJC_METHOD_FAMILY: return "C23_CLANG_OBJC_METHOD_FAMILY";
    case ObjCMethodFamilyAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
