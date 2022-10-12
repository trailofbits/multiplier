// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class PcsAttrSpelling : unsigned char {
  GNU_PCS,
  CXX11_GNU_PCS,
  C2X_GNU_PCS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(PcsAttrSpelling) {
  return "PcsAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(PcsAttrSpelling) {
  return 4;
}

const char *EnumeratorName(PcsAttrSpelling);

} // namespace mx
