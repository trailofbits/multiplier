// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/StorageClass.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(StorageClass e) {
  switch (e) {
    case StorageClass::NONE: return "NONE";
    case StorageClass::EXTERN: return "EXTERN";
    case StorageClass::STATIC: return "STATIC";
    case StorageClass::PRIVATE_EXTERN: return "PRIVATE_EXTERN";
    case StorageClass::AUTO: return "AUTO";
    case StorageClass::REGISTER: return "REGISTER";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
