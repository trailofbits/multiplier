// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class DLLExportAttrSpelling : unsigned char {
  DECLSPEC_DLLEXPORT,
  GNU_DLLEXPORT,
  CXX11_GNU_DLLEXPORT,
  C23_GNU_DLLEXPORT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(DLLExportAttrSpelling) {
  return "DLLExportAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(DLLExportAttrSpelling) {
  return 5;
}

const char *EnumeratorName(DLLExportAttrSpelling);

} // namespace mx
