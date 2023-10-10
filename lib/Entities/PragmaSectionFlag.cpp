// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/PragmaSectionFlag.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(PragmaSectionFlag e) {
  switch (e) {
    case PragmaSectionFlag::NONE: return "NONE";
    case PragmaSectionFlag::READ: return "READ";
    case PragmaSectionFlag::WRITE: return "WRITE";
    case PragmaSectionFlag::EXECUTE: return "EXECUTE";
    case PragmaSectionFlag::IMPLICIT: return "IMPLICIT";
    case PragmaSectionFlag::ZERO_INITIALIZER: return "ZERO_INITIALIZER";
    case PragmaSectionFlag::INVALID: return "INVALID";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
