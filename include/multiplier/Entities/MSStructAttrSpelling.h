// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class MSStructAttrSpelling : unsigned char {
  GNU_MS_STRUCT,
  CXX11_GNU_MS_STRUCT,
  C23_GNU_MS_STRUCT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(MSStructAttrSpelling) {
  return "MSStructAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(MSStructAttrSpelling) {
  return 4;
}

const char *EnumeratorName(MSStructAttrSpelling);

} // namespace mx
