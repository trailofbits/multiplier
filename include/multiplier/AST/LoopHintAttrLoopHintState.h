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
enum class LoopHintAttrLoopHintState : unsigned char {
  ENABLE,
  DISABLE,
  NUMERIC,
  FIXED_WIDTH,
  SCALABLE_WIDTH,
  ASSUME_SAFETY,
  FULL,
};

inline static const char *EnumerationName(LoopHintAttrLoopHintState) {
  return "LoopHintAttrLoopHintState";
}

inline static constexpr unsigned NumEnumerators(LoopHintAttrLoopHintState) {
  return 7;
}

MX_EXPORT const char *EnumeratorName(LoopHintAttrLoopHintState);

} // namespace mx
