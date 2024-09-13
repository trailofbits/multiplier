// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class NestedNameSpecifierDependence : unsigned char {
  UNEXPANDED_PACK,
  INSTANTIATION,
  DEPENDENT,
  ERROR,
  NONE,
  DEPENDENT_INSTANTIATION,
  ALL,
};

inline static const char *EnumerationName(NestedNameSpecifierDependence) {
  return "NestedNameSpecifierDependence";
}

inline static constexpr unsigned NumEnumerators(NestedNameSpecifierDependence) {
  return 7;
}

MX_EXPORT const char *EnumeratorName(NestedNameSpecifierDependence);

} // namespace mx
