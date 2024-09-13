// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class OpenMPLastprivateModifier : unsigned char {
  CONDITIONAL,
  UNKNOWN,
};

inline static const char *EnumerationName(OpenMPLastprivateModifier) {
  return "OpenMPLastprivateModifier";
}

inline static constexpr unsigned NumEnumerators(OpenMPLastprivateModifier) {
  return 2;
}

MX_EXPORT const char *EnumeratorName(OpenMPLastprivateModifier);

} // namespace mx
