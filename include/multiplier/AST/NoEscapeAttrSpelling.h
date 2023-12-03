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
enum class NoEscapeAttrSpelling : unsigned char {
  GNU_NOESCAPE,
  CXX11_CLANG_NOESCAPE,
  C2X_CLANG_NOESCAPE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NoEscapeAttrSpelling) {
  return "NoEscapeAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NoEscapeAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(NoEscapeAttrSpelling);

} // namespace mx
