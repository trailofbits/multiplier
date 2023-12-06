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
enum class PragmaSectionFlag : unsigned char {
  NONE,
  READ,
  WRITE,
  EXECUTE,
  IMPLICIT,
  ZERO_INITIALIZER,
  INVALID,
};

inline static const char *EnumerationName(PragmaSectionFlag) {
  return "PragmaSectionFlag";
}

inline static constexpr unsigned NumEnumerators(PragmaSectionFlag) {
  return 7;
}

MX_EXPORT const char *EnumeratorName(PragmaSectionFlag);

} // namespace mx
