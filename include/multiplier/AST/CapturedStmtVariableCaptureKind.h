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
enum class CapturedStmtVariableCaptureKind : unsigned char {
  THIS,
  BY_REFERENCE,
  BY_COPY,
  VLA_TYPE,
};

inline static const char *EnumerationName(CapturedStmtVariableCaptureKind) {
  return "CapturedStmtVariableCaptureKind";
}

inline static constexpr unsigned NumEnumerators(CapturedStmtVariableCaptureKind) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(CapturedStmtVariableCaptureKind);

} // namespace mx
