// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class TemplateSpecializationKind : unsigned char {
  UNDECLARED,
  IMPLICIT_INSTANTIATION,
  EXPLICIT_SPECIALIZATION,
  EXPLICIT_INSTANTIATION_DECLARATION,
  EXPLICIT_INSTANTIATION_DEFINITION,
};

inline static const char *EnumerationName(TemplateSpecializationKind) {
  return "TemplateSpecializationKind";
}

inline static constexpr unsigned NumEnumerators(TemplateSpecializationKind) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(TemplateSpecializationKind);

} // namespace mx
