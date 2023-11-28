// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/WeakAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(WeakAttrSpelling e) {
  switch (e) {
    case WeakAttrSpelling::GNU_WEAK: return "GNU_WEAK";
    case WeakAttrSpelling::CXX11_GNU_WEAK: return "CXX11_GNU_WEAK";
    case WeakAttrSpelling::C2X_GNU_WEAK: return "C2X_GNU_WEAK";
    case WeakAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
