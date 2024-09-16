// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SwiftAsyncFramePointerKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SwiftAsyncFramePointerKind e) {
  switch (e) {
    case SwiftAsyncFramePointerKind::AUTO: return "AUTO";
    case SwiftAsyncFramePointerKind::ALWAYS: return "ALWAYS";
    case SwiftAsyncFramePointerKind::NEVER: return "NEVER";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
