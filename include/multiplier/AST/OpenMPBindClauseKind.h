// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class OpenMPBindClauseKind : unsigned char {
  BIND_TEAMS,
  BIND_PARALLEL,
  BIND_THREAD,
  BIND_UNKNOWN,
};

inline static const char *EnumerationName(OpenMPBindClauseKind) {
  return "OpenMPBindClauseKind";
}

inline static constexpr unsigned NumEnumerators(OpenMPBindClauseKind) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(OpenMPBindClauseKind);

} // namespace mx
