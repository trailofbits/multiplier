// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class InliningMethod : unsigned char {
  NORMAL_INLINING,
  ONLY_HINT_INLINING,
  ONLY_ALWAYS_INLINING,
};

inline static const char *EnumerationName(InliningMethod) {
  return "InliningMethod";
}

inline static constexpr unsigned NumEnumerators(InliningMethod) {
  return 3;
}

const char *EnumeratorName(InliningMethod);

} // namespace mx
