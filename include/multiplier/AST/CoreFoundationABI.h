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
enum class CoreFoundationABI : unsigned char {
  UNSPECIFIED,
  STANDALONE,
  OBJECTIVE_C,
  SWIFT,
  SWIFT50,
  SWIFT42,
  SWIFT41,
};

inline static const char *EnumerationName(CoreFoundationABI) {
  return "CoreFoundationABI";
}

inline static constexpr unsigned NumEnumerators(CoreFoundationABI) {
  return 7;
}

MX_EXPORT const char *EnumeratorName(CoreFoundationABI);

} // namespace mx
