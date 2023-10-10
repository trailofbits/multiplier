// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/LoopHintAttrOptionType.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(LoopHintAttrOptionType e) {
  switch (e) {
    case LoopHintAttrOptionType::VECTORIZE: return "VECTORIZE";
    case LoopHintAttrOptionType::VECTORIZE_WIDTH: return "VECTORIZE_WIDTH";
    case LoopHintAttrOptionType::INTERLEAVE: return "INTERLEAVE";
    case LoopHintAttrOptionType::INTERLEAVE_COUNT: return "INTERLEAVE_COUNT";
    case LoopHintAttrOptionType::UNROLL: return "UNROLL";
    case LoopHintAttrOptionType::UNROLL_COUNT: return "UNROLL_COUNT";
    case LoopHintAttrOptionType::UNROLL_AND_JAM: return "UNROLL_AND_JAM";
    case LoopHintAttrOptionType::UNROLL_AND_JAM_COUNT: return "UNROLL_AND_JAM_COUNT";
    case LoopHintAttrOptionType::PIPELINE_DISABLED: return "PIPELINE_DISABLED";
    case LoopHintAttrOptionType::PIPELINE_INITIATION_INTERVAL: return "PIPELINE_INITIATION_INTERVAL";
    case LoopHintAttrOptionType::DISTRIBUTE: return "DISTRIBUTE";
    case LoopHintAttrOptionType::VECTORIZE_PREDICATE: return "VECTORIZE_PREDICATE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
