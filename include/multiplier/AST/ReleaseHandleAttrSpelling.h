// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ReleaseHandleAttrSpelling : unsigned char {
  GNU_RELEASE_HANDLE,
  CXX11_CLANG_RELEASE_HANDLE,
  C23_CLANG_RELEASE_HANDLE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ReleaseHandleAttrSpelling) {
  return "ReleaseHandleAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ReleaseHandleAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ReleaseHandleAttrSpelling);

} // namespace mx
