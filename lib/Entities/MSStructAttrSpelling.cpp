// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MSStructAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(MSStructAttrSpelling e) {
  switch (e) {
    case MSStructAttrSpelling::GNU_MS_STRUCT: return "GNU_MS_STRUCT";
    case MSStructAttrSpelling::CXX11_GNU_MS_STRUCT: return "CXX11_GNU_MS_STRUCT";
    case MSStructAttrSpelling::C23_GNU_MS_STRUCT: return "C23_GNU_MS_STRUCT";
    case MSStructAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
