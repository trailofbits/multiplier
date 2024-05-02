// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/MipsShortCallAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(MipsShortCallAttrSpelling e) {
  switch (e) {
    case MipsShortCallAttrSpelling::GNU_SHORT_CALL: return "GNU_SHORT_CALL";
    case MipsShortCallAttrSpelling::CXX11_GNU_SHORT_CALL: return "CXX11_GNU_SHORT_CALL";
    case MipsShortCallAttrSpelling::C23_GNU_SHORT_CALL: return "C23_GNU_SHORT_CALL";
    case MipsShortCallAttrSpelling::GNU_NEAR: return "GNU_NEAR";
    case MipsShortCallAttrSpelling::CXX11_GNU_NEAR: return "CXX11_GNU_NEAR";
    case MipsShortCallAttrSpelling::C23_GNU_NEAR: return "C23_GNU_NEAR";
    case MipsShortCallAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
