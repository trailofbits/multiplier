// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class SectionAttrSpelling : unsigned char {
  GNU_SECTION,
  CXX11_GNU_SECTION,
  C2X_GNU_SECTION,
  DECLSPEC_ALLOCATE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(SectionAttrSpelling) {
  return "SectionAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(SectionAttrSpelling) {
  return 5;
}

const char *EnumeratorName(SectionAttrSpelling);

} // namespace mx
