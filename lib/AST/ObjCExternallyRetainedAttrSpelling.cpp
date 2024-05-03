// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCExternallyRetainedAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCExternallyRetainedAttrSpelling e) {
  switch (e) {
    case ObjCExternallyRetainedAttrSpelling::GNU_OBJC_EXTERNALLY_RETAINED: return "GNU_OBJC_EXTERNALLY_RETAINED";
    case ObjCExternallyRetainedAttrSpelling::CXX11_CLANG_OBJC_EXTERNALLY_RETAINED: return "CXX11_CLANG_OBJC_EXTERNALLY_RETAINED";
    case ObjCExternallyRetainedAttrSpelling::C23_CLANG_OBJC_EXTERNALLY_RETAINED: return "C23_CLANG_OBJC_EXTERNALLY_RETAINED";
    case ObjCExternallyRetainedAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
