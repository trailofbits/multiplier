// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/UnavailableAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(UnavailableAttrSpelling e) {
  switch (e) {
    case UnavailableAttrSpelling::GNU_UNAVAILABLE: return "GNU_UNAVAILABLE";
    case UnavailableAttrSpelling::CXX11_CLANG_UNAVAILABLE: return "CXX11_CLANG_UNAVAILABLE";
    case UnavailableAttrSpelling::C2X_CLANG_UNAVAILABLE: return "C2X_CLANG_UNAVAILABLE";
    case UnavailableAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
