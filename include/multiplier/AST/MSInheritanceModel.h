// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class MSInheritanceModel : unsigned char {
  SINGLE,
  MULTIPLE,
  VIRTUAL,
  UNSPECIFIED,
};

inline static const char *EnumerationName(MSInheritanceModel) {
  return "MSInheritanceModel";
}

inline static constexpr unsigned NumEnumerators(MSInheritanceModel) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(MSInheritanceModel);

} // namespace mx
