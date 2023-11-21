// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class DeclFriendObjectKind : unsigned char {
  NONE,
  DECLARED,
  UNDECLARED,
};

inline static const char *EnumerationName(DeclFriendObjectKind) {
  return "DeclFriendObjectKind";
}

inline static constexpr unsigned NumEnumerators(DeclFriendObjectKind) {
  return 3;
}

const char *EnumeratorName(DeclFriendObjectKind);

} // namespace mx
