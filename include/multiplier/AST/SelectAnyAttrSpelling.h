// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class SelectAnyAttrSpelling : unsigned char {
  DECLSPEC_SELECTANY,
  GNU_SELECTANY,
  CXX11_GNU_SELECTANY,
  C2X_GNU_SELECTANY,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(SelectAnyAttrSpelling) {
  return "SelectAnyAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(SelectAnyAttrSpelling) {
  return 5;
}

const char *EnumeratorName(SelectAnyAttrSpelling);

} // namespace mx
