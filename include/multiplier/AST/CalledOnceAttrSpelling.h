// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class CalledOnceAttrSpelling : unsigned char {
  GNU_CALLED_ONCE,
  CXX11_CLANG_CALLED_ONCE,
  C23_CLANG_CALLED_ONCE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CalledOnceAttrSpelling) {
  return "CalledOnceAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CalledOnceAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(CalledOnceAttrSpelling);

} // namespace mx
