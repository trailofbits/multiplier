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
enum class CoroDisableLifetimeBoundAttrSpelling : unsigned char {
  GNU_CORO_DISABLE_LIFETIMEBOUND,
  CXX11_CLANG_CORO_DISABLE_LIFETIMEBOUND,
  C23_CLANG_CORO_DISABLE_LIFETIMEBOUND,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CoroDisableLifetimeBoundAttrSpelling) {
  return "CoroDisableLifetimeBoundAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CoroDisableLifetimeBoundAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(CoroDisableLifetimeBoundAttrSpelling);

} // namespace mx
