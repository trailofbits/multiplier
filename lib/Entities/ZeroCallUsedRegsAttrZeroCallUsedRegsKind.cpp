// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ZeroCallUsedRegsAttrZeroCallUsedRegsKind.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ZeroCallUsedRegsAttrZeroCallUsedRegsKind e) {
  switch (e) {
    case ZeroCallUsedRegsAttrZeroCallUsedRegsKind::SKIP: return "SKIP";
    case ZeroCallUsedRegsAttrZeroCallUsedRegsKind::USED_GPR_ARG: return "USED_GPR_ARG";
    case ZeroCallUsedRegsAttrZeroCallUsedRegsKind::USED_GPR: return "USED_GPR";
    case ZeroCallUsedRegsAttrZeroCallUsedRegsKind::USED_ARGUMENT: return "USED_ARGUMENT";
    case ZeroCallUsedRegsAttrZeroCallUsedRegsKind::USED: return "USED";
    case ZeroCallUsedRegsAttrZeroCallUsedRegsKind::ALL_GPR_ARG: return "ALL_GPR_ARG";
    case ZeroCallUsedRegsAttrZeroCallUsedRegsKind::ALL_GPR: return "ALL_GPR";
    case ZeroCallUsedRegsAttrZeroCallUsedRegsKind::ALL_ARGUMENT: return "ALL_ARGUMENT";
    case ZeroCallUsedRegsAttrZeroCallUsedRegsKind::ALL: return "ALL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
