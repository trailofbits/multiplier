// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class OpenMPMapModifierKind : unsigned char {
  UNKNOWN,
  ALWAYS,
  CLOSE,
  MAPPER,
  ITERATOR,
  PRESENT,
  OMPX_HOLD,
};

inline static const char *EnumerationName(OpenMPMapModifierKind) {
  return "OpenMPMapModifierKind";
}

inline static constexpr unsigned NumEnumerators(OpenMPMapModifierKind) {
  return 7;
}

const char *EnumeratorName(OpenMPMapModifierKind);

} // namespace mx
