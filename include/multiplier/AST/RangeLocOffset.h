// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class RangeLocOffset : unsigned char {
  ASSIGN_TOKEN,
  SECOND_COLON_TOKEN,
  TOTAL,
};

inline static const char *EnumerationName(RangeLocOffset) {
  return "RangeLocOffset";
}

inline static constexpr unsigned NumEnumerators(RangeLocOffset) {
  return 3;
}

const char *EnumeratorName(RangeLocOffset);

} // namespace mx
