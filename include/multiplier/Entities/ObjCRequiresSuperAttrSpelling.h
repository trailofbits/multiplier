// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ObjCRequiresSuperAttrSpelling : unsigned char {
  GNU_OBJC_REQUIRES_SUPER,
  CXX11_CLANG_OBJC_REQUIRES_SUPER,
  C23_CLANG_OBJC_REQUIRES_SUPER,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCRequiresSuperAttrSpelling) {
  return "ObjCRequiresSuperAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCRequiresSuperAttrSpelling) {
  return 4;
}

const char *EnumeratorName(ObjCRequiresSuperAttrSpelling);

} // namespace mx
