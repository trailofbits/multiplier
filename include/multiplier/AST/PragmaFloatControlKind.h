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
enum class PragmaFloatControlKind : unsigned char {
  UNKNOWN,
  PRECISE,
  NO_PRECISE,
  EXCEPT,
  NO_EXCEPT,
  PUSH,
  POP,
};

inline static const char *EnumerationName(PragmaFloatControlKind) {
  return "PragmaFloatControlKind";
}

inline static constexpr unsigned NumEnumerators(PragmaFloatControlKind) {
  return 7;
}

MX_EXPORT const char *EnumeratorName(PragmaFloatControlKind);

} // namespace mx
