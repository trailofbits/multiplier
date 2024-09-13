// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class OpenMPDoacrossClauseModifier : unsigned char {
  DOACROSS_SOURCE,
  DOACROSS_SINK,
  DOACROSS_SINK_OMP_CUR_ITERATION,
  DOACROSS_SOURCE_OMP_CUR_ITERATION,
  DOACROSS_UNKNOWN,
};

inline static const char *EnumerationName(OpenMPDoacrossClauseModifier) {
  return "OpenMPDoacrossClauseModifier";
}

inline static constexpr unsigned NumEnumerators(OpenMPDoacrossClauseModifier) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(OpenMPDoacrossClauseModifier);

} // namespace mx
