// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/NoSanitizeAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NoSanitizeAttrSpelling e) {
  switch (e) {
    case NoSanitizeAttrSpelling::GNU_NO_SANITIZE: return "GNU_NO_SANITIZE";
    case NoSanitizeAttrSpelling::CXX11_CLANG_NO_SANITIZE: return "CXX11_CLANG_NO_SANITIZE";
    case NoSanitizeAttrSpelling::C2X_CLANG_NO_SANITIZE: return "C2X_CLANG_NO_SANITIZE";
    case NoSanitizeAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx