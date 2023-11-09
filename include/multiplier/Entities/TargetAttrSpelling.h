// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class TargetAttrSpelling : unsigned char {
  GNU_TARGET,
  CXX11_GNU_TARGET,
  C2X_GNU_TARGET,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(TargetAttrSpelling) {
  return "TargetAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(TargetAttrSpelling) {
  return 4;
}

const char *EnumeratorName(TargetAttrSpelling);

} // namespace mx
