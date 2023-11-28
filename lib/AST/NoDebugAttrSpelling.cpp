// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/NoDebugAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NoDebugAttrSpelling e) {
  switch (e) {
    case NoDebugAttrSpelling::GNU_NODEBUG: return "GNU_NODEBUG";
    case NoDebugAttrSpelling::CXX11_GNU_NODEBUG: return "CXX11_GNU_NODEBUG";
    case NoDebugAttrSpelling::C2X_GNU_NODEBUG: return "C2X_GNU_NODEBUG";
    case NoDebugAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
