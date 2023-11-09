// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class FunctionReturnThunksAttrSpelling : unsigned char {
  GNU_FUNCTION_RETURN,
  CXX11_GNU_FUNCTION_RETURN,
  C2X_GNU_FUNCTION_RETURN,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(FunctionReturnThunksAttrSpelling) {
  return "FunctionReturnThunksAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(FunctionReturnThunksAttrSpelling) {
  return 4;
}

const char *EnumeratorName(FunctionReturnThunksAttrSpelling);

} // namespace mx
