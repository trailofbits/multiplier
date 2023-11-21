// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CPUSpecificAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CPUSpecificAttrSpelling e) {
  switch (e) {
    case CPUSpecificAttrSpelling::GNU_CPU_SPECIFIC: return "GNU_CPU_SPECIFIC";
    case CPUSpecificAttrSpelling::CXX11_CLANG_CPU_SPECIFIC: return "CXX11_CLANG_CPU_SPECIFIC";
    case CPUSpecificAttrSpelling::C2X_CLANG_CPU_SPECIFIC: return "C2X_CLANG_CPU_SPECIFIC";
    case CPUSpecificAttrSpelling::DECLSPEC_CPU_SPECIFIC: return "DECLSPEC_CPU_SPECIFIC";
    case CPUSpecificAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
