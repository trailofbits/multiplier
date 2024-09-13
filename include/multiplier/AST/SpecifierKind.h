// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class SpecifierKind : unsigned char {
  IDENTIFIER,
  NAMESPACE,
  NAMESPACE_ALIAS,
  TYPE_SPEC,
  TYPE_SPEC_WITH_TEMPLATE,
  GLOBAL,
  SUPER,
};

inline static const char *EnumerationName(SpecifierKind) {
  return "SpecifierKind";
}

inline static constexpr unsigned NumEnumerators(SpecifierKind) {
  return 7;
}

MX_EXPORT const char *EnumeratorName(SpecifierKind);

} // namespace mx
