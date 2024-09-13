// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCSubclassingRestrictedAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCSubclassingRestrictedAttrSpelling e) {
  switch (e) {
    case ObjCSubclassingRestrictedAttrSpelling::GNU_OBJC_SUBCLASSING_RESTRICTED: return "GNU_OBJC_SUBCLASSING_RESTRICTED";
    case ObjCSubclassingRestrictedAttrSpelling::CXX11_CLANG_OBJC_SUBCLASSING_RESTRICTED: return "CXX11_CLANG_OBJC_SUBCLASSING_RESTRICTED";
    case ObjCSubclassingRestrictedAttrSpelling::C23_CLANG_OBJC_SUBCLASSING_RESTRICTED: return "C23_CLANG_OBJC_SUBCLASSING_RESTRICTED";
    case ObjCSubclassingRestrictedAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
