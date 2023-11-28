// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AtomicScopeModelKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AtomicScopeModelKind e) {
  switch (e) {
    case AtomicScopeModelKind::NONE: return "NONE";
    case AtomicScopeModelKind::OPEN_CL: return "OPEN_CL";
    case AtomicScopeModelKind::HIP: return "HIP";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
