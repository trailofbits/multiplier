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
enum class BPFPreserveStaticOffsetAttrSpelling : unsigned char {
  GNU_PRESERVE_STATIC_OFFSET,
  CXX11_CLANG_PRESERVE_STATIC_OFFSET,
  C23_CLANG_PRESERVE_STATIC_OFFSET,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(BPFPreserveStaticOffsetAttrSpelling) {
  return "BPFPreserveStaticOffsetAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(BPFPreserveStaticOffsetAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(BPFPreserveStaticOffsetAttrSpelling);

} // namespace mx
