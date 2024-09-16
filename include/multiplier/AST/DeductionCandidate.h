// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class DeductionCandidate : unsigned char {
  NORMAL,
  COPY,
  AGGREGATE,
};

inline static const char *EnumerationName(DeductionCandidate) {
  return "DeductionCandidate";
}

inline static constexpr unsigned NumEnumerators(DeductionCandidate) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(DeductionCandidate);

} // namespace mx
