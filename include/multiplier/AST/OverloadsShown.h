// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class OverloadsShown : unsigned char {
  ALL,
  BEST,
};

inline static const char *EnumerationName(OverloadsShown) {
  return "OverloadsShown";
}

inline static constexpr unsigned NumEnumerators(OverloadsShown) {
  return 2;
}

MX_EXPORT const char *EnumeratorName(OverloadsShown);

} // namespace mx
