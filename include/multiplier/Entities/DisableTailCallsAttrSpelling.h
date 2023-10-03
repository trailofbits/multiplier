// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class DisableTailCallsAttrSpelling : unsigned char {
  GNU_DISABLE_TAIL_CALLS,
  CXX11_CLANG_DISABLE_TAIL_CALLS,
  C23_CLANG_DISABLE_TAIL_CALLS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(DisableTailCallsAttrSpelling) {
  return "DisableTailCallsAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(DisableTailCallsAttrSpelling) {
  return 4;
}

const char *EnumeratorName(DisableTailCallsAttrSpelling);

} // namespace mx
