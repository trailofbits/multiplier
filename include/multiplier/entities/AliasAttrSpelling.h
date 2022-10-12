// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class AliasAttrSpelling : unsigned char {
  GNU_ALIAS,
  CXX11_GNU_ALIAS,
  C2X_GNU_ALIAS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AliasAttrSpelling) {
  return "AliasAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AliasAttrSpelling) {
  return 4;
}

const char *EnumeratorName(AliasAttrSpelling);

} // namespace mx
