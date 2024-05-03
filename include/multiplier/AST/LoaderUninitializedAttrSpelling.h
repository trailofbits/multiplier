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
enum class LoaderUninitializedAttrSpelling : unsigned char {
  GNU_LOADER_UNINITIALIZED,
  CXX11_CLANG_LOADER_UNINITIALIZED,
  C23_CLANG_LOADER_UNINITIALIZED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(LoaderUninitializedAttrSpelling) {
  return "LoaderUninitializedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(LoaderUninitializedAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(LoaderUninitializedAttrSpelling);

} // namespace mx
