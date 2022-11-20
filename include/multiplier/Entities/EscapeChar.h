// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class EscapeChar : unsigned char {
  SINGLE,
  DOUBLE,
  SINGLE_AND_DOUBLE,
};

inline static const char *EnumerationName(EscapeChar) {
  return "EscapeChar";
}

inline static constexpr unsigned NumEnumerators(EscapeChar) {
  return 3;
}

const char *EnumeratorName(EscapeChar);

} // namespace mx