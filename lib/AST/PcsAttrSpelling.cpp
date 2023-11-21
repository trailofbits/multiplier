// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/PcsAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(PcsAttrSpelling e) {
  switch (e) {
    case PcsAttrSpelling::GNU_PCS: return "GNU_PCS";
    case PcsAttrSpelling::CXX11_GNU_PCS: return "CXX11_GNU_PCS";
    case PcsAttrSpelling::C2X_GNU_PCS: return "C2X_GNU_PCS";
    case PcsAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
