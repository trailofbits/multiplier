// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class SelectorLocationsKind : unsigned char {
  NON_STANDARD,
  STANDARD_NO_SPACE,
  STANDARD_WITH_SPACE,
};

inline static const char *EnumerationName(SelectorLocationsKind) {
  return "SelectorLocationsKind";
}

inline static constexpr unsigned NumEnumerators(SelectorLocationsKind) {
  return 3;
}

const char *EnumeratorName(SelectorLocationsKind);

} // namespace mx
