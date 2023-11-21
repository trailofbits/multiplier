// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/LTOVisibilityPublicAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(LTOVisibilityPublicAttrSpelling e) {
  switch (e) {
    case LTOVisibilityPublicAttrSpelling::GNU_LTO_VISIBILITY_PUBLIC: return "GNU_LTO_VISIBILITY_PUBLIC";
    case LTOVisibilityPublicAttrSpelling::CXX11_CLANG_LTO_VISIBILITY_PUBLIC: return "CXX11_CLANG_LTO_VISIBILITY_PUBLIC";
    case LTOVisibilityPublicAttrSpelling::C2X_CLANG_LTO_VISIBILITY_PUBLIC: return "C2X_CLANG_LTO_VISIBILITY_PUBLIC";
    case LTOVisibilityPublicAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
