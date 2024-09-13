// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class UninitializedAttrSpelling : unsigned char {
  GNU_UNINITIALIZED,
  CXX11_CLANG_UNINITIALIZED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(UninitializedAttrSpelling) {
  return "UninitializedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(UninitializedAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(UninitializedAttrSpelling);

} // namespace mx
