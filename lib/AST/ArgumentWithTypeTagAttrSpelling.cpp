// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ArgumentWithTypeTagAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ArgumentWithTypeTagAttrSpelling e) {
  switch (e) {
    case ArgumentWithTypeTagAttrSpelling::GNU_ARGUMENT_WITH_TYPE_TAG: return "GNU_ARGUMENT_WITH_TYPE_TAG";
    case ArgumentWithTypeTagAttrSpelling::CXX11_CLANG_ARGUMENT_WITH_TYPE_TAG: return "CXX11_CLANG_ARGUMENT_WITH_TYPE_TAG";
    case ArgumentWithTypeTagAttrSpelling::C2X_CLANG_ARGUMENT_WITH_TYPE_TAG: return "C2X_CLANG_ARGUMENT_WITH_TYPE_TAG";
    case ArgumentWithTypeTagAttrSpelling::GNU_POINTER_WITH_TYPE_TAG: return "GNU_POINTER_WITH_TYPE_TAG";
    case ArgumentWithTypeTagAttrSpelling::CXX11_CLANG_POINTER_WITH_TYPE_TAG: return "CXX11_CLANG_POINTER_WITH_TYPE_TAG";
    case ArgumentWithTypeTagAttrSpelling::C2X_CLANG_POINTER_WITH_TYPE_TAG: return "C2X_CLANG_POINTER_WITH_TYPE_TAG";
    case ArgumentWithTypeTagAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
