// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCReturnsInnerPointerAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCReturnsInnerPointerAttrSpelling e) {
  switch (e) {
    case ObjCReturnsInnerPointerAttrSpelling::GNU_OBJC_RETURNS_INNER_POINTER: return "GNU_OBJC_RETURNS_INNER_POINTER";
    case ObjCReturnsInnerPointerAttrSpelling::CXX11_CLANG_OBJC_RETURNS_INNER_POINTER: return "CXX11_CLANG_OBJC_RETURNS_INNER_POINTER";
    case ObjCReturnsInnerPointerAttrSpelling::C23_CLANG_OBJC_RETURNS_INNER_POINTER: return "C23_CLANG_OBJC_RETURNS_INNER_POINTER";
    case ObjCReturnsInnerPointerAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
