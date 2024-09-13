// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class X86ForceAlignArgPointerAttrSpelling : unsigned char {
  GNU_FORCE_ALIGN_ARGUMENT_POINTER,
  CXX11_GNU_FORCE_ALIGN_ARGUMENT_POINTER,
  C23_GNU_FORCE_ALIGN_ARGUMENT_POINTER,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(X86ForceAlignArgPointerAttrSpelling) {
  return "X86ForceAlignArgPointerAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(X86ForceAlignArgPointerAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(X86ForceAlignArgPointerAttrSpelling);

} // namespace mx
