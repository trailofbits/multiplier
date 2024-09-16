// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class DLLImportAttrSpelling : unsigned char {
  DECLSPEC_DLLIMPORT,
  GNU_DLLIMPORT,
  CXX11_GNU_DLLIMPORT,
  C23_GNU_DLLIMPORT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(DLLImportAttrSpelling) {
  return "DLLImportAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(DLLImportAttrSpelling) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(DLLImportAttrSpelling);

} // namespace mx
