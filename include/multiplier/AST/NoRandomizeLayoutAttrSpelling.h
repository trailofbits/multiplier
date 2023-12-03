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
enum class NoRandomizeLayoutAttrSpelling : unsigned char {
  GNU_NO_RANDOMIZE_LAYOUT,
  CXX11_GNU_NO_RANDOMIZE_LAYOUT,
  C2X_GNU_NO_RANDOMIZE_LAYOUT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NoRandomizeLayoutAttrSpelling) {
  return "NoRandomizeLayoutAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NoRandomizeLayoutAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(NoRandomizeLayoutAttrSpelling);

} // namespace mx
