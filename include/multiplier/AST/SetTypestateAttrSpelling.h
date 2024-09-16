// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class SetTypestateAttrSpelling : unsigned char {
  GNU_TYPESTATE,
  CXX11_CLANG_TYPESTATE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(SetTypestateAttrSpelling) {
  return "SetTypestateAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(SetTypestateAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(SetTypestateAttrSpelling);

} // namespace mx
