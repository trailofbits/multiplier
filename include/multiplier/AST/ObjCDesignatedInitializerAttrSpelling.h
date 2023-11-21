// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ObjCDesignatedInitializerAttrSpelling : unsigned char {
  GNU_OBJC_DESIGNATED_INITIALIZER,
  CXX11_CLANG_OBJC_DESIGNATED_INITIALIZER,
  C2X_CLANG_OBJC_DESIGNATED_INITIALIZER,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCDesignatedInitializerAttrSpelling) {
  return "ObjCDesignatedInitializerAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCDesignatedInitializerAttrSpelling) {
  return 4;
}

const char *EnumeratorName(ObjCDesignatedInitializerAttrSpelling);

} // namespace mx
