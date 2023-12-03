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
enum class ExprNullPointerConstantValueDependence : unsigned char {
  NEVER_VALUE_DEPENDENT,
  VALUE_DEPENDENT_IS_NULL,
  VALUE_DEPENDENT_IS_NOT_NULL,
};

inline static const char *EnumerationName(ExprNullPointerConstantValueDependence) {
  return "ExprNullPointerConstantValueDependence";
}

inline static constexpr unsigned NumEnumerators(ExprNullPointerConstantValueDependence) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(ExprNullPointerConstantValueDependence);

} // namespace mx
