// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/QualifiedTypePrimitiveCopyKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(QualifiedTypePrimitiveCopyKind e) {
  switch (e) {
    case QualifiedTypePrimitiveCopyKind::TRIVIAL: return "TRIVIAL";
    case QualifiedTypePrimitiveCopyKind::VOLATILE_TRIVIAL: return "VOLATILE_TRIVIAL";
    case QualifiedTypePrimitiveCopyKind::ARC_STRONG: return "ARC_STRONG";
    case QualifiedTypePrimitiveCopyKind::ARC_WEAK: return "ARC_WEAK";
    case QualifiedTypePrimitiveCopyKind::STRUCT: return "STRUCT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
