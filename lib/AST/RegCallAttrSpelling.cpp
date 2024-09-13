// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/RegCallAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(RegCallAttrSpelling e) {
  switch (e) {
    case RegCallAttrSpelling::GNU_REGCALL: return "GNU_REGCALL";
    case RegCallAttrSpelling::CXX11_GNU_REGCALL: return "CXX11_GNU_REGCALL";
    case RegCallAttrSpelling::C23_GNU_REGCALL: return "C23_GNU_REGCALL";
    case RegCallAttrSpelling::KEYWORD_REGCALL: return "KEYWORD_REGCALL";
    case RegCallAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
