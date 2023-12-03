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
enum class IncludePathLocation : unsigned char {
  ABSOLUTE,
  SYSROOT_RELATIVE,
};

inline static const char *EnumerationName(IncludePathLocation) {
  return "IncludePathLocation";
}

inline static constexpr unsigned NumEnumerators(IncludePathLocation) {
  return 2;
}

MX_EXPORT const char *EnumeratorName(IncludePathLocation);

} // namespace mx
