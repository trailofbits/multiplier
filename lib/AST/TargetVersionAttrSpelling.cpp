// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TargetVersionAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TargetVersionAttrSpelling e) {
  switch (e) {
    case TargetVersionAttrSpelling::GNU_TARGET_VERSION: return "GNU_TARGET_VERSION";
    case TargetVersionAttrSpelling::CXX11_GNU_TARGET_VERSION: return "CXX11_GNU_TARGET_VERSION";
    case TargetVersionAttrSpelling::C2X_GNU_TARGET_VERSION: return "C2X_GNU_TARGET_VERSION";
    case TargetVersionAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
