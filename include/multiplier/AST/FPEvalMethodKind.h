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
enum class FPEvalMethodKind : unsigned char {
  FEM_INDETERMINABLE,
  FEM_SOURCE,
  FEM_DOUBLE,
  FEM_EXTENDED,
  FEM_UNSET_ON_COMMAND_LINE,
};

inline static const char *EnumerationName(FPEvalMethodKind) {
  return "FPEvalMethodKind";
}

inline static constexpr unsigned NumEnumerators(FPEvalMethodKind) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(FPEvalMethodKind);

} // namespace mx
