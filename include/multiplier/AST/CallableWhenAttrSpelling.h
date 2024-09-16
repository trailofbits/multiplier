// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class CallableWhenAttrSpelling : unsigned char {
  GNU_CALLABLE_WHEN,
  CXX11_CLANG_CALLABLE_WHEN,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CallableWhenAttrSpelling) {
  return "CallableWhenAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CallableWhenAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(CallableWhenAttrSpelling);

} // namespace mx
