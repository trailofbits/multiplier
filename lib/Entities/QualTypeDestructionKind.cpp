// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/QualTypeDestructionKind.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(QualTypeDestructionKind e) {
  switch (e) {
    case QualTypeDestructionKind::NONE: return "NONE";
    case QualTypeDestructionKind::CXX_DESTRUCTOR: return "CXX_DESTRUCTOR";
    case QualTypeDestructionKind::OBJC_STRONG_LIFETIME: return "OBJC_STRONG_LIFETIME";
    case QualTypeDestructionKind::OBJC_WEAK_LIFETIME: return "OBJC_WEAK_LIFETIME";
    case QualTypeDestructionKind::NONTRIVIAL_C_STRUCT: return "NONTRIVIAL_C_STRUCT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
