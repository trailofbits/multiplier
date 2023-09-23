// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class FlattenAttrSpelling : unsigned char {
  GNU_FLATTEN,
  CXX11_GNU_FLATTEN,
  C23_GNU_FLATTEN,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(FlattenAttrSpelling) {
  return "FlattenAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(FlattenAttrSpelling) {
  return 4;
}

const char *EnumeratorName(FlattenAttrSpelling);

} // namespace mx
