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
enum class Linkage : unsigned char {
  NO_LINKAGE,
  INTERNAL_LINKAGE,
  UNIQUE_EXTERNAL_LINKAGE,
  VISIBLE_NO_LINKAGE,
  MODULE_LINKAGE,
  EXTERNAL_LINKAGE,
};

inline static const char *EnumerationName(Linkage) {
  return "Linkage";
}

inline static constexpr unsigned NumEnumerators(Linkage) {
  return 6;
}

MX_EXPORT const char *EnumeratorName(Linkage);

} // namespace mx
