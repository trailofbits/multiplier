// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class NoDestroyAttrSpelling : unsigned char {
  GNU_NO_DESTROY,
  CXX11_CLANG_NO_DESTROY,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NoDestroyAttrSpelling) {
  return "NoDestroyAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NoDestroyAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(NoDestroyAttrSpelling);

} // namespace mx
