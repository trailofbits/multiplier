// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/NoDerefAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NoDerefAttrSpelling e) {
  switch (e) {
    case NoDerefAttrSpelling::GNU_NODEREF: return "GNU_NODEREF";
    case NoDerefAttrSpelling::CXX11_CLANG_NODEREF: return "CXX11_CLANG_NODEREF";
    case NoDerefAttrSpelling::C23_CLANG_NODEREF: return "C23_CLANG_NODEREF";
    case NoDerefAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
