// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class OpenMPAtomicDefaultMemOrderClauseKind : unsigned char {
  SEQ_CST,
  ACQ_REL,
  RELAXED,
  UNKNOWN,
};

inline static const char *EnumerationName(OpenMPAtomicDefaultMemOrderClauseKind) {
  return "OpenMPAtomicDefaultMemOrderClauseKind";
}

inline static constexpr unsigned NumEnumerators(OpenMPAtomicDefaultMemOrderClauseKind) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(OpenMPAtomicDefaultMemOrderClauseKind);

} // namespace mx
