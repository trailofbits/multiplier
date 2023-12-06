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
enum class ParameterABI : unsigned char {
  ORDINARY,
  SWIFT_INDIRECT_RESULT,
  SWIFT_ERROR_RESULT,
  SWIFT_CONTEXT,
  SWIFT_ASYNC_CONTEXT,
};

inline static const char *EnumerationName(ParameterABI) {
  return "ParameterABI";
}

inline static constexpr unsigned NumEnumerators(ParameterABI) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(ParameterABI);

} // namespace mx
