// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/PragmaFPKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(PragmaFPKind e) {
  switch (e) {
    case PragmaFPKind::PFK_CONTRACT: return "PFK_CONTRACT";
    case PragmaFPKind::PFK_REASSOCIATE: return "PFK_REASSOCIATE";
    case PragmaFPKind::PFK_RECIPROCAL: return "PFK_RECIPROCAL";
    case PragmaFPKind::PFK_EXCEPTIONS: return "PFK_EXCEPTIONS";
    case PragmaFPKind::PFK_EVAL_METHOD: return "PFK_EVAL_METHOD";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
