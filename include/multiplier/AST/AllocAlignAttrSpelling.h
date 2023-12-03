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
enum class AllocAlignAttrSpelling : unsigned char {
  GNU_ALLOC_ALIGN,
  CXX11_GNU_ALLOC_ALIGN,
  C2X_GNU_ALLOC_ALIGN,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AllocAlignAttrSpelling) {
  return "AllocAlignAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AllocAlignAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(AllocAlignAttrSpelling);

} // namespace mx
