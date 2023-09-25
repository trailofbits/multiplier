// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class MicroMipsAttrSpelling : unsigned char {
  GNU_MICROMIPS,
  CXX11_GNU_MICROMIPS,
  C23_GNU_MICROMIPS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(MicroMipsAttrSpelling) {
  return "MicroMipsAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(MicroMipsAttrSpelling) {
  return 4;
}

const char *EnumeratorName(MicroMipsAttrSpelling);

} // namespace mx
