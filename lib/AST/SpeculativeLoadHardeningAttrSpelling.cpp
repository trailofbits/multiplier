// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SpeculativeLoadHardeningAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SpeculativeLoadHardeningAttrSpelling e) {
  switch (e) {
    case SpeculativeLoadHardeningAttrSpelling::GNU_SPECULATIVE_LOAD_HARDENING: return "GNU_SPECULATIVE_LOAD_HARDENING";
    case SpeculativeLoadHardeningAttrSpelling::CXX11_CLANG_SPECULATIVE_LOAD_HARDENING: return "CXX11_CLANG_SPECULATIVE_LOAD_HARDENING";
    case SpeculativeLoadHardeningAttrSpelling::C2X_CLANG_SPECULATIVE_LOAD_HARDENING: return "C2X_CLANG_SPECULATIVE_LOAD_HARDENING";
    case SpeculativeLoadHardeningAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
