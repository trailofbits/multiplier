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
enum class AlwaysDestroyAttrSpelling : unsigned char {
  GNU_ALWAYS_DESTROY,
  CXX11_CLANG_ALWAYS_DESTROY,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AlwaysDestroyAttrSpelling) {
  return "AlwaysDestroyAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AlwaysDestroyAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(AlwaysDestroyAttrSpelling);

} // namespace mx
