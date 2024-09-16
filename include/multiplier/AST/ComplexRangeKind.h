// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ComplexRangeKind : unsigned char {
  CX_FULL,
  CX_LIMITED,
  CX_FORTRAN,
  CX_NONE,
};

inline static const char *EnumerationName(ComplexRangeKind) {
  return "ComplexRangeKind";
}

inline static constexpr unsigned NumEnumerators(ComplexRangeKind) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ComplexRangeKind);

} // namespace mx
