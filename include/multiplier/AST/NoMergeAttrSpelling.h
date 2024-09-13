// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class NoMergeAttrSpelling : unsigned char {
  GNU_NOMERGE,
  CXX11_CLANG_NOMERGE,
  C23_CLANG_NOMERGE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NoMergeAttrSpelling) {
  return "NoMergeAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NoMergeAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(NoMergeAttrSpelling);

} // namespace mx
