// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class DestructorAttrSpelling : unsigned char {
  GNU_DESTRUCTOR,
  CXX11_GNU_DESTRUCTOR,
  C2X_GNU_DESTRUCTOR,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(DestructorAttrSpelling) {
  return "DestructorAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(DestructorAttrSpelling) {
  return 4;
}

const char *EnumeratorName(DestructorAttrSpelling);

} // namespace mx