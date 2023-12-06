// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class NoThreadSafetyAnalysisAttrSpelling : unsigned char {
  GNU_NO_THREAD_SAFETY_ANALYSIS,
  CXX11_CLANG_NO_THREAD_SAFETY_ANALYSIS,
  C2X_CLANG_NO_THREAD_SAFETY_ANALYSIS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NoThreadSafetyAnalysisAttrSpelling) {
  return "NoThreadSafetyAnalysisAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NoThreadSafetyAnalysisAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(NoThreadSafetyAnalysisAttrSpelling);

} // namespace mx
