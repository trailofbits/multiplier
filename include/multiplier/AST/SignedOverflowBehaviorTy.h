// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class SignedOverflowBehaviorTy : unsigned char {
  UNDEFINED,
  DEFINED,
  TRAPPING,
};

inline static const char *EnumerationName(SignedOverflowBehaviorTy) {
  return "SignedOverflowBehaviorTy";
}

inline static constexpr unsigned NumEnumerators(SignedOverflowBehaviorTy) {
  return 3;
}

const char *EnumeratorName(SignedOverflowBehaviorTy);

} // namespace mx
