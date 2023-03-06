// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/UnaryOperatorKind.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(UnaryOperatorKind e) {
  switch (e) {
    case UnaryOperatorKind::POST_INCREMENT: return "POST_INCREMENT";
    case UnaryOperatorKind::POST_DEC: return "POST_DEC";
    case UnaryOperatorKind::PRE_INCREMENT: return "PRE_INCREMENT";
    case UnaryOperatorKind::PRE_DEC: return "PRE_DEC";
    case UnaryOperatorKind::ADDRESS_OF: return "ADDRESS_OF";
    case UnaryOperatorKind::DEREF: return "DEREF";
    case UnaryOperatorKind::PLUS: return "PLUS";
    case UnaryOperatorKind::MINUS: return "MINUS";
    case UnaryOperatorKind::NOT: return "NOT";
    case UnaryOperatorKind::L_NOT: return "L_NOT";
    case UnaryOperatorKind::REAL: return "REAL";
    case UnaryOperatorKind::IMAG: return "IMAG";
    case UnaryOperatorKind::EXTENSION: return "EXTENSION";
    case UnaryOperatorKind::COAWAIT: return "COAWAIT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
