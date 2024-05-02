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
enum class PredefinedIdentKind : unsigned char {
  FUNC,
  FUNCTION,
  L_FUNCTION,
  FUNC_D_NAME,
  FUNC_SIG,
  L_FUNC_SIG,
  PRETTY_FUNCTION,
  PRETTY_FUNCTION_NO_VIRTUAL,
};

inline static const char *EnumerationName(PredefinedIdentKind) {
  return "PredefinedIdentKind";
}

inline static constexpr unsigned NumEnumerators(PredefinedIdentKind) {
  return 8;
}

MX_EXPORT const char *EnumeratorName(PredefinedIdentKind);

} // namespace mx
