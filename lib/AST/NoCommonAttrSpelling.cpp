// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/NoCommonAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NoCommonAttrSpelling e) {
  switch (e) {
    case NoCommonAttrSpelling::GNU_NOCOMMON: return "GNU_NOCOMMON";
    case NoCommonAttrSpelling::CXX11_GNU_NOCOMMON: return "CXX11_GNU_NOCOMMON";
    case NoCommonAttrSpelling::C23_GNU_NOCOMMON: return "C23_GNU_NOCOMMON";
    case NoCommonAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
