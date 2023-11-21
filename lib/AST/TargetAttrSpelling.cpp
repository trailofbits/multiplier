// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TargetAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TargetAttrSpelling e) {
  switch (e) {
    case TargetAttrSpelling::GNU_TARGET: return "GNU_TARGET";
    case TargetAttrSpelling::CXX11_GNU_TARGET: return "CXX11_GNU_TARGET";
    case TargetAttrSpelling::C2X_GNU_TARGET: return "C2X_GNU_TARGET";
    case TargetAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
