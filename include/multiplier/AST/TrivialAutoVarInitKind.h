// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class TrivialAutoVarInitKind : unsigned char {
  UNINITIALIZED,
  ZERO,
  PATTERN,
};

inline static const char *EnumerationName(TrivialAutoVarInitKind) {
  return "TrivialAutoVarInitKind";
}

inline static constexpr unsigned NumEnumerators(TrivialAutoVarInitKind) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(TrivialAutoVarInitKind);

} // namespace mx
