// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class CoroReturnTypeAttrSpelling : unsigned char {
  GNU_CORO_RETURN_TYPE,
  CXX11_CLANG_CORO_RETURN_TYPE,
  C23_CLANG_CORO_RETURN_TYPE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CoroReturnTypeAttrSpelling) {
  return "CoroReturnTypeAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CoroReturnTypeAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(CoroReturnTypeAttrSpelling);

} // namespace mx
