// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class DefaultCallingConvention : unsigned char {
  NONE,
  C_DECL,
  FAST_CALL,
  STD_CALL,
  VECTOR_CALL,
  REG_CALL,
  RTD_CALL,
};

inline static const char *EnumerationName(DefaultCallingConvention) {
  return "DefaultCallingConvention";
}

inline static constexpr unsigned NumEnumerators(DefaultCallingConvention) {
  return 7;
}

MX_EXPORT const char *EnumeratorName(DefaultCallingConvention);

} // namespace mx
