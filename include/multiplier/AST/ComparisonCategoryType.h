// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ComparisonCategoryType : unsigned char {
  PARTIAL_ORDERING,
  WEAK_ORDERING,
  STRONG_ORDERING,
};

inline static const char *EnumerationName(ComparisonCategoryType) {
  return "ComparisonCategoryType";
}

inline static constexpr unsigned NumEnumerators(ComparisonCategoryType) {
  return 3;
}

const char *EnumeratorName(ComparisonCategoryType);

} // namespace mx
