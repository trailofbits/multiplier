// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class MultiVersionKind : unsigned char {
  NONE,
  TARGET,
  CPU_SPECIFIC,
  CPU_DISPATCH,
  TARGET_CLONES,
  TARGET_VERSION,
};

inline static const char *EnumerationName(MultiVersionKind) {
  return "MultiVersionKind";
}

inline static constexpr unsigned NumEnumerators(MultiVersionKind) {
  return 6;
}

const char *EnumeratorName(MultiVersionKind);

} // namespace mx
