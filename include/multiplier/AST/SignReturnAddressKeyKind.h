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
enum class SignReturnAddressKeyKind : unsigned char {
  A_KEY,
  B_KEY,
};

inline static const char *EnumerationName(SignReturnAddressKeyKind) {
  return "SignReturnAddressKeyKind";
}

inline static constexpr unsigned NumEnumerators(SignReturnAddressKeyKind) {
  return 2;
}

MX_EXPORT const char *EnumeratorName(SignReturnAddressKeyKind);

} // namespace mx
