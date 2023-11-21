// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/StackProtectorMode.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(StackProtectorMode e) {
  switch (e) {
    case StackProtectorMode::OFF: return "OFF";
    case StackProtectorMode::ON: return "ON";
    case StackProtectorMode::STRONG: return "STRONG";
    case StackProtectorMode::REQ: return "REQ";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
