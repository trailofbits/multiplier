// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/NoThreadSafetyAnalysisAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NoThreadSafetyAnalysisAttrSpelling e) {
  switch (e) {
    case NoThreadSafetyAnalysisAttrSpelling::GNU_NO_THREAD_SAFETY_ANALYSIS: return "GNU_NO_THREAD_SAFETY_ANALYSIS";
    case NoThreadSafetyAnalysisAttrSpelling::CXX11_CLANG_NO_THREAD_SAFETY_ANALYSIS: return "CXX11_CLANG_NO_THREAD_SAFETY_ANALYSIS";
    case NoThreadSafetyAnalysisAttrSpelling::C23_CLANG_NO_THREAD_SAFETY_ANALYSIS: return "C23_CLANG_NO_THREAD_SAFETY_ANALYSIS";
    case NoThreadSafetyAnalysisAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
