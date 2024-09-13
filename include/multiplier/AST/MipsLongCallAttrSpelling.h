// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class MipsLongCallAttrSpelling : unsigned char {
  GNU_LONG_CALL,
  CXX11_GNU_LONG_CALL,
  C23_GNU_LONG_CALL,
  GNU_FAR,
  CXX11_GNU_FAR,
  C23_GNU_FAR,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(MipsLongCallAttrSpelling) {
  return "MipsLongCallAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(MipsLongCallAttrSpelling) {
  return 7;
}

MX_EXPORT const char *EnumeratorName(MipsLongCallAttrSpelling);

} // namespace mx
