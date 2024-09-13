// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ImplicitCastExprOnStack : unsigned char {
  ON_STACK,
};

inline static const char *EnumerationName(ImplicitCastExprOnStack) {
  return "ImplicitCastExprOnStack";
}

inline static constexpr unsigned NumEnumerators(ImplicitCastExprOnStack) {
  return 1;
}

MX_EXPORT const char *EnumeratorName(ImplicitCastExprOnStack);

} // namespace mx
