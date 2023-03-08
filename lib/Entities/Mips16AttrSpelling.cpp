// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/Mips16AttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(Mips16AttrSpelling e) {
  switch (e) {
    case Mips16AttrSpelling::GNU_MIPS16: return "GNU_MIPS16";
    case Mips16AttrSpelling::CXX11_GNU_MIPS16: return "CXX11_GNU_MIPS16";
    case Mips16AttrSpelling::C2X_GNU_MIPS16: return "C2X_GNU_MIPS16";
    case Mips16AttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
