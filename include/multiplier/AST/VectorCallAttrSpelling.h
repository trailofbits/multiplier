// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class VectorCallAttrSpelling : unsigned char {
  GNU_VECTORCALL,
  CXX11_CLANG_VECTORCALL,
  C23_CLANG_VECTORCALL,
  KEYWORD_VECTORCALL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(VectorCallAttrSpelling) {
  return "VectorCallAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(VectorCallAttrSpelling) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(VectorCallAttrSpelling);

} // namespace mx
