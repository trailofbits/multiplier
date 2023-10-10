// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/LoopHintAttrLoopHintState.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(LoopHintAttrLoopHintState e) {
  switch (e) {
    case LoopHintAttrLoopHintState::ENABLE: return "ENABLE";
    case LoopHintAttrLoopHintState::DISABLE: return "DISABLE";
    case LoopHintAttrLoopHintState::NUMERIC: return "NUMERIC";
    case LoopHintAttrLoopHintState::FIXED_WIDTH: return "FIXED_WIDTH";
    case LoopHintAttrLoopHintState::SCALABLE_WIDTH: return "SCALABLE_WIDTH";
    case LoopHintAttrLoopHintState::ASSUME_SAFETY: return "ASSUME_SAFETY";
    case LoopHintAttrLoopHintState::FULL: return "FULL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
