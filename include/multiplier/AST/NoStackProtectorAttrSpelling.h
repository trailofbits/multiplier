// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class NoStackProtectorAttrSpelling : unsigned char {
  GNU_NO_STACK_PROTECTOR,
  CXX11_CLANG_NO_STACK_PROTECTOR,
  C2X_CLANG_NO_STACK_PROTECTOR,
  DECLSPEC_SAFEBUFFERS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NoStackProtectorAttrSpelling) {
  return "NoStackProtectorAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NoStackProtectorAttrSpelling) {
  return 5;
}

const char *EnumeratorName(NoStackProtectorAttrSpelling);

} // namespace mx
