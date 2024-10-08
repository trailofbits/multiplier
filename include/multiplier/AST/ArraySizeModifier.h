// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ArraySizeModifier : unsigned char {
  NORMAL,
  STATIC,
  STAR,
};

inline static const char *EnumerationName(ArraySizeModifier) {
  return "ArraySizeModifier";
}

inline static constexpr unsigned NumEnumerators(ArraySizeModifier) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(ArraySizeModifier);

} // namespace mx
