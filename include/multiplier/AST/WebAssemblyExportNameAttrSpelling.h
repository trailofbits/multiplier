// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class WebAssemblyExportNameAttrSpelling : unsigned char {
  GNU_EXPORT_NAME,
  CXX11_CLANG_EXPORT_NAME,
  C23_CLANG_EXPORT_NAME,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(WebAssemblyExportNameAttrSpelling) {
  return "WebAssemblyExportNameAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(WebAssemblyExportNameAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(WebAssemblyExportNameAttrSpelling);

} // namespace mx
