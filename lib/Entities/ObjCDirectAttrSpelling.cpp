// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCDirectAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCDirectAttrSpelling e) {
  switch (e) {
    case ObjCDirectAttrSpelling::GNU_OBJC_DIRECT: return "GNU_OBJC_DIRECT";
    case ObjCDirectAttrSpelling::CXX11_CLANG_OBJC_DIRECT: return "CXX11_CLANG_OBJC_DIRECT";
    case ObjCDirectAttrSpelling::C2X_CLANG_OBJC_DIRECT: return "C2X_CLANG_OBJC_DIRECT";
    case ObjCDirectAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
