// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class NoInlineAttrSpelling : unsigned char {
  KEYWORD_NOINLINE,
  GNU_NOINLINE,
  CXX11_GNU_NOINLINE,
  C23_GNU_NOINLINE,
  CXX11_CLANG_NOINLINE,
  C23_CLANG_NOINLINE,
  DECLSPEC_NOINLINE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NoInlineAttrSpelling) {
  return "NoInlineAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NoInlineAttrSpelling) {
  return 8;
}

MX_EXPORT const char *EnumeratorName(NoInlineAttrSpelling);

} // namespace mx
