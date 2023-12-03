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
enum class ExceptionSpecificationType : unsigned char {
  NONE,
  DYNAMIC_NONE,
  DYNAMIC,
  MS_ANY,
  NO_THROW,
  BASIC_NOEXCEPT,
  DEPENDENT_NOEXCEPT,
  NOEXCEPT_FALSE,
  NOEXCEPT_TRUE,
  UNEVALUATED,
  UNINSTANTIATED,
  UNPARSED,
};

inline static const char *EnumerationName(ExceptionSpecificationType) {
  return "ExceptionSpecificationType";
}

inline static constexpr unsigned NumEnumerators(ExceptionSpecificationType) {
  return 12;
}

MX_EXPORT const char *EnumeratorName(ExceptionSpecificationType);

} // namespace mx
