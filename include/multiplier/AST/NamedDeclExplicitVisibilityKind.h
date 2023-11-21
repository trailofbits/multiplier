// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class NamedDeclExplicitVisibilityKind : unsigned char {
  VISIBILITY_FOR_TYPE,
  VISIBILITY_FOR_VALUE,
};

inline static const char *EnumerationName(NamedDeclExplicitVisibilityKind) {
  return "NamedDeclExplicitVisibilityKind";
}

inline static constexpr unsigned NumEnumerators(NamedDeclExplicitVisibilityKind) {
  return 2;
}

const char *EnumeratorName(NamedDeclExplicitVisibilityKind);

} // namespace mx
