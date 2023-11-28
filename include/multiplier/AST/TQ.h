// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class TQ : unsigned char {
  CONST,
  RESTRICT,
  VOLATILE,
  CVR_MASK,
};

inline static const char *EnumerationName(TQ) {
  return "TQ";
}

inline static constexpr unsigned NumEnumerators(TQ) {
  return 4;
}

const char *EnumeratorName(TQ);

} // namespace mx