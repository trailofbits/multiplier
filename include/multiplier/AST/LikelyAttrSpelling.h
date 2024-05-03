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
enum class LikelyAttrSpelling : unsigned char {
  CXX11_LIKELY,
  C23_CLANG_LIKELY,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(LikelyAttrSpelling) {
  return "LikelyAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(LikelyAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(LikelyAttrSpelling);

} // namespace mx
