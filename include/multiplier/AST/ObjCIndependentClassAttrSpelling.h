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
enum class ObjCIndependentClassAttrSpelling : unsigned char {
  GNU_OBJC_INDEPENDENT_CLASS,
  CXX11_CLANG_OBJC_INDEPENDENT_CLASS,
  C23_CLANG_OBJC_INDEPENDENT_CLASS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCIndependentClassAttrSpelling) {
  return "ObjCIndependentClassAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCIndependentClassAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ObjCIndependentClassAttrSpelling);

} // namespace mx
