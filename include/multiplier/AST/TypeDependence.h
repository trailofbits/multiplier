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
enum class TypeDependence : unsigned char {
  UNEXPANDED_PACK,
  INSTANTIATION,
  DEPENDENT,
  VARIABLY_MODIFIED,
  ERROR,
  NONE,
  ALL,
  DEPENDENT_INSTANTIATION,
};

inline static const char *EnumerationName(TypeDependence) {
  return "TypeDependence";
}

inline static constexpr unsigned NumEnumerators(TypeDependence) {
  return 8;
}

MX_EXPORT const char *EnumeratorName(TypeDependence);

} // namespace mx
