// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ReturnsNonNullAttrSpelling : unsigned char {
  GNU_RETURNS_NONNULL,
  CXX11_GNU_RETURNS_NONNULL,
  C23_GNU_RETURNS_NONNULL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ReturnsNonNullAttrSpelling) {
  return "ReturnsNonNullAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ReturnsNonNullAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ReturnsNonNullAttrSpelling);

} // namespace mx
