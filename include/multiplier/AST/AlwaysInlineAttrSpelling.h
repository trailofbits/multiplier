// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class AlwaysInlineAttrSpelling : unsigned char {
  GNU_ALWAYS_INLINE,
  CXX11_GNU_ALWAYS_INLINE,
  C2X_GNU_ALWAYS_INLINE,
  CXX11_CLANG_ALWAYS_INLINE,
  C2X_CLANG_ALWAYS_INLINE,
  KEYWORD_FORCEINLINE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AlwaysInlineAttrSpelling) {
  return "AlwaysInlineAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AlwaysInlineAttrSpelling) {
  return 7;
}

const char *EnumeratorName(AlwaysInlineAttrSpelling);

} // namespace mx
