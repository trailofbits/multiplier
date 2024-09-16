// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class OpenMPMapClauseKind : unsigned char {
  ALLOC,
  TO,
  FROM,
  TOFROM,
  DELETE,
  RELEASE,
  UNKNOWN,
};

inline static const char *EnumerationName(OpenMPMapClauseKind) {
  return "OpenMPMapClauseKind";
}

inline static constexpr unsigned NumEnumerators(OpenMPMapClauseKind) {
  return 7;
}

MX_EXPORT const char *EnumeratorName(OpenMPMapClauseKind);

} // namespace mx
