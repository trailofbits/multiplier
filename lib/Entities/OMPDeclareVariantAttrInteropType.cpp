// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPDeclareVariantAttrInteropType.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OMPDeclareVariantAttrInteropType e) {
  switch (e) {
    case OMPDeclareVariantAttrInteropType::TARGET: return "TARGET";
    case OMPDeclareVariantAttrInteropType::TARGET_SYNC: return "TARGET_SYNC";
    case OMPDeclareVariantAttrInteropType::TARGET_TARGET_SYNC: return "TARGET_TARGET_SYNC";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
