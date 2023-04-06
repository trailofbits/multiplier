// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class OpenMPSeverityClauseKind : unsigned char {
  SEVERITY_FATAL,
  SEVERITY_WARNING,
  SEVERITY_UNKNOWN,
};

inline static const char *EnumerationName(OpenMPSeverityClauseKind) {
  return "OpenMPSeverityClauseKind";
}

inline static constexpr unsigned NumEnumerators(OpenMPSeverityClauseKind) {
  return 3;
}

const char *EnumeratorName(OpenMPSeverityClauseKind);

} // namespace mx
