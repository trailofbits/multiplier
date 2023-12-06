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
enum class OpenMPAdjustArgsOpKind : unsigned char {
  ADJUSTARGS_NOTHING,
  ADJUSTARGS_NEED_DEVICE_POINTER,
  ADJUSTARGS_UNKNOWN,
};

inline static const char *EnumerationName(OpenMPAdjustArgsOpKind) {
  return "OpenMPAdjustArgsOpKind";
}

inline static constexpr unsigned NumEnumerators(OpenMPAdjustArgsOpKind) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(OpenMPAdjustArgsOpKind);

} // namespace mx
