// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/HotAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(HotAttrSpelling e) {
  switch (e) {
    case HotAttrSpelling::GNU_HOT: return "GNU_HOT";
    case HotAttrSpelling::CXX11_GNU_HOT: return "CXX11_GNU_HOT";
    case HotAttrSpelling::C23_GNU_HOT: return "C23_GNU_HOT";
    case HotAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
