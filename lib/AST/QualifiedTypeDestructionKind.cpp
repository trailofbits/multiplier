// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/QualifiedTypeDestructionKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(QualifiedTypeDestructionKind e) {
  switch (e) {
    case QualifiedTypeDestructionKind::NONE: return "NONE";
    case QualifiedTypeDestructionKind::CXX_DESTRUCTOR: return "CXX_DESTRUCTOR";
    case QualifiedTypeDestructionKind::OBJC_STRONG_LIFETIME: return "OBJC_STRONG_LIFETIME";
    case QualifiedTypeDestructionKind::OBJC_WEAK_LIFETIME: return "OBJC_WEAK_LIFETIME";
    case QualifiedTypeDestructionKind::NONTRIVIAL_C_STRUCT: return "NONTRIVIAL_C_STRUCT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
