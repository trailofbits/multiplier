// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class WebAssemblyImportModuleAttrSpelling : unsigned char {
  GNU_IMPORT_MODULE,
  CXX11_CLANG_IMPORT_MODULE,
  C2X_CLANG_IMPORT_MODULE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(WebAssemblyImportModuleAttrSpelling) {
  return "WebAssemblyImportModuleAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(WebAssemblyImportModuleAttrSpelling) {
  return 4;
}

const char *EnumeratorName(WebAssemblyImportModuleAttrSpelling);

} // namespace mx
