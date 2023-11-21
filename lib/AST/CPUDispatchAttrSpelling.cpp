// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CPUDispatchAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CPUDispatchAttrSpelling e) {
  switch (e) {
    case CPUDispatchAttrSpelling::GNU_CPU_DISPATCH: return "GNU_CPU_DISPATCH";
    case CPUDispatchAttrSpelling::CXX11_CLANG_CPU_DISPATCH: return "CXX11_CLANG_CPU_DISPATCH";
    case CPUDispatchAttrSpelling::C2X_CLANG_CPU_DISPATCH: return "C2X_CLANG_CPU_DISPATCH";
    case CPUDispatchAttrSpelling::DECLSPEC_CPU_DISPATCH: return "DECLSPEC_CPU_DISPATCH";
    case CPUDispatchAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
