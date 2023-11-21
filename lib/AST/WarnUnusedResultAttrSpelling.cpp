// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/WarnUnusedResultAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(WarnUnusedResultAttrSpelling e) {
  switch (e) {
    case WarnUnusedResultAttrSpelling::CXX11_NODISCARD: return "CXX11_NODISCARD";
    case WarnUnusedResultAttrSpelling::C2X_NODISCARD: return "C2X_NODISCARD";
    case WarnUnusedResultAttrSpelling::CXX11_CLANG_WARN_UNUSED_RESULT: return "CXX11_CLANG_WARN_UNUSED_RESULT";
    case WarnUnusedResultAttrSpelling::GNU_WARN_UNUSED_RESULT: return "GNU_WARN_UNUSED_RESULT";
    case WarnUnusedResultAttrSpelling::CXX11_GNU_WARN_UNUSED_RESULT: return "CXX11_GNU_WARN_UNUSED_RESULT";
    case WarnUnusedResultAttrSpelling::C2X_GNU_WARN_UNUSED_RESULT: return "C2X_GNU_WARN_UNUSED_RESULT";
    case WarnUnusedResultAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
