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
enum class OpenMPLinearClauseKind : unsigned char {
  VALUE,
  REFERENCE,
  UVAL,
  UNKNOWN,
};

inline static const char *EnumerationName(OpenMPLinearClauseKind) {
  return "OpenMPLinearClauseKind";
}

inline static constexpr unsigned NumEnumerators(OpenMPLinearClauseKind) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(OpenMPLinearClauseKind);

} // namespace mx
