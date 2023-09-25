// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class DisableSanitizerInstrumentationAttrSpelling : unsigned char {
  GNU_DISABLE_SANITIZER_INSTRUMENTATION,
  CXX11_CLANG_DISABLE_SANITIZER_INSTRUMENTATION,
  C23_CLANG_DISABLE_SANITIZER_INSTRUMENTATION,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(DisableSanitizerInstrumentationAttrSpelling) {
  return "DisableSanitizerInstrumentationAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(DisableSanitizerInstrumentationAttrSpelling) {
  return 4;
}

const char *EnumeratorName(DisableSanitizerInstrumentationAttrSpelling);

} // namespace mx
