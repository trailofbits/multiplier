// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/StdCallAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(StdCallAttrSpelling e) {
  switch (e) {
    case StdCallAttrSpelling::GNU_STDCALL: return "GNU_STDCALL";
    case StdCallAttrSpelling::CXX11_GNU_STDCALL: return "CXX11_GNU_STDCALL";
    case StdCallAttrSpelling::C23_GNU_STDCALL: return "C23_GNU_STDCALL";
    case StdCallAttrSpelling::KEYWORD_STDCALL: return "KEYWORD_STDCALL";
    case StdCallAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
