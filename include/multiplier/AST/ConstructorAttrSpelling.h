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
enum class ConstructorAttrSpelling : unsigned char {
  GNU_CONSTRUCTOR,
  CXX11_GNU_CONSTRUCTOR,
  C2X_GNU_CONSTRUCTOR,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ConstructorAttrSpelling) {
  return "ConstructorAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ConstructorAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ConstructorAttrSpelling);

} // namespace mx
