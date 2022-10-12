// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ARMInterruptAttrSpelling : unsigned char {
  GNU_INTERRUPT,
  CXX11_GNU_INTERRUPT,
  C2X_GNU_INTERRUPT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ARMInterruptAttrSpelling) {
  return "ARMInterruptAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ARMInterruptAttrSpelling) {
  return 4;
}

const char *EnumeratorName(ARMInterruptAttrSpelling);

} // namespace mx
