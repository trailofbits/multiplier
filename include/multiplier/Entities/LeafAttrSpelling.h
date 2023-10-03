// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class LeafAttrSpelling : unsigned char {
  GNU_LEAF,
  CXX11_GNU_LEAF,
  C23_GNU_LEAF,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(LeafAttrSpelling) {
  return "LeafAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(LeafAttrSpelling) {
  return 4;
}

const char *EnumeratorName(LeafAttrSpelling);

} // namespace mx
