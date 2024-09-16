// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class NoSanitizeAttrSpelling : unsigned char {
  GNU_NO_SANITIZE,
  CXX11_CLANG_NO_SANITIZE,
  C23_CLANG_NO_SANITIZE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NoSanitizeAttrSpelling) {
  return "NoSanitizeAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NoSanitizeAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(NoSanitizeAttrSpelling);

} // namespace mx
