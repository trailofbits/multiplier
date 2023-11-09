// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class GNUInlineAttrSpelling : unsigned char {
  GNU_GNU_INLINE,
  CXX11_GNU_GNU_INLINE,
  C2X_GNU_GNU_INLINE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(GNUInlineAttrSpelling) {
  return "GNUInlineAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(GNUInlineAttrSpelling) {
  return 4;
}

const char *EnumeratorName(GNUInlineAttrSpelling);

} // namespace mx
