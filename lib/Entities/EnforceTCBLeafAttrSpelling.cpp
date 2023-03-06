// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/EnforceTCBLeafAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(EnforceTCBLeafAttrSpelling e) {
  switch (e) {
    case EnforceTCBLeafAttrSpelling::GNU_ENFORCE_TCB_LEAF: return "GNU_ENFORCE_TCB_LEAF";
    case EnforceTCBLeafAttrSpelling::CXX11_CLANG_ENFORCE_TCB_LEAF: return "CXX11_CLANG_ENFORCE_TCB_LEAF";
    case EnforceTCBLeafAttrSpelling::C2X_CLANG_ENFORCE_TCB_LEAF: return "C2X_CLANG_ENFORCE_TCB_LEAF";
    case EnforceTCBLeafAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
