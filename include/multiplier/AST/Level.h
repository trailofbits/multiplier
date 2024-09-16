// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class Level : unsigned char {
  IGNORED,
  NOTE,
  REMARK,
  WARNING,
  ERROR,
  FATAL,
};

inline static const char *EnumerationName(Level) {
  return "Level";
}

inline static constexpr unsigned NumEnumerators(Level) {
  return 6;
}

MX_EXPORT const char *EnumeratorName(Level);

} // namespace mx
