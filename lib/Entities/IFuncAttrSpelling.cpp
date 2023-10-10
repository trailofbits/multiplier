// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/IFuncAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(IFuncAttrSpelling e) {
  switch (e) {
    case IFuncAttrSpelling::GNU_IFUNC: return "GNU_IFUNC";
    case IFuncAttrSpelling::CXX11_GNU_IFUNC: return "CXX11_GNU_IFUNC";
    case IFuncAttrSpelling::C23_GNU_IFUNC: return "C23_GNU_IFUNC";
    case IFuncAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
