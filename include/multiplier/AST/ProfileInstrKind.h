// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ProfileInstrKind : unsigned char {
  PROFILE_NONE,
  PROFILE_CLANG_INSTR,
  PROFILE_IR_INSTR,
  PROFILE_CSIR_INSTR,
};

inline static const char *EnumerationName(ProfileInstrKind) {
  return "ProfileInstrKind";
}

inline static constexpr unsigned NumEnumerators(ProfileInstrKind) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ProfileInstrKind);

} // namespace mx
