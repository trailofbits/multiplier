// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class FastCallAttrSpelling : unsigned char {
  GNU_FASTCALL,
  CXX11_GNU_FASTCALL,
  C23_GNU_FASTCALL,
  KEYWORD_FASTCALL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(FastCallAttrSpelling) {
  return "FastCallAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(FastCallAttrSpelling) {
  return 5;
}

const char *EnumeratorName(FastCallAttrSpelling);

} // namespace mx
