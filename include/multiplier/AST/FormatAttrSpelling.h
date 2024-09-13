// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class FormatAttrSpelling : unsigned char {
  GNU_FORMAT,
  CXX11_GNU_FORMAT,
  C23_GNU_FORMAT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(FormatAttrSpelling) {
  return "FormatAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(FormatAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(FormatAttrSpelling);

} // namespace mx
