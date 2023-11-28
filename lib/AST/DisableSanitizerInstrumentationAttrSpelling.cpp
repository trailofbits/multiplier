// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/DisableSanitizerInstrumentationAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(DisableSanitizerInstrumentationAttrSpelling e) {
  switch (e) {
    case DisableSanitizerInstrumentationAttrSpelling::GNU_DISABLE_SANITIZER_INSTRUMENTATION: return "GNU_DISABLE_SANITIZER_INSTRUMENTATION";
    case DisableSanitizerInstrumentationAttrSpelling::CXX11_CLANG_DISABLE_SANITIZER_INSTRUMENTATION: return "CXX11_CLANG_DISABLE_SANITIZER_INSTRUMENTATION";
    case DisableSanitizerInstrumentationAttrSpelling::C2X_CLANG_DISABLE_SANITIZER_INSTRUMENTATION: return "C2X_CLANG_DISABLE_SANITIZER_INSTRUMENTATION";
    case DisableSanitizerInstrumentationAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
