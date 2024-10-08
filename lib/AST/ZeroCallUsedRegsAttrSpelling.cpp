// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ZeroCallUsedRegsAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ZeroCallUsedRegsAttrSpelling e) {
  switch (e) {
    case ZeroCallUsedRegsAttrSpelling::GNU_ZERO_CALL_USED_REGS: return "GNU_ZERO_CALL_USED_REGS";
    case ZeroCallUsedRegsAttrSpelling::CXX11_GNU_ZERO_CALL_USED_REGS: return "CXX11_GNU_ZERO_CALL_USED_REGS";
    case ZeroCallUsedRegsAttrSpelling::C23_GNU_ZERO_CALL_USED_REGS: return "C23_GNU_ZERO_CALL_USED_REGS";
    case ZeroCallUsedRegsAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
