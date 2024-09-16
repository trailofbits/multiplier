// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CDeclAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CDeclAttrSpelling e) {
  switch (e) {
    case CDeclAttrSpelling::GNU_CDECL: return "GNU_CDECL";
    case CDeclAttrSpelling::CXX11_GNU_CDECL: return "CXX11_GNU_CDECL";
    case CDeclAttrSpelling::C23_GNU_CDECL: return "C23_GNU_CDECL";
    case CDeclAttrSpelling::KEYWORD_CDECL: return "KEYWORD_CDECL";
    case CDeclAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
