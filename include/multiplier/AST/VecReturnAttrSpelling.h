// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class VecReturnAttrSpelling : unsigned char {
  GNU_VECRETURN,
  CXX11_CLANG_VECRETURN,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(VecReturnAttrSpelling) {
  return "VecReturnAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(VecReturnAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(VecReturnAttrSpelling);

} // namespace mx
