// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class LTOVisibilityPublicAttrSpelling : unsigned char {
  GNU_LTO_VISIBILITY_PUBLIC,
  CXX11_CLANG_LTO_VISIBILITY_PUBLIC,
  C23_CLANG_LTO_VISIBILITY_PUBLIC,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(LTOVisibilityPublicAttrSpelling) {
  return "LTOVisibilityPublicAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(LTOVisibilityPublicAttrSpelling) {
  return 4;
}

const char *EnumeratorName(LTOVisibilityPublicAttrSpelling);

} // namespace mx
