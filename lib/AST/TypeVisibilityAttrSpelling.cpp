// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TypeVisibilityAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TypeVisibilityAttrSpelling e) {
  switch (e) {
    case TypeVisibilityAttrSpelling::GNU_TYPE_VISIBILITY: return "GNU_TYPE_VISIBILITY";
    case TypeVisibilityAttrSpelling::CXX11_CLANG_TYPE_VISIBILITY: return "CXX11_CLANG_TYPE_VISIBILITY";
    case TypeVisibilityAttrSpelling::C2X_CLANG_TYPE_VISIBILITY: return "C2X_CLANG_TYPE_VISIBILITY";
    case TypeVisibilityAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
