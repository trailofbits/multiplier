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
enum class AccessSpecifier : unsigned char {
  PUBLIC,
  PROTECTED,
  PRIVATE,
  NONE,
};

inline static const char *EnumerationName(AccessSpecifier) {
  return "AccessSpecifier";
}

inline static constexpr unsigned NumEnumerators(AccessSpecifier) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(AccessSpecifier);

} // namespace mx
