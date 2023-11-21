// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class TailPaddingUseRules : unsigned char {
  ALWAYS_USE_TAIL_PADDING,
  USE_TAIL_PADDING_UNLESS_POD03,
  USE_TAIL_PADDING_UNLESS_POD11,
};

inline static const char *EnumerationName(TailPaddingUseRules) {
  return "TailPaddingUseRules";
}

inline static constexpr unsigned NumEnumerators(TailPaddingUseRules) {
  return 3;
}

const char *EnumeratorName(TailPaddingUseRules);

} // namespace mx
