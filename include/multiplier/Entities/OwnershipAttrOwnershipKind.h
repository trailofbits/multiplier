// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class OwnershipAttrOwnershipKind : unsigned char {
  HOLDS,
  RETURNS,
  TAKES,
};

inline static const char *EnumerationName(OwnershipAttrOwnershipKind) {
  return "OwnershipAttrOwnershipKind";
}

inline static constexpr unsigned NumEnumerators(OwnershipAttrOwnershipKind) {
  return 3;
}

const char *EnumeratorName(OwnershipAttrOwnershipKind);

} // namespace mx
