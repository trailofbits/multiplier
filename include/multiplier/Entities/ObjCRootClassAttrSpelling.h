// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ObjCRootClassAttrSpelling : unsigned char {
  GNU_OBJC_ROOT_CLASS,
  CXX11_CLANG_OBJC_ROOT_CLASS,
  C2X_CLANG_OBJC_ROOT_CLASS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCRootClassAttrSpelling) {
  return "ObjCRootClassAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCRootClassAttrSpelling) {
  return 4;
}

const char *EnumeratorName(ObjCRootClassAttrSpelling);

} // namespace mx
