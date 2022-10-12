// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class CapturedRegionKind : unsigned char {
  DEFAULT,
  OBJ_C_AT_FINALLY,
  OPEN_MP,
};

inline static const char *EnumerationName(CapturedRegionKind) {
  return "CapturedRegionKind";
}

inline static constexpr unsigned NumEnumerators(CapturedRegionKind) {
  return 3;
}

const char *EnumeratorName(CapturedRegionKind);

} // namespace mx
