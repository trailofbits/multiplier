// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class NonOdrUseReason : unsigned char {
  NONE,
  UNEVALUATED,
  CONSTANT,
  DISCARDED,
};

inline static const char *EnumerationName(NonOdrUseReason) {
  return "NonOdrUseReason";
}

inline static constexpr unsigned NumEnumerators(NonOdrUseReason) {
  return 4;
}

const char *EnumeratorName(NonOdrUseReason);

} // namespace mx
