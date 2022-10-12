// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class MipsShortCallAttrSpelling : unsigned char {
  GNU_SHORT_CALL,
  CXX11_GNU_SHORT_CALL,
  C2X_GNU_SHORT_CALL,
  GNU_NEAR,
  CXX11_GNU_NEAR,
  C2X_GNU_NEAR,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(MipsShortCallAttrSpelling) {
  return "MipsShortCallAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(MipsShortCallAttrSpelling) {
  return 7;
}

const char *EnumeratorName(MipsShortCallAttrSpelling);

} // namespace mx
