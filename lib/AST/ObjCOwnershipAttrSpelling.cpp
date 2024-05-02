// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCOwnershipAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCOwnershipAttrSpelling e) {
  switch (e) {
    case ObjCOwnershipAttrSpelling::GNU_OBJC_OWNERSHIP: return "GNU_OBJC_OWNERSHIP";
    case ObjCOwnershipAttrSpelling::CXX11_CLANG_OBJC_OWNERSHIP: return "CXX11_CLANG_OBJC_OWNERSHIP";
    case ObjCOwnershipAttrSpelling::C23_CLANG_OBJC_OWNERSHIP: return "C23_CLANG_OBJC_OWNERSHIP";
    case ObjCOwnershipAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
