// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/RISCVInterruptAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(RISCVInterruptAttrSpelling e) {
  switch (e) {
    case RISCVInterruptAttrSpelling::GNU_INTERRUPT: return "GNU_INTERRUPT";
    case RISCVInterruptAttrSpelling::CXX11_GNU_INTERRUPT: return "CXX11_GNU_INTERRUPT";
    case RISCVInterruptAttrSpelling::C2X_GNU_INTERRUPT: return "C2X_GNU_INTERRUPT";
    case RISCVInterruptAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
