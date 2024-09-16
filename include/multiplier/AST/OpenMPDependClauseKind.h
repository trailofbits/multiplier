// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class OpenMPDependClauseKind : unsigned char {
  IN,
  OUT,
  INOUT,
  MUTEXINOUTSET,
  DEPOBJ,
  SOURCE,
  SINK,
  INOUTSET,
  OUTALLMEMORY,
  INOUTALLMEMORY,
  UNKNOWN,
};

inline static const char *EnumerationName(OpenMPDependClauseKind) {
  return "OpenMPDependClauseKind";
}

inline static constexpr unsigned NumEnumerators(OpenMPDependClauseKind) {
  return 11;
}

MX_EXPORT const char *EnumeratorName(OpenMPDependClauseKind);

} // namespace mx
