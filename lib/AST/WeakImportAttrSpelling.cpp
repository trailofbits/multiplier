// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/WeakImportAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(WeakImportAttrSpelling e) {
  switch (e) {
    case WeakImportAttrSpelling::GNU_WEAK_IMPORT: return "GNU_WEAK_IMPORT";
    case WeakImportAttrSpelling::CXX11_CLANG_WEAK_IMPORT: return "CXX11_CLANG_WEAK_IMPORT";
    case WeakImportAttrSpelling::C2X_CLANG_WEAK_IMPORT: return "C2X_CLANG_WEAK_IMPORT";
    case WeakImportAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
