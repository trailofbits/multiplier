// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class GPUDefaultStreamKind : unsigned char {
  LEGACY,
  PER_THREAD,
};

inline static const char *EnumerationName(GPUDefaultStreamKind) {
  return "GPUDefaultStreamKind";
}

inline static constexpr unsigned NumEnumerators(GPUDefaultStreamKind) {
  return 2;
}

const char *EnumeratorName(GPUDefaultStreamKind);

} // namespace mx
