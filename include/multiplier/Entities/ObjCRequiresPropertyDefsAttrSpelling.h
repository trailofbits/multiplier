// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ObjCRequiresPropertyDefsAttrSpelling : unsigned char {
  GNU_OBJC_REQUIRES_PROPERTY_DEFINITIONS,
  CXX11_CLANG_OBJC_REQUIRES_PROPERTY_DEFINITIONS,
  C2X_CLANG_OBJC_REQUIRES_PROPERTY_DEFINITIONS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCRequiresPropertyDefsAttrSpelling) {
  return "ObjCRequiresPropertyDefsAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCRequiresPropertyDefsAttrSpelling) {
  return 4;
}

const char *EnumeratorName(ObjCRequiresPropertyDefsAttrSpelling);

} // namespace mx
