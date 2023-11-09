// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class MinVectorWidthAttrSpelling : unsigned char {
  GNU_MIN_VECTOR_WIDTH,
  CXX11_CLANG_MIN_VECTOR_WIDTH,
  C2X_CLANG_MIN_VECTOR_WIDTH,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(MinVectorWidthAttrSpelling) {
  return "MinVectorWidthAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(MinVectorWidthAttrSpelling) {
  return 4;
}

const char *EnumeratorName(MinVectorWidthAttrSpelling);

} // namespace mx
