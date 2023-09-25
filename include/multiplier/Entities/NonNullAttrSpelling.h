// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class NonNullAttrSpelling : unsigned char {
  GNU_NONNULL,
  CXX11_GNU_NONNULL,
  C23_GNU_NONNULL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NonNullAttrSpelling) {
  return "NonNullAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NonNullAttrSpelling) {
  return 4;
}

const char *EnumeratorName(NonNullAttrSpelling);

} // namespace mx
