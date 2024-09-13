// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class CoroWrapperAttrSpelling : unsigned char {
  GNU_CORO_WRAPPER,
  CXX11_CLANG_CORO_WRAPPER,
  C23_CLANG_CORO_WRAPPER,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CoroWrapperAttrSpelling) {
  return "CoroWrapperAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CoroWrapperAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(CoroWrapperAttrSpelling);

} // namespace mx
