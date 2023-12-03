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
enum class SFINAEResponse : unsigned char {
  SUBSTITUTION_FAILURE,
  SUPPRESS,
  REPORT,
  ACCESS_CONTROL,
};

inline static const char *EnumerationName(SFINAEResponse) {
  return "SFINAEResponse";
}

inline static constexpr unsigned NumEnumerators(SFINAEResponse) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(SFINAEResponse);

} // namespace mx
