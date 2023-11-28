// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ARMInterruptAttrInterruptType.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ARMInterruptAttrInterruptType e) {
  switch (e) {
    case ARMInterruptAttrInterruptType::IRQ: return "IRQ";
    case ARMInterruptAttrInterruptType::FIQ: return "FIQ";
    case ARMInterruptAttrInterruptType::SWI: return "SWI";
    case ARMInterruptAttrInterruptType::ABORT: return "ABORT";
    case ARMInterruptAttrInterruptType::UNDEF: return "UNDEF";
    case ARMInterruptAttrInterruptType::GENERIC: return "GENERIC";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
