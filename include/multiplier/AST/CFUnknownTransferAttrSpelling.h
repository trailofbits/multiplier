// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class CFUnknownTransferAttrSpelling : unsigned char {
  GNU_CF_UNKNOWN_TRANSFER,
  CXX11_CLANG_CF_UNKNOWN_TRANSFER,
  C23_CLANG_CF_UNKNOWN_TRANSFER,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CFUnknownTransferAttrSpelling) {
  return "CFUnknownTransferAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CFUnknownTransferAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(CFUnknownTransferAttrSpelling);

} // namespace mx
