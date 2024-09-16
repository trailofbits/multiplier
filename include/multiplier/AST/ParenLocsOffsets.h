// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ParenLocsOffsets : unsigned char {
  L_PAREN_TOKEN,
  R_PAREN_TOKEN,
  TOTAL,
};

inline static const char *EnumerationName(ParenLocsOffsets) {
  return "ParenLocsOffsets";
}

inline static constexpr unsigned NumEnumerators(ParenLocsOffsets) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(ParenLocsOffsets);

} // namespace mx
