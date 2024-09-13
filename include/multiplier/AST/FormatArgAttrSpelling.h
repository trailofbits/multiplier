// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class FormatArgAttrSpelling : unsigned char {
  GNU_FORMAT_ARGUMENT,
  CXX11_GNU_FORMAT_ARGUMENT,
  C23_GNU_FORMAT_ARGUMENT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(FormatArgAttrSpelling) {
  return "FormatArgAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(FormatArgAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(FormatArgAttrSpelling);

} // namespace mx
