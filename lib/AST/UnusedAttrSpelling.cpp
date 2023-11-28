// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/UnusedAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(UnusedAttrSpelling e) {
  switch (e) {
    case UnusedAttrSpelling::CXX11_MAYBE_UNUSED: return "CXX11_MAYBE_UNUSED";
    case UnusedAttrSpelling::GNU_UNUSED: return "GNU_UNUSED";
    case UnusedAttrSpelling::CXX11_GNU_UNUSED: return "CXX11_GNU_UNUSED";
    case UnusedAttrSpelling::C2X_GNU_UNUSED: return "C2X_GNU_UNUSED";
    case UnusedAttrSpelling::C2X_MAYBE_UNUSED: return "C2X_MAYBE_UNUSED";
    case UnusedAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
