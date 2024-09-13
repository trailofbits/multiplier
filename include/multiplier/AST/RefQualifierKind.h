// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class RefQualifierKind : unsigned char {
  NONE,
  L_VALUE,
  R_VALUE,
};

inline static const char *EnumerationName(RefQualifierKind) {
  return "RefQualifierKind";
}

inline static constexpr unsigned NumEnumerators(RefQualifierKind) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(RefQualifierKind);

} // namespace mx
