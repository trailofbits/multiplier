// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCGCAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCGCAttrSpelling e) {
  switch (e) {
    case ObjCGCAttrSpelling::GNU_OBJC_GC: return "GNU_OBJC_GC";
    case ObjCGCAttrSpelling::CXX11_CLANG_OBJC_GC: return "CXX11_CLANG_OBJC_GC";
    case ObjCGCAttrSpelling::C23_CLANG_OBJC_GC: return "C23_CLANG_OBJC_GC";
    case ObjCGCAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
