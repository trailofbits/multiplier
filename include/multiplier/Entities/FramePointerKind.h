// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class FramePointerKind : unsigned char {
  NONE,
  NON_LEAF,
  ALL,
};

inline static const char *EnumerationName(FramePointerKind) {
  return "FramePointerKind";
}

inline static constexpr unsigned NumEnumerators(FramePointerKind) {
  return 3;
}

const char *EnumeratorName(FramePointerKind);

} // namespace mx
