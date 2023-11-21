// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TrivialAutoVarInitKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TrivialAutoVarInitKind e) {
  switch (e) {
    case TrivialAutoVarInitKind::UNINITIALIZED: return "UNINITIALIZED";
    case TrivialAutoVarInitKind::ZERO: return "ZERO";
    case TrivialAutoVarInitKind::PATTERN: return "PATTERN";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
