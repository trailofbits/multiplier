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
enum class NSConsumesSelfAttrSpelling : unsigned char {
  GNU_NS_CONSUMES_SELF,
  CXX11_CLANG_NS_CONSUMES_SELF,
  C23_CLANG_NS_CONSUMES_SELF,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NSConsumesSelfAttrSpelling) {
  return "NSConsumesSelfAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NSConsumesSelfAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(NSConsumesSelfAttrSpelling);

} // namespace mx
