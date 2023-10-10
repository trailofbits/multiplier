// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CFGuardAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CFGuardAttrSpelling e) {
  switch (e) {
    case CFGuardAttrSpelling::DECLSPEC_GUARD: return "DECLSPEC_GUARD";
    case CFGuardAttrSpelling::GNU_GUARD: return "GNU_GUARD";
    case CFGuardAttrSpelling::CXX11_CLANG_GUARD: return "CXX11_CLANG_GUARD";
    case CFGuardAttrSpelling::C23_CLANG_GUARD: return "C23_CLANG_GUARD";
    case CFGuardAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
