// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/MSP430InterruptAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(MSP430InterruptAttrSpelling e) {
  switch (e) {
    case MSP430InterruptAttrSpelling::GNU_INTERRUPT: return "GNU_INTERRUPT";
    case MSP430InterruptAttrSpelling::CXX11_GNU_INTERRUPT: return "CXX11_GNU_INTERRUPT";
    case MSP430InterruptAttrSpelling::C23_GNU_INTERRUPT: return "C23_GNU_INTERRUPT";
    case MSP430InterruptAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
