// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCPreciseLifetimeAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCPreciseLifetimeAttrSpelling e) {
  switch (e) {
    case ObjCPreciseLifetimeAttrSpelling::GNU_OBJC_PRECISE_LIFETIME: return "GNU_OBJC_PRECISE_LIFETIME";
    case ObjCPreciseLifetimeAttrSpelling::CXX11_CLANG_OBJC_PRECISE_LIFETIME: return "CXX11_CLANG_OBJC_PRECISE_LIFETIME";
    case ObjCPreciseLifetimeAttrSpelling::C23_CLANG_OBJC_PRECISE_LIFETIME: return "C23_CLANG_OBJC_PRECISE_LIFETIME";
    case ObjCPreciseLifetimeAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
