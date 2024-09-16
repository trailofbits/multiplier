// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class RandomizeLayoutAttrSpelling : unsigned char {
  GNU_RANDOMIZE_LAYOUT,
  CXX11_GNU_RANDOMIZE_LAYOUT,
  C23_GNU_RANDOMIZE_LAYOUT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(RandomizeLayoutAttrSpelling) {
  return "RandomizeLayoutAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(RandomizeLayoutAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(RandomizeLayoutAttrSpelling);

} // namespace mx
