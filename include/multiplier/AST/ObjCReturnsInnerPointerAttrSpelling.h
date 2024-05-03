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
enum class ObjCReturnsInnerPointerAttrSpelling : unsigned char {
  GNU_OBJC_RETURNS_INNER_POINTER,
  CXX11_CLANG_OBJC_RETURNS_INNER_POINTER,
  C23_CLANG_OBJC_RETURNS_INNER_POINTER,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCReturnsInnerPointerAttrSpelling) {
  return "ObjCReturnsInnerPointerAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCReturnsInnerPointerAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ObjCReturnsInnerPointerAttrSpelling);

} // namespace mx
