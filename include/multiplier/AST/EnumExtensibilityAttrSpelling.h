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
enum class EnumExtensibilityAttrSpelling : unsigned char {
  GNU_ENUM_EXTENSIBILITY,
  CXX11_CLANG_ENUM_EXTENSIBILITY,
  C2X_CLANG_ENUM_EXTENSIBILITY,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(EnumExtensibilityAttrSpelling) {
  return "EnumExtensibilityAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(EnumExtensibilityAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(EnumExtensibilityAttrSpelling);

} // namespace mx
