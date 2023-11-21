// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AnyX86InterruptAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AnyX86InterruptAttrSpelling e) {
  switch (e) {
    case AnyX86InterruptAttrSpelling::GNU_INTERRUPT: return "GNU_INTERRUPT";
    case AnyX86InterruptAttrSpelling::CXX11_GNU_INTERRUPT: return "CXX11_GNU_INTERRUPT";
    case AnyX86InterruptAttrSpelling::C2X_GNU_INTERRUPT: return "C2X_GNU_INTERRUPT";
    case AnyX86InterruptAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
