// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/PreserveMostAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(PreserveMostAttrSpelling e) {
  switch (e) {
    case PreserveMostAttrSpelling::GNU_PRESERVE_MOST: return "GNU_PRESERVE_MOST";
    case PreserveMostAttrSpelling::CXX11_CLANG_PRESERVE_MOST: return "CXX11_CLANG_PRESERVE_MOST";
    case PreserveMostAttrSpelling::C2X_CLANG_PRESERVE_MOST: return "C2X_CLANG_PRESERVE_MOST";
    case PreserveMostAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
