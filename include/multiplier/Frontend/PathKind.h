// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class PathKind : unsigned char {
  UNIX,
  WINDOWS,
};

inline static const char *EnumerationName(PathKind) {
  return "PathKind";
}

inline static constexpr unsigned NumEnumerators(PathKind) {
  return 2;
}

MX_EXPORT const char *EnumeratorName(PathKind);

} // namespace mx
