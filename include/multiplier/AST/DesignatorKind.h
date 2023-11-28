// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class DesignatorKind : unsigned char {
  FIELD_DESIGNATOR,
  ARRAY_DESIGNATOR,
  ARRAY_RANGE_DESIGNATOR,
};

inline static const char *EnumerationName(DesignatorKind) {
  return "DesignatorKind";
}

inline static constexpr unsigned NumEnumerators(DesignatorKind) {
  return 3;
}

const char *EnumeratorName(DesignatorKind);

} // namespace mx
