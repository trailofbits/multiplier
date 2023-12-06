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
enum class GCMode : unsigned char {
  NON_GC,
  GC_ONLY,
  HYBRID_GC,
};

inline static const char *EnumerationName(GCMode) {
  return "GCMode";
}

inline static constexpr unsigned NumEnumerators(GCMode) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(GCMode);

} // namespace mx
