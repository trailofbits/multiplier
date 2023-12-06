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
enum class SpecialMemberFlags : unsigned char {
  DEFAULT_CONSTRUCTOR,
  COPY_CONSTRUCTOR,
  MOVE_CONSTRUCTOR,
  COPY_ASSIGNMENT,
  MOVE_ASSIGNMENT,
  DESTRUCTOR,
  ALL,
};

inline static const char *EnumerationName(SpecialMemberFlags) {
  return "SpecialMemberFlags";
}

inline static constexpr unsigned NumEnumerators(SpecialMemberFlags) {
  return 7;
}

MX_EXPORT const char *EnumeratorName(SpecialMemberFlags);

} // namespace mx
