// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/UseHandleAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(UseHandleAttrSpelling e) {
  switch (e) {
    case UseHandleAttrSpelling::GNU_USE_HANDLE: return "GNU_USE_HANDLE";
    case UseHandleAttrSpelling::CXX11_CLANG_USE_HANDLE: return "CXX11_CLANG_USE_HANDLE";
    case UseHandleAttrSpelling::C2X_CLANG_USE_HANDLE: return "C2X_CLANG_USE_HANDLE";
    case UseHandleAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
