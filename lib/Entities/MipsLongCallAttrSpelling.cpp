// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MipsLongCallAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(MipsLongCallAttrSpelling e) {
  switch (e) {
    case MipsLongCallAttrSpelling::GNU_LONG_CALL: return "GNU_LONG_CALL";
    case MipsLongCallAttrSpelling::CXX11_GNU_LONG_CALL: return "CXX11_GNU_LONG_CALL";
    case MipsLongCallAttrSpelling::C23_GNU_LONG_CALL: return "C23_GNU_LONG_CALL";
    case MipsLongCallAttrSpelling::GNU_FAR: return "GNU_FAR";
    case MipsLongCallAttrSpelling::CXX11_GNU_FAR: return "CXX11_GNU_FAR";
    case MipsLongCallAttrSpelling::C23_GNU_FAR: return "C23_GNU_FAR";
    case MipsLongCallAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
