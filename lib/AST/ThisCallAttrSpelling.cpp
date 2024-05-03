// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ThisCallAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ThisCallAttrSpelling e) {
  switch (e) {
    case ThisCallAttrSpelling::GNU_THISCALL: return "GNU_THISCALL";
    case ThisCallAttrSpelling::CXX11_GNU_THISCALL: return "CXX11_GNU_THISCALL";
    case ThisCallAttrSpelling::C23_GNU_THISCALL: return "C23_GNU_THISCALL";
    case ThisCallAttrSpelling::KEYWORD_THISCALL: return "KEYWORD_THISCALL";
    case ThisCallAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
