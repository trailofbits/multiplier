// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/StorageDuration.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(StorageDuration e) {
  switch (e) {
    case StorageDuration::FULL_EXPRESSION: return "FULL_EXPRESSION";
    case StorageDuration::AUTOMATIC: return "AUTOMATIC";
    case StorageDuration::THREAD: return "THREAD";
    case StorageDuration::STATIC: return "STATIC";
    case StorageDuration::DYNAMIC: return "DYNAMIC";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
