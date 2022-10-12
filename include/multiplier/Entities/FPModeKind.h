// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class FPModeKind : unsigned char {
  OFF,
  ON,
  FAST,
  FAST_HONOR_PRAGMAS,
};

inline static const char *EnumerationName(FPModeKind) {
  return "FPModeKind";
}

inline static constexpr unsigned NumEnumerators(FPModeKind) {
  return 4;
}

const char *EnumeratorName(FPModeKind);

} // namespace mx
