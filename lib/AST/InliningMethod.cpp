// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/InliningMethod.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(InliningMethod e) {
  switch (e) {
    case InliningMethod::NORMAL_INLINING: return "NORMAL_INLINING";
    case InliningMethod::ONLY_HINT_INLINING: return "ONLY_HINT_INLINING";
    case InliningMethod::ONLY_ALWAYS_INLINING: return "ONLY_ALWAYS_INLINING";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
