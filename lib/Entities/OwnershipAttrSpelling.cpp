// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OwnershipAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OwnershipAttrSpelling e) {
  switch (e) {
    case OwnershipAttrSpelling::GNU_OWNERSHIP_HOLDS: return "GNU_OWNERSHIP_HOLDS";
    case OwnershipAttrSpelling::CXX11_CLANG_OWNERSHIP_HOLDS: return "CXX11_CLANG_OWNERSHIP_HOLDS";
    case OwnershipAttrSpelling::C23_CLANG_OWNERSHIP_HOLDS: return "C23_CLANG_OWNERSHIP_HOLDS";
    case OwnershipAttrSpelling::GNU_OWNERSHIP_RETURNS: return "GNU_OWNERSHIP_RETURNS";
    case OwnershipAttrSpelling::CXX11_CLANG_OWNERSHIP_RETURNS: return "CXX11_CLANG_OWNERSHIP_RETURNS";
    case OwnershipAttrSpelling::C23_CLANG_OWNERSHIP_RETURNS: return "C23_CLANG_OWNERSHIP_RETURNS";
    case OwnershipAttrSpelling::GNU_OWNERSHIP_TAKES: return "GNU_OWNERSHIP_TAKES";
    case OwnershipAttrSpelling::CXX11_CLANG_OWNERSHIP_TAKES: return "CXX11_CLANG_OWNERSHIP_TAKES";
    case OwnershipAttrSpelling::C23_CLANG_OWNERSHIP_TAKES: return "C23_CLANG_OWNERSHIP_TAKES";
    case OwnershipAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
