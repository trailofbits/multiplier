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
enum class DeprecatedAttrSpelling : unsigned char {
  GNU_DEPRECATED,
  CXX11_GNU_DEPRECATED,
  C2X_GNU_DEPRECATED,
  DECLSPEC_DEPRECATED,
  CXX11_DEPRECATED,
  C2X_DEPRECATED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(DeprecatedAttrSpelling) {
  return "DeprecatedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(DeprecatedAttrSpelling) {
  return 7;
}

MX_EXPORT const char *EnumeratorName(DeprecatedAttrSpelling);

} // namespace mx
