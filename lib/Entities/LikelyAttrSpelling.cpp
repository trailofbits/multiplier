// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/LikelyAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(LikelyAttrSpelling e) {
  switch (e) {
    case LikelyAttrSpelling::CXX11_LIKELY: return "CXX11_LIKELY";
    case LikelyAttrSpelling::C2X_CLANG_LIKELY: return "C2X_CLANG_LIKELY";
    case LikelyAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
