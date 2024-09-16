// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ExtendArgsKind : unsigned char {
  EXTEND_TO32,
  EXTEND_TO64,
};

inline static const char *EnumerationName(ExtendArgsKind) {
  return "ExtendArgsKind";
}

inline static constexpr unsigned NumEnumerators(ExtendArgsKind) {
  return 2;
}

MX_EXPORT const char *EnumeratorName(ExtendArgsKind);

} // namespace mx
