// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ObjCSubclassingRestrictedAttrSpelling : unsigned char {
  GNU_OBJC_SUBCLASSING_RESTRICTED,
  CXX11_CLANG_OBJC_SUBCLASSING_RESTRICTED,
  C2X_CLANG_OBJC_SUBCLASSING_RESTRICTED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCSubclassingRestrictedAttrSpelling) {
  return "ObjCSubclassingRestrictedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCSubclassingRestrictedAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ObjCSubclassingRestrictedAttrSpelling);

} // namespace mx
