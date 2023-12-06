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
enum class MethodRefFlags : unsigned char {
  METHOD_REFERENCE_NONE,
  METHOD_REFERENCE_GETTER,
  METHOD_REFERENCE_SETTER,
};

inline static const char *EnumerationName(MethodRefFlags) {
  return "MethodRefFlags";
}

inline static constexpr unsigned NumEnumerators(MethodRefFlags) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(MethodRefFlags);

} // namespace mx
