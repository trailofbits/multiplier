// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class RetainAttrSpelling : unsigned char {
  GNU_RETAIN,
  CXX11_GNU_RETAIN,
  C2X_GNU_RETAIN,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(RetainAttrSpelling) {
  return "RetainAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(RetainAttrSpelling) {
  return 4;
}

const char *EnumeratorName(RetainAttrSpelling);

} // namespace mx
