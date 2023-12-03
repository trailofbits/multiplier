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
enum class UnusedAttrSpelling : unsigned char {
  CXX11_MAYBE_UNUSED,
  GNU_UNUSED,
  CXX11_GNU_UNUSED,
  C2X_GNU_UNUSED,
  C2X_MAYBE_UNUSED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(UnusedAttrSpelling) {
  return "UnusedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(UnusedAttrSpelling) {
  return 6;
}

MX_EXPORT const char *EnumeratorName(UnusedAttrSpelling);

} // namespace mx
