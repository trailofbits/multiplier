// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class NoMips16AttrSpelling : unsigned char {
  GNU_NOMIPS16,
  CXX11_GNU_NOMIPS16,
  C23_GNU_NOMIPS16,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NoMips16AttrSpelling) {
  return "NoMips16AttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NoMips16AttrSpelling) {
  return 4;
}

const char *EnumeratorName(NoMips16AttrSpelling);

} // namespace mx
