// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ObjCDirectAttrSpelling : unsigned char {
  GNU_OBJC_DIRECT,
  CXX11_CLANG_OBJC_DIRECT,
  C23_CLANG_OBJC_DIRECT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCDirectAttrSpelling) {
  return "ObjCDirectAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCDirectAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ObjCDirectAttrSpelling);

} // namespace mx
