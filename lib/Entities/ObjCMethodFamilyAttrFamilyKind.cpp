// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCMethodFamilyAttrFamilyKind.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCMethodFamilyAttrFamilyKind e) {
  switch (e) {
    case ObjCMethodFamilyAttrFamilyKind::NONE: return "NONE";
    case ObjCMethodFamilyAttrFamilyKind::ALLOC: return "ALLOC";
    case ObjCMethodFamilyAttrFamilyKind::COPY: return "COPY";
    case ObjCMethodFamilyAttrFamilyKind::INITIALIZER: return "INITIALIZER";
    case ObjCMethodFamilyAttrFamilyKind::MUTABLE_COPY: return "MUTABLE_COPY";
    case ObjCMethodFamilyAttrFamilyKind::NEW: return "NEW";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
