// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class SwiftAsyncFramePointerKind : unsigned char {
  AUTO,
  ALWAYS,
  NEVER,
  // Skipped repeat pasta::kDefault
};

inline static const char *EnumerationName(SwiftAsyncFramePointerKind) {
  return "SwiftAsyncFramePointerKind";
}

inline static constexpr unsigned NumEnumerators(SwiftAsyncFramePointerKind) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(SwiftAsyncFramePointerKind);

} // namespace mx
