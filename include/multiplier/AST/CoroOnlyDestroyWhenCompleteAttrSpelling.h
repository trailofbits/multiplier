// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class CoroOnlyDestroyWhenCompleteAttrSpelling : unsigned char {
  GNU_CORO_ONLY_DESTROY_WHEN_COMPLETE,
  CXX11_CLANG_CORO_ONLY_DESTROY_WHEN_COMPLETE,
  C23_CLANG_CORO_ONLY_DESTROY_WHEN_COMPLETE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CoroOnlyDestroyWhenCompleteAttrSpelling) {
  return "CoroOnlyDestroyWhenCompleteAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CoroOnlyDestroyWhenCompleteAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(CoroOnlyDestroyWhenCompleteAttrSpelling);

} // namespace mx
