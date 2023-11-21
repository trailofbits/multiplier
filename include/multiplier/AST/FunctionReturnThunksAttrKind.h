// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class FunctionReturnThunksAttrKind : unsigned char {
  KEEP,
  EXTERN,
};

inline static const char *EnumerationName(FunctionReturnThunksAttrKind) {
  return "FunctionReturnThunksAttrKind";
}

inline static constexpr unsigned NumEnumerators(FunctionReturnThunksAttrKind) {
  return 2;
}

const char *EnumeratorName(FunctionReturnThunksAttrKind);

} // namespace mx
