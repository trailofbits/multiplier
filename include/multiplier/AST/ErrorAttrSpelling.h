// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ErrorAttrSpelling : unsigned char {
  GNU_ERROR,
  CXX11_GNU_ERROR,
  C2X_GNU_ERROR,
  GNU_WARNING,
  CXX11_GNU_WARNING,
  C2X_GNU_WARNING,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ErrorAttrSpelling) {
  return "ErrorAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ErrorAttrSpelling) {
  return 7;
}

MX_EXPORT const char *EnumeratorName(ErrorAttrSpelling);

} // namespace mx
