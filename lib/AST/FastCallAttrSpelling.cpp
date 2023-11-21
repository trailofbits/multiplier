// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/FastCallAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(FastCallAttrSpelling e) {
  switch (e) {
    case FastCallAttrSpelling::GNU_FASTCALL: return "GNU_FASTCALL";
    case FastCallAttrSpelling::CXX11_GNU_FASTCALL: return "CXX11_GNU_FASTCALL";
    case FastCallAttrSpelling::C2X_GNU_FASTCALL: return "C2X_GNU_FASTCALL";
    case FastCallAttrSpelling::KEYWORD_FASTCALL: return "KEYWORD_FASTCALL";
    case FastCallAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
