// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class PatchableFunctionEntryAttrSpelling : unsigned char {
  GNU_PATCHABLE_FUNCTION_ENTRY,
  CXX11_GNU_PATCHABLE_FUNCTION_ENTRY,
  C23_GNU_PATCHABLE_FUNCTION_ENTRY,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(PatchableFunctionEntryAttrSpelling) {
  return "PatchableFunctionEntryAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(PatchableFunctionEntryAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(PatchableFunctionEntryAttrSpelling);

} // namespace mx
