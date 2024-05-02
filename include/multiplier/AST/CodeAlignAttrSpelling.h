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
enum class CodeAlignAttrSpelling : unsigned char {
  GNU_CODE_ALIGN,
  CXX11_CLANG_CODE_ALIGN,
  C23_CLANG_CODE_ALIGN,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CodeAlignAttrSpelling) {
  return "CodeAlignAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CodeAlignAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(CodeAlignAttrSpelling);

} // namespace mx
