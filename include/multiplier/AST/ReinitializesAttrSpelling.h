// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ReinitializesAttrSpelling : unsigned char {
  GNU_REINITIALIZES,
  CXX11_CLANG_REINITIALIZES,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ReinitializesAttrSpelling) {
  return "ReinitializesAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ReinitializesAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(ReinitializesAttrSpelling);

} // namespace mx
