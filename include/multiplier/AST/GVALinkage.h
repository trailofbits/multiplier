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
enum class GVALinkage : unsigned char {
  INTERNAL,
  AVAILABLE_EXTERNALLY,
  DISCARDABLE_ODR,
  STRONG_EXTERNAL,
  STRONG_ODR,
};

inline static const char *EnumerationName(GVALinkage) {
  return "GVALinkage";
}

inline static constexpr unsigned NumEnumerators(GVALinkage) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(GVALinkage);

} // namespace mx
