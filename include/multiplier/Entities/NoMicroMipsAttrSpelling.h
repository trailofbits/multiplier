// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class NoMicroMipsAttrSpelling : unsigned char {
  GNU_NOMICROMIPS,
  CXX11_GNU_NOMICROMIPS,
  C2X_GNU_NOMICROMIPS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NoMicroMipsAttrSpelling) {
  return "NoMicroMipsAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NoMicroMipsAttrSpelling) {
  return 4;
}

const char *EnumeratorName(NoMicroMipsAttrSpelling);

} // namespace mx
