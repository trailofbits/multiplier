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
enum class LambdaCaptureKind : unsigned char {
  THIS,
  STAR_THIS,
  BY_COPY,
  BY_REFERENCE,
  VLA_TYPE,
};

inline static const char *EnumerationName(LambdaCaptureKind) {
  return "LambdaCaptureKind";
}

inline static constexpr unsigned NumEnumerators(LambdaCaptureKind) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(LambdaCaptureKind);

} // namespace mx
