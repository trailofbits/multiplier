// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class AllocSizeAttrSpelling : unsigned char {
  GNU_ALLOC_SIZE,
  CXX11_GNU_ALLOC_SIZE,
  C2X_GNU_ALLOC_SIZE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AllocSizeAttrSpelling) {
  return "AllocSizeAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AllocSizeAttrSpelling) {
  return 4;
}

const char *EnumeratorName(AllocSizeAttrSpelling);

} // namespace mx
