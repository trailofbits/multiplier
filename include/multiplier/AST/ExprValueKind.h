// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ExprValueKind : unsigned char {
  PR_VALUE,
  L_VALUE,
  X_VALUE,
};

inline static const char *EnumerationName(ExprValueKind) {
  return "ExprValueKind";
}

inline static constexpr unsigned NumEnumerators(ExprValueKind) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(ExprValueKind);

} // namespace mx
