// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/WarnUnusedAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(WarnUnusedAttrSpelling e) {
  switch (e) {
    case WarnUnusedAttrSpelling::GNU_WARN_UNUSED: return "GNU_WARN_UNUSED";
    case WarnUnusedAttrSpelling::CXX11_GNU_WARN_UNUSED: return "CXX11_GNU_WARN_UNUSED";
    case WarnUnusedAttrSpelling::C23_GNU_WARN_UNUSED: return "C23_GNU_WARN_UNUSED";
    case WarnUnusedAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
