// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class WeakAttrSpelling : unsigned char {
  GNU_WEAK,
  CXX11_GNU_WEAK,
  C23_GNU_WEAK,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(WeakAttrSpelling) {
  return "WeakAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(WeakAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(WeakAttrSpelling);

} // namespace mx
