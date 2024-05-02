// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/NoUwtableAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NoUwtableAttrSpelling e) {
  switch (e) {
    case NoUwtableAttrSpelling::GNU_NOUWTABLE: return "GNU_NOUWTABLE";
    case NoUwtableAttrSpelling::CXX11_CLANG_NOUWTABLE: return "CXX11_CLANG_NOUWTABLE";
    case NoUwtableAttrSpelling::C23_CLANG_NOUWTABLE: return "C23_CLANG_NOUWTABLE";
    case NoUwtableAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
