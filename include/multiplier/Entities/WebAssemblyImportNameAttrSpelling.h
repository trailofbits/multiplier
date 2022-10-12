// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class WebAssemblyImportNameAttrSpelling : unsigned char {
  GNU_IMPORT_NAME,
  CXX11_CLANG_IMPORT_NAME,
  C2X_CLANG_IMPORT_NAME,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(WebAssemblyImportNameAttrSpelling) {
  return "WebAssemblyImportNameAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(WebAssemblyImportNameAttrSpelling) {
  return 4;
}

const char *EnumeratorName(WebAssemblyImportNameAttrSpelling);

} // namespace mx
