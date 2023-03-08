// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/InClassInitStyle.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(InClassInitStyle e) {
  switch (e) {
    case InClassInitStyle::NO_INITIALIZER: return "NO_INITIALIZER";
    case InClassInitStyle::COPY_INITIALIZER: return "COPY_INITIALIZER";
    case InClassInitStyle::LIST_INITIALIZER: return "LIST_INITIALIZER";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
