// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class CDeclAttrSpelling : unsigned char {
  GNU_CDECL,
  CXX11_GNU_CDECL,
  C2X_GNU_CDECL,
  KEYWORD_CDECL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CDeclAttrSpelling) {
  return "CDeclAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CDeclAttrSpelling) {
  return 5;
}

const char *EnumeratorName(CDeclAttrSpelling);

} // namespace mx
