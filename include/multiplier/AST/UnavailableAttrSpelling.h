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
enum class UnavailableAttrSpelling : unsigned char {
  GNU_UNAVAILABLE,
  CXX11_CLANG_UNAVAILABLE,
  C23_CLANG_UNAVAILABLE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(UnavailableAttrSpelling) {
  return "UnavailableAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(UnavailableAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(UnavailableAttrSpelling);

} // namespace mx
