// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/MSVtorDispMode.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(MSVtorDispMode e) {
  switch (e) {
    case MSVtorDispMode::NEVER: return "NEVER";
    case MSVtorDispMode::FOR_VIRTUAL_BASE_OVERRIDE: return "FOR_VIRTUAL_BASE_OVERRIDE";
    case MSVtorDispMode::FOR_VF_TABLE: return "FOR_VF_TABLE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
