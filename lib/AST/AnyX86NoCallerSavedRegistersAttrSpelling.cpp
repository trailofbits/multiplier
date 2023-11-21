// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AnyX86NoCallerSavedRegistersAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AnyX86NoCallerSavedRegistersAttrSpelling e) {
  switch (e) {
    case AnyX86NoCallerSavedRegistersAttrSpelling::GNU_NO_CALLER_SAVED_REGISTERS: return "GNU_NO_CALLER_SAVED_REGISTERS";
    case AnyX86NoCallerSavedRegistersAttrSpelling::CXX11_GNU_NO_CALLER_SAVED_REGISTERS: return "CXX11_GNU_NO_CALLER_SAVED_REGISTERS";
    case AnyX86NoCallerSavedRegistersAttrSpelling::C2X_GNU_NO_CALLER_SAVED_REGISTERS: return "C2X_GNU_NO_CALLER_SAVED_REGISTERS";
    case AnyX86NoCallerSavedRegistersAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
