// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class VisibilityForcedKinds : unsigned char {
  FORCE_HIDDEN,
  FORCE_PROTECTED,
  FORCE_DEFAULT,
  SOURCE,
};

inline static const char *EnumerationName(VisibilityForcedKinds) {
  return "VisibilityForcedKinds";
}

inline static constexpr unsigned NumEnumerators(VisibilityForcedKinds) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(VisibilityForcedKinds);

} // namespace mx
