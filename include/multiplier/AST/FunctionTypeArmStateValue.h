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
enum class FunctionTypeArmStateValue : unsigned char {
  ARM_NONE,
  ARM_PRESERVES,
  ARM_IN,
  ARM_OUT,
  ARM_IN_OUT,
};

inline static const char *EnumerationName(FunctionTypeArmStateValue) {
  return "FunctionTypeArmStateValue";
}

inline static constexpr unsigned NumEnumerators(FunctionTypeArmStateValue) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(FunctionTypeArmStateValue);

} // namespace mx
