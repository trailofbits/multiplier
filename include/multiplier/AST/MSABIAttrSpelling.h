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
enum class MSABIAttrSpelling : unsigned char {
  GNU_MS_ABI,
  CXX11_GNU_MS_ABI,
  C2X_GNU_MS_ABI,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(MSABIAttrSpelling) {
  return "MSABIAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(MSABIAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(MSABIAttrSpelling);

} // namespace mx
