// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ModeAttrSpelling : unsigned char {
  GNU_MODE,
  CXX11_GNU_MODE,
  C23_GNU_MODE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ModeAttrSpelling) {
  return "ModeAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ModeAttrSpelling) {
  return 4;
}

const char *EnumeratorName(ModeAttrSpelling);

} // namespace mx
