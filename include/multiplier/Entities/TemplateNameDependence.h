// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class TemplateNameDependence : unsigned char {
  UNEXPANDED_PACK,
  INSTANTIATION,
  DEPENDENT,
  ERROR,
  NONE,
  DEPENDENT_INSTANTIATION,
  ALL,
};

inline static const char *EnumerationName(TemplateNameDependence) {
  return "TemplateNameDependence";
}

inline static constexpr unsigned NumEnumerators(TemplateNameDependence) {
  return 7;
}

const char *EnumeratorName(TemplateNameDependence);

} // namespace mx
