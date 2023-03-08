// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/FPEvalMethodKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(FPEvalMethodKind e) {
  switch (e) {
    case FPEvalMethodKind::FEM_INDETERMINABLE: return "FEM_INDETERMINABLE";
    case FPEvalMethodKind::FEM_SOURCE: return "FEM_SOURCE";
    case FPEvalMethodKind::FEM_DOUBLE: return "FEM_DOUBLE";
    case FPEvalMethodKind::FEM_EXTENDED: return "FEM_EXTENDED";
    case FPEvalMethodKind::FEM_UNSET_ON_COMMAND_LINE: return "FEM_UNSET_ON_COMMAND_LINE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
