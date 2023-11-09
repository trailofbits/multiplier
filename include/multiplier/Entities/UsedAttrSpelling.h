// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class UsedAttrSpelling : unsigned char {
  GNU_USED,
  CXX11_GNU_USED,
  C2X_GNU_USED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(UsedAttrSpelling) {
  return "UsedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(UsedAttrSpelling) {
  return 4;
}

const char *EnumeratorName(UsedAttrSpelling);

} // namespace mx
