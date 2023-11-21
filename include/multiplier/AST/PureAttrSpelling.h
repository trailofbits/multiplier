// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class PureAttrSpelling : unsigned char {
  GNU_PURE,
  CXX11_GNU_PURE,
  C2X_GNU_PURE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(PureAttrSpelling) {
  return "PureAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(PureAttrSpelling) {
  return 4;
}

const char *EnumeratorName(PureAttrSpelling);

} // namespace mx
