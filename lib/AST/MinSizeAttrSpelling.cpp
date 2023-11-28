// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/MinSizeAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(MinSizeAttrSpelling e) {
  switch (e) {
    case MinSizeAttrSpelling::GNU_MINSIZE: return "GNU_MINSIZE";
    case MinSizeAttrSpelling::CXX11_CLANG_MINSIZE: return "CXX11_CLANG_MINSIZE";
    case MinSizeAttrSpelling::C2X_CLANG_MINSIZE: return "C2X_CLANG_MINSIZE";
    case MinSizeAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
