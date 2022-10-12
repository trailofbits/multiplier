// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ObjCNonLazyClassAttrSpelling : unsigned char {
  GNU_OBJC_NONLAZY_CLASS,
  CXX11_CLANG_OBJC_NONLAZY_CLASS,
  C2X_CLANG_OBJC_NONLAZY_CLASS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCNonLazyClassAttrSpelling) {
  return "ObjCNonLazyClassAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCNonLazyClassAttrSpelling) {
  return 4;
}

const char *EnumeratorName(ObjCNonLazyClassAttrSpelling);

} // namespace mx
