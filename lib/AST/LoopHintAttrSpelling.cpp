// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/LoopHintAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(LoopHintAttrSpelling e) {
  switch (e) {
    case LoopHintAttrSpelling::PRAGMA_CLANG_LOOP: return "PRAGMA_CLANG_LOOP";
    case LoopHintAttrSpelling::PRAGMA_UNROLL: return "PRAGMA_UNROLL";
    case LoopHintAttrSpelling::PRAGMA_NOUNROLL: return "PRAGMA_NOUNROLL";
    case LoopHintAttrSpelling::PRAGMA_UNROLL_AND_JAM: return "PRAGMA_UNROLL_AND_JAM";
    case LoopHintAttrSpelling::PRAGMA_NOUNROLL_AND_JAM: return "PRAGMA_NOUNROLL_AND_JAM";
    case LoopHintAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
