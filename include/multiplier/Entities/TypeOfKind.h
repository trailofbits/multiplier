// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class TypeOfKind : unsigned char {
  QUALIFIED,
  UNQUALIFIED,
};

inline static const char *EnumerationName(TypeOfKind) {
  return "TypeOfKind";
}

inline static constexpr unsigned NumEnumerators(TypeOfKind) {
  return 2;
}

const char *EnumeratorName(TypeOfKind);

} // namespace mx
