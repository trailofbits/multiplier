// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SuppressAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SuppressAttrSpelling e) {
  switch (e) {
    case SuppressAttrSpelling::CXX11_GSL_SUPPRESS: return "CXX11_GSL_SUPPRESS";
    case SuppressAttrSpelling::GNU_SUPPRESS: return "GNU_SUPPRESS";
    case SuppressAttrSpelling::CXX11_CLANG_SUPPRESS: return "CXX11_CLANG_SUPPRESS";
    case SuppressAttrSpelling::C23_CLANG_SUPPRESS: return "C23_CLANG_SUPPRESS";
    case SuppressAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
