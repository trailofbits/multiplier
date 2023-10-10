// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CalledOnceAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CalledOnceAttrSpelling e) {
  switch (e) {
    case CalledOnceAttrSpelling::GNU_CALLED_ONCE: return "GNU_CALLED_ONCE";
    case CalledOnceAttrSpelling::CXX11_CLANG_CALLED_ONCE: return "CXX11_CLANG_CALLED_ONCE";
    case CalledOnceAttrSpelling::C23_CLANG_CALLED_ONCE: return "C23_CLANG_CALLED_ONCE";
    case CalledOnceAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
