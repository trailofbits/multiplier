// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class StructReturnConventionKind : unsigned char {
  DEFAULT,
  ON_STACK,
  IN_REGS,
};

inline static const char *EnumerationName(StructReturnConventionKind) {
  return "StructReturnConventionKind";
}

inline static constexpr unsigned NumEnumerators(StructReturnConventionKind) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(StructReturnConventionKind);

} // namespace mx
