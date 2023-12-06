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
enum class UuidAttrSpelling : unsigned char {
  DECLSPEC_UUID,
  MICROSOFT_UUID,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(UuidAttrSpelling) {
  return "UuidAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(UuidAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(UuidAttrSpelling);

} // namespace mx
