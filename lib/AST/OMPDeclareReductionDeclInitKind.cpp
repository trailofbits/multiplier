// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OMPDeclareReductionDeclInitKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OMPDeclareReductionDeclInitKind e) {
  switch (e) {
    case OMPDeclareReductionDeclInitKind::CALL_INITIALIZER: return "CALL_INITIALIZER";
    case OMPDeclareReductionDeclInitKind::DIRECT_INITIALIZER: return "DIRECT_INITIALIZER";
    case OMPDeclareReductionDeclInitKind::COPY_INITIALIZER: return "COPY_INITIALIZER";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
