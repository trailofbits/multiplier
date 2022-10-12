// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class LoopHintAttrOptionType : unsigned char {
  VECTORIZE,
  VECTORIZE_WIDTH,
  INTERLEAVE,
  INTERLEAVE_COUNT,
  UNROLL,
  UNROLL_COUNT,
  UNROLL_AND_JAM,
  UNROLL_AND_JAM_COUNT,
  PIPELINE_DISABLED,
  PIPELINE_INITIATION_INTERVAL,
  DISTRIBUTE,
  VECTORIZE_PREDICATE,
};

inline static const char *EnumerationName(LoopHintAttrOptionType) {
  return "LoopHintAttrOptionType";
}

inline static constexpr unsigned NumEnumerators(LoopHintAttrOptionType) {
  return 12;
}

const char *EnumeratorName(LoopHintAttrOptionType);

} // namespace mx
