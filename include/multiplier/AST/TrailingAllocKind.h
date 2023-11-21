// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class TrailingAllocKind : unsigned char {
  TAK_INHERITS_CONSTRUCTOR,
  TAK_HAS_TAIL_EXPLICIT,
};

inline static const char *EnumerationName(TrailingAllocKind) {
  return "TrailingAllocKind";
}

inline static constexpr unsigned NumEnumerators(TrailingAllocKind) {
  return 2;
}

const char *EnumeratorName(TrailingAllocKind);

} // namespace mx
