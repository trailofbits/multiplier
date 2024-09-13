// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class NullabilityKind : unsigned char {
  NON_NULL,
  NULLABLE,
  UNSPECIFIED,
  NULLABLE_RESULT,
};

inline static const char *EnumerationName(NullabilityKind) {
  return "NullabilityKind";
}

inline static constexpr unsigned NumEnumerators(NullabilityKind) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(NullabilityKind);

} // namespace mx
