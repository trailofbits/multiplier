// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class PragmaFPKind : unsigned char {
  PFK_CONTRACT,
  PFK_REASSOCIATE,
  PFK_RECIPROCAL,
  PFK_EXCEPTIONS,
  PFK_EVAL_METHOD,
};

inline static const char *EnumerationName(PragmaFPKind) {
  return "PragmaFPKind";
}

inline static constexpr unsigned NumEnumerators(PragmaFPKind) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(PragmaFPKind);

} // namespace mx
