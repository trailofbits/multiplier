// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ExcessPrecisionKind : unsigned char {
  FPP_STANDARD,
  FPP_FAST,
  FPP_NONE,
};

inline static const char *EnumerationName(ExcessPrecisionKind) {
  return "ExcessPrecisionKind";
}

inline static constexpr unsigned NumEnumerators(ExcessPrecisionKind) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(ExcessPrecisionKind);

} // namespace mx
