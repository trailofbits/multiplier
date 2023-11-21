// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AnyX86NoCfCheckAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AnyX86NoCfCheckAttrSpelling e) {
  switch (e) {
    case AnyX86NoCfCheckAttrSpelling::GNU_NOCF_CHECK: return "GNU_NOCF_CHECK";
    case AnyX86NoCfCheckAttrSpelling::CXX11_GNU_NOCF_CHECK: return "CXX11_GNU_NOCF_CHECK";
    case AnyX86NoCfCheckAttrSpelling::C2X_GNU_NOCF_CHECK: return "C2X_GNU_NOCF_CHECK";
    case AnyX86NoCfCheckAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
