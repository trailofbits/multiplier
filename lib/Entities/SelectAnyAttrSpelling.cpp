// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/SelectAnyAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SelectAnyAttrSpelling e) {
  switch (e) {
    case SelectAnyAttrSpelling::DECLSPEC_SELECTANY: return "DECLSPEC_SELECTANY";
    case SelectAnyAttrSpelling::GNU_SELECTANY: return "GNU_SELECTANY";
    case SelectAnyAttrSpelling::CXX11_GNU_SELECTANY: return "CXX11_GNU_SELECTANY";
    case SelectAnyAttrSpelling::C23_GNU_SELECTANY: return "C23_GNU_SELECTANY";
    case SelectAnyAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
