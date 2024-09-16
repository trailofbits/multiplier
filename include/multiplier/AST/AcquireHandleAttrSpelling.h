// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class AcquireHandleAttrSpelling : unsigned char {
  GNU_ACQUIRE_HANDLE,
  CXX11_CLANG_ACQUIRE_HANDLE,
  C23_CLANG_ACQUIRE_HANDLE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AcquireHandleAttrSpelling) {
  return "AcquireHandleAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AcquireHandleAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(AcquireHandleAttrSpelling);

} // namespace mx
