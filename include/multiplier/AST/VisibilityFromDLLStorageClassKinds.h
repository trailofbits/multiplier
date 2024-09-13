// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class VisibilityFromDLLStorageClassKinds : unsigned char {
  KEEP,
  DEFAULT,
  HIDDEN,
  PROTECTED,
};

inline static const char *EnumerationName(VisibilityFromDLLStorageClassKinds) {
  return "VisibilityFromDLLStorageClassKinds";
}

inline static constexpr unsigned NumEnumerators(VisibilityFromDLLStorageClassKinds) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(VisibilityFromDLLStorageClassKinds);

} // namespace mx
