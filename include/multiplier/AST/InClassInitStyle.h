// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class InClassInitStyle : unsigned char {
  NO_INITIALIZER,
  COPY_INITIALIZER,
  LIST_INITIALIZER,
};

inline static const char *EnumerationName(InClassInitStyle) {
  return "InClassInitStyle";
}

inline static constexpr unsigned NumEnumerators(InClassInitStyle) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(InClassInitStyle);

} // namespace mx
