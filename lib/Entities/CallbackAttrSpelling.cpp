// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CallbackAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CallbackAttrSpelling e) {
  switch (e) {
    case CallbackAttrSpelling::GNU_CALLBACK: return "GNU_CALLBACK";
    case CallbackAttrSpelling::CXX11_CLANG_CALLBACK: return "CXX11_CLANG_CALLBACK";
    case CallbackAttrSpelling::C23_CLANG_CALLBACK: return "C23_CLANG_CALLBACK";
    case CallbackAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
