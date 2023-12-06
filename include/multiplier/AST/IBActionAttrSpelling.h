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
enum class IBActionAttrSpelling : unsigned char {
  GNU_IBACTION,
  CXX11_CLANG_IBACTION,
  C2X_CLANG_IBACTION,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(IBActionAttrSpelling) {
  return "IBActionAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(IBActionAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(IBActionAttrSpelling);

} // namespace mx
