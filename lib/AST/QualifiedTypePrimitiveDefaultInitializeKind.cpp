// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/QualifiedTypePrimitiveDefaultInitializeKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(QualifiedTypePrimitiveDefaultInitializeKind e) {
  switch (e) {
    case QualifiedTypePrimitiveDefaultInitializeKind::TRIVIAL: return "TRIVIAL";
    case QualifiedTypePrimitiveDefaultInitializeKind::ARC_STRONG: return "ARC_STRONG";
    case QualifiedTypePrimitiveDefaultInitializeKind::ARC_WEAK: return "ARC_WEAK";
    case QualifiedTypePrimitiveDefaultInitializeKind::STRUCT: return "STRUCT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
