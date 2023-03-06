// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MipsInterruptAttrInterruptType.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(MipsInterruptAttrInterruptType e) {
  switch (e) {
    case MipsInterruptAttrInterruptType::SW0: return "SW0";
    case MipsInterruptAttrInterruptType::SW1: return "SW1";
    case MipsInterruptAttrInterruptType::HW0: return "HW0";
    case MipsInterruptAttrInterruptType::HW1: return "HW1";
    case MipsInterruptAttrInterruptType::HW2: return "HW2";
    case MipsInterruptAttrInterruptType::HW3: return "HW3";
    case MipsInterruptAttrInterruptType::HW4: return "HW4";
    case MipsInterruptAttrInterruptType::HW5: return "HW5";
    case MipsInterruptAttrInterruptType::EIC: return "EIC";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
