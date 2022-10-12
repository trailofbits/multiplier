// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class TemplateArgumentDependence : unsigned char {
  UNEXPANDED_PACK,
  INSTANTIATION,
  DEPENDENT,
  ERROR,
  NONE,
  DEPENDENT_INSTANTIATION,
  ALL,
};

inline static const char *EnumerationName(TemplateArgumentDependence) {
  return "TemplateArgumentDependence";
}

inline static constexpr unsigned NumEnumerators(TemplateArgumentDependence) {
  return 7;
}

const char *EnumeratorName(TemplateArgumentDependence);

} // namespace mx
