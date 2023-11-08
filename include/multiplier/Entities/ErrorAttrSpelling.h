// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ErrorAttrSpelling : unsigned char {
  GNU_ERROR,
  CXX11_GNU_ERROR,
  C23_GNU_ERROR,
  GNU_WARNING,
  CXX11_GNU_WARNING,
  C23_GNU_WARNING,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ErrorAttrSpelling) {
  return "ErrorAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ErrorAttrSpelling) {
  return 7;
}

const char *EnumeratorName(ErrorAttrSpelling);

} // namespace mx
