// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/RecordDeclArgPassingKind.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(RecordDeclArgPassingKind e) {
  switch (e) {
    case RecordDeclArgPassingKind::CAN_PASS_IN_REGS: return "CAN_PASS_IN_REGS";
    case RecordDeclArgPassingKind::CANNOT_PASS_IN_REGS: return "CANNOT_PASS_IN_REGS";
    case RecordDeclArgPassingKind::CAN_NEVER_PASS_IN_REGS: return "CAN_NEVER_PASS_IN_REGS";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
