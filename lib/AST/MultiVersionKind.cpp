// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/MultiVersionKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(MultiVersionKind e) {
  switch (e) {
    case MultiVersionKind::NONE: return "NONE";
    case MultiVersionKind::TARGET: return "TARGET";
    case MultiVersionKind::CPU_SPECIFIC: return "CPU_SPECIFIC";
    case MultiVersionKind::CPU_DISPATCH: return "CPU_DISPATCH";
    case MultiVersionKind::TARGET_CLONES: return "TARGET_CLONES";
    case MultiVersionKind::TARGET_VERSION: return "TARGET_VERSION";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
