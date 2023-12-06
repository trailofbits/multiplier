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
enum class TestTypestateAttrSpelling : unsigned char {
  GNU_TEST_TYPESTATE,
  CXX11_CLANG_TEST_TYPESTATE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(TestTypestateAttrSpelling) {
  return "TestTypestateAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(TestTypestateAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(TestTypestateAttrSpelling);

} // namespace mx
