// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class AvailabilityAttrSpelling : unsigned char {
  GNU_AVAILABILITY,
  CXX11_CLANG_AVAILABILITY,
  C23_CLANG_AVAILABILITY,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AvailabilityAttrSpelling) {
  return "AvailabilityAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AvailabilityAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(AvailabilityAttrSpelling);

} // namespace mx
