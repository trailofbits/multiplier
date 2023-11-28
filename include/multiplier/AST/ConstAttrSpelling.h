// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ConstAttrSpelling : unsigned char {
  GNU_CONST,
  CXX11_GNU_CONST,
  C2X_GNU_CONST,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ConstAttrSpelling) {
  return "ConstAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ConstAttrSpelling) {
  return 4;
}

const char *EnumeratorName(ConstAttrSpelling);

} // namespace mx
