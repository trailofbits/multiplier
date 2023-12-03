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
enum class ExprDependence : unsigned char {
  UNEXPANDED_PACK,
  INSTANTIATION,
  TYPE,
  VALUE,
  ERROR,
  NONE,
  ALL,
  TYPE_VALUE,
  TYPE_INSTANTIATION,
  VALUE_INSTANTIATION,
  TYPE_VALUE_INSTANTIATION,
  ERROR_DEPENDENT,
};

inline static const char *EnumerationName(ExprDependence) {
  return "ExprDependence";
}

inline static constexpr unsigned NumEnumerators(ExprDependence) {
  return 12;
}

MX_EXPORT const char *EnumeratorName(ExprDependence);

} // namespace mx
