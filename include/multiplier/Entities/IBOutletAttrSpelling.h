// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class IBOutletAttrSpelling : unsigned char {
  GNU_IBOUTLET,
  CXX11_CLANG_IBOUTLET,
  C2X_CLANG_IBOUTLET,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(IBOutletAttrSpelling) {
  return "IBOutletAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(IBOutletAttrSpelling) {
  return 4;
}

const char *EnumeratorName(IBOutletAttrSpelling);

} // namespace mx
