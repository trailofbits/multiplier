// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class FPExceptionModeKind : unsigned char {
  IGNORE,
  MAY_TRAP,
  STRICT,
  DEFAULT,
};

inline static const char *EnumerationName(FPExceptionModeKind) {
  return "FPExceptionModeKind";
}

inline static constexpr unsigned NumEnumerators(FPExceptionModeKind) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(FPExceptionModeKind);

} // namespace mx
