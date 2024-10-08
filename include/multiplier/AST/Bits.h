// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class Bits : unsigned char {
  NONE,
  UNEXPANDED_PACK,
  INSTANTIATION,
  TYPE,
  VALUE,
  DEPENDENT,
  ERROR,
  VARIABLY_MODIFIED,
  SYNTACTIC,
  SEMANTIC,
};

inline static const char *EnumerationName(Bits) {
  return "Bits";
}

inline static constexpr unsigned NumEnumerators(Bits) {
  return 10;
}

MX_EXPORT const char *EnumeratorName(Bits);

} // namespace mx
