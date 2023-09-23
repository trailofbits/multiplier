// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class MIGServerRoutineAttrSpelling : unsigned char {
  GNU_MIG_SERVER_ROUTINE,
  CXX11_CLANG_MIG_SERVER_ROUTINE,
  C23_CLANG_MIG_SERVER_ROUTINE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(MIGServerRoutineAttrSpelling) {
  return "MIGServerRoutineAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(MIGServerRoutineAttrSpelling) {
  return 4;
}

const char *EnumeratorName(MIGServerRoutineAttrSpelling);

} // namespace mx
