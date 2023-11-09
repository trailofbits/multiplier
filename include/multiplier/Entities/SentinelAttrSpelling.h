// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class SentinelAttrSpelling : unsigned char {
  GNU_SENTINEL,
  CXX11_GNU_SENTINEL,
  C2X_GNU_SENTINEL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(SentinelAttrSpelling) {
  return "SentinelAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(SentinelAttrSpelling) {
  return 4;
}

const char *EnumeratorName(SentinelAttrSpelling);

} // namespace mx
