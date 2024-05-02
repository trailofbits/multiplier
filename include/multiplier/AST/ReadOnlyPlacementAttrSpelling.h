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
enum class ReadOnlyPlacementAttrSpelling : unsigned char {
  GNU_ENFORCE_READ_ONLY_PLACEMENT,
  CXX11_CLANG_ENFORCE_READ_ONLY_PLACEMENT,
  C23_CLANG_ENFORCE_READ_ONLY_PLACEMENT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ReadOnlyPlacementAttrSpelling) {
  return "ReadOnlyPlacementAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ReadOnlyPlacementAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ReadOnlyPlacementAttrSpelling);

} // namespace mx
