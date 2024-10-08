// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class NoThrowAttrSpelling : unsigned char {
  GNU_NOTHROW,
  CXX11_GNU_NOTHROW,
  C23_GNU_NOTHROW,
  DECLSPEC_NOTHROW,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NoThrowAttrSpelling) {
  return "NoThrowAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NoThrowAttrSpelling) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(NoThrowAttrSpelling);

} // namespace mx
