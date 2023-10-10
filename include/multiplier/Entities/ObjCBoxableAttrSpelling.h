// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ObjCBoxableAttrSpelling : unsigned char {
  GNU_OBJC_BOXABLE,
  CXX11_CLANG_OBJC_BOXABLE,
  C23_CLANG_OBJC_BOXABLE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCBoxableAttrSpelling) {
  return "ObjCBoxableAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCBoxableAttrSpelling) {
  return 4;
}

const char *EnumeratorName(ObjCBoxableAttrSpelling);

} // namespace mx
