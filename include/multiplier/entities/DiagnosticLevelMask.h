// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class DiagnosticLevelMask : unsigned char {
  NONE,
  NOTE,
  REMARK,
  WARNING,
  ERROR,
  ALL,
};

inline static const char *EnumerationName(DiagnosticLevelMask) {
  return "DiagnosticLevelMask";
}

inline static constexpr unsigned NumEnumerators(DiagnosticLevelMask) {
  return 6;
}

const char *EnumeratorName(DiagnosticLevelMask);

} // namespace mx
