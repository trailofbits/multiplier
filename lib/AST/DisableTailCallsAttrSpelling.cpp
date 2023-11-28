// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/DisableTailCallsAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(DisableTailCallsAttrSpelling e) {
  switch (e) {
    case DisableTailCallsAttrSpelling::GNU_DISABLE_TAIL_CALLS: return "GNU_DISABLE_TAIL_CALLS";
    case DisableTailCallsAttrSpelling::CXX11_CLANG_DISABLE_TAIL_CALLS: return "CXX11_CLANG_DISABLE_TAIL_CALLS";
    case DisableTailCallsAttrSpelling::C2X_CLANG_DISABLE_TAIL_CALLS: return "C2X_CLANG_DISABLE_TAIL_CALLS";
    case DisableTailCallsAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
