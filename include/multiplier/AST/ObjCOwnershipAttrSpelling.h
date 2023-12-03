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
enum class ObjCOwnershipAttrSpelling : unsigned char {
  GNU_OBJC_OWNERSHIP,
  CXX11_CLANG_OBJC_OWNERSHIP,
  C2X_CLANG_OBJC_OWNERSHIP,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCOwnershipAttrSpelling) {
  return "ObjCOwnershipAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCOwnershipAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ObjCOwnershipAttrSpelling);

} // namespace mx
