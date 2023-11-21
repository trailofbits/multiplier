// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/FormatAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(FormatAttrSpelling e) {
  switch (e) {
    case FormatAttrSpelling::GNU_FORMAT: return "GNU_FORMAT";
    case FormatAttrSpelling::CXX11_GNU_FORMAT: return "CXX11_GNU_FORMAT";
    case FormatAttrSpelling::C2X_GNU_FORMAT: return "C2X_GNU_FORMAT";
    case FormatAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
