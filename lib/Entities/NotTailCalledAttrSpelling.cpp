// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/NotTailCalledAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NotTailCalledAttrSpelling e) {
  switch (e) {
    case NotTailCalledAttrSpelling::GNU_NOT_TAIL_CALLED: return "GNU_NOT_TAIL_CALLED";
    case NotTailCalledAttrSpelling::CXX11_CLANG_NOT_TAIL_CALLED: return "CXX11_CLANG_NOT_TAIL_CALLED";
    case NotTailCalledAttrSpelling::C23_CLANG_NOT_TAIL_CALLED: return "C23_CLANG_NOT_TAIL_CALLED";
    case NotTailCalledAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
