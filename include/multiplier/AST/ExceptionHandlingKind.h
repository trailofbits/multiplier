// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ExceptionHandlingKind : unsigned char {
  NONE,
  SJ_LJ,
  WIN_EH,
  DWARF_CFI,
  WASM,
};

inline static const char *EnumerationName(ExceptionHandlingKind) {
  return "ExceptionHandlingKind";
}

inline static constexpr unsigned NumEnumerators(ExceptionHandlingKind) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(ExceptionHandlingKind);

} // namespace mx
