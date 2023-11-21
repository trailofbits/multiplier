// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class AlignedAttrSpelling : unsigned char {
  GNU_ALIGNED,
  CXX11_GNU_ALIGNED,
  C2X_GNU_ALIGNED,
  DECLSPEC_ALIGN,
  KEYWORD_ALIGNAS,
  KEYWORD__ALIGNAS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AlignedAttrSpelling) {
  return "AlignedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AlignedAttrSpelling) {
  return 7;
}

const char *EnumeratorName(AlignedAttrSpelling);

} // namespace mx
