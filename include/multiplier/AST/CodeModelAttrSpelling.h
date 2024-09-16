// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class CodeModelAttrSpelling : unsigned char {
  GNU_MODEL,
  CXX11_GNU_MODEL,
  C23_GNU_MODEL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CodeModelAttrSpelling) {
  return "CodeModelAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CodeModelAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(CodeModelAttrSpelling);

} // namespace mx
