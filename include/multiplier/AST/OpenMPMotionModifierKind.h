// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class OpenMPMotionModifierKind : unsigned char {
  MOTIONMODIFIER_MAPPER,
  MOTIONMODIFIER_PRESENT,
  MOTIONMODIFIER_UNKNOWN,
};

inline static const char *EnumerationName(OpenMPMotionModifierKind) {
  return "OpenMPMotionModifierKind";
}

inline static constexpr unsigned NumEnumerators(OpenMPMotionModifierKind) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(OpenMPMotionModifierKind);

} // namespace mx
