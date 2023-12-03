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
enum class ColdAttrSpelling : unsigned char {
  GNU_COLD,
  CXX11_GNU_COLD,
  C2X_GNU_COLD,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ColdAttrSpelling) {
  return "ColdAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ColdAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ColdAttrSpelling);

} // namespace mx
